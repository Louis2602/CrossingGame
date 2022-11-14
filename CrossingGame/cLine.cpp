#include "cLine.h"

cLine::cLine() {
	objectInLine = 0;
	speed = 10;
}

void cLine::changeLight(bool light) {
	this->greenLight = light;
}

bool cLine::getLight() {
	return this->greenLight;
}

cLine::cLine(int speed, bool direction, bool greenLight, int currentRow) {
	this->speed = speed;
	this->direction = direction;
	this->greenLight = greenLight;
	this->currentRow = currentRow;
	this->objectInLine = 0;
}

void cLine::pushVehicle(COBJECT* Object) {
	lineData.push_back(Object);
	printVehicle(Object->getPos(), Object->returnShape(), Object->getHeight(), Object->getWidth());
	objectInLine += 1;
}

COBJECT* cLine::generateVehicle(cPoint pos) {
	int randomType = rand() % 2;
	COBJECT* Object = NULL;
	switch (randomType) {
	case 0:
		Object = new cCar(pos);
	default:
		Object = new cTruck(pos);
	}
	return Object;
}

bool cLine::doHaveSlot() {
	if (this->objectInLine <= 4) {
		return true;
	}
	return false;
}

void cLine::popVehicle() {
	if (objectInLine > 0) {
		lineData.erase(lineData.begin());
		this->objectInLine -= 1;
	}
}

void cLine::printVehicle(cPoint pos, char** shape, int height, int width) {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < height; i++) {
		for (int j = max(1, y); j <= min(58, y + width - 1); ++j) {
			if ((x + j > 5) && (x + j < 67)) {
				mtx.lock();
				Controller::GotoXY(x + j, y + i);
				cout << shape[i][j - max(1, y)];
				//cout << i << " " << j;
				mtx.unlock();
			}

		}
	}
	if (x > 80) {
		popVehicle();
	}
}

void cLine::deleteVehicle(cPoint pos, char** shape, int height, int width) {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < height; i++) {
		for (int j = max(1, y); j <= min(58, y + width - 1); ++j) {
			if ((x + j > 5) && (x + j < 67)) {
				mtx.lock();
				Controller::GotoXY(x + j, y + i);
				cout << ' ';
				mtx.unlock();
				//cout << i << " " << j;
			}

		}
	}
	if (x > 80) {
		popVehicle();
	}
}


void cLine::nextMove() {
	for (int i{}; i < lineData.size(); i++) {
		deleteVehicle(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getHeight(), lineData[i]->getWidth());
		lineData[i]->updatePosition(this->speed, 0);
		printVehicle(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getHeight(), lineData[i]->getWidth());

	}
}

//void cLine::stillContainVehicle