#include "cLine.h"

cLine::cLine() {
	objectInLine = 0;
	speed = 2;
}

/////////////////////
cLine::cLine(int curLine, bool direction, string type, int spacing) {
	this->currentRow = curLine;
	this->direction = direction;
	cPoint pos;
	COBJECT* obj;
	for (int i = 0; i < 4; i++) {
		pos.setX(i * spacing);
		pos.setY(6 + 4 * curLine);
		if (type == "bird") {
			obj = new CBIRD(pos);
		}
		if (type == "car") {
			obj = new cCar(pos);
		}
		if (type == "dino") {
			obj = new CDINO(pos);
		}
		if (type == "truck") {
			obj = new cTruck(pos);
		}
		this->lineData.push_back(obj);
	}
}
/////////////////////

void cLine::changeLight(bool light) {
	this->greenLight = light;
}

bool cLine::getLight() {
	return this->greenLight;
}

//cLine::cLine(int speed, bool direction, bool greenLight, int currentRow) {
//	this->speed = speed;
//	this->direction = direction;
//	this->greenLight = greenLight;
//	this->currentRow = currentRow;
//	this->objectInLine = 0;
//}
void cLine::setSpeed(int _x) {
	this->speed = _x;
}
//void cLine::pushObject(COBJECT* Object) {
//	lineData.push_back(Object);
//	printObject(Object->getPos(), Object->returnShape(), Object->getHeight(), Object->getWidth());
//	objectInLine += 1;
//}

//COBJECT* cLine::generateObject(cPoint pos) {
//	int randomType = rand() % 2;
//	COBJECT* Object = NULL;
//	switch (randomType) {
//	case 0:
//		Object = new cCar(pos);
//	default:
//		Object = new cTruck(pos);
//	}
//	return Object;
//}

//bool cLine::doHaveSlot() {
//	if (this->objectInLine <= 4) {
//		return true;
//	}
//	return false;
//}
//
//void cLine::popObject() {
//	if (objectInLine > 0) {
//		lineData.erase(lineData.begin());
//		this->objectInLine -= 1;
//	}
//
//}

void cLine::printObject(cPoint pos, char** shape, int height, int width) {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < height; i++) {
		for (int j = max(1, y); j <= min(58, y + width - 1); ++j) {
			if ((x + j > 5) && (x + j < 67)) {
				mtx.lock();
				Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
				Controller::GotoXY(x + j, y + i);
				cout << shape[i][j - max(1, y)];
				//cout << i << " " << j;
				mtx.unlock();
			}
		}
	}
}

void cLine::deleteObject(cPoint pos, char** shape, int height, int width) {
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
}


void cLine::check(COBJECT* &obj) {
	if (obj->getX() < -20 && this->direction == 1) {
		obj->updatePosition(80, 0);
		return;
	}
	if (obj->getX() > 70 && this->direction == 0) {
		obj->updatePosition(-90, 0);
		return;
	}
}

void cLine::nextMove(CPEOPLE p, bool& IS_RUNNING) {
	for (int i{}; i < lineData.size(); i++) {
		if (p.isImpact(lineData[i]))
		{
			IS_RUNNING = false;
			return;
		}

		deleteObject(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getHeight(), lineData[i]->getWidth());
		if (this->direction)
			lineData[i]->updatePosition(-(this->speed), 0); // phải qua trái
		else
			lineData[i]->updatePosition(this->speed, 0); // trái qua phải
		printObject(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getHeight(), lineData[i]->getWidth());

		if (p.isImpact(lineData[i]))
		{
			IS_RUNNING = false;
			return;
		}

		check(lineData[i]);
	}
}

vector<COBJECT*> cLine::getData() {
	return this->lineData;
}

//void cLine::stillContainObject