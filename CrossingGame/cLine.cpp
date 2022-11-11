#include "cLine.h"

cLine::cLine() {
	objectInLine = 0;
}

cLine::cLine(int speed, bool direction, bool redLight, int currentRow) {
	this->speed = speed;
	this->direction = direction;
	this->redLight = redLight;
	this->currentRow = currentRow;
	this->objectInLine = 0;
}

void cLine::pushVehicle(CVEHICLE* vehicle) {
	lineData.push_back(vehicle);
	printVehicle(vehicle->getPos(), vehicle->returnShape(), vehicle->getHeight(), vehicle->getWidth());
	objectInLine += 1;
}

CVEHICLE* cLine::generateVehicle(cPoint pos) {
	int randomType = rand() % 2;
	CVEHICLE* vehicle = NULL;
	switch (randomType) {
	case 0:
		vehicle = new cCar(pos);
	default:
		vehicle = new cTruck(pos);
	}
	return vehicle;
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
				Controller::GotoXY(x + j, y + i);
				cout << shape[i][j - max(1, y)];
				//cout << i << " " << j;
				
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
				Controller::GotoXY(x + j, y + i);
				cout << ' ';
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
		lineData[i]->updatePosition(1, 0);
		printVehicle(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getHeight(), lineData[i]->getWidth());

	}
}

//void cLine::stillContainVehicle