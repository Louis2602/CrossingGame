#pragma once

#include <iostream>
#include <vector>

#include "cCar.h"
#include "cTruck.h"
#include "COBJECT.h"
#include "cPoint.h"
#include "Controller.h"
#include "CBIRD.h"
#include "CDINO.h"
#include "CPEOPLE.h"

#define LINE_1 8
#define LINE_2 12
#define LINE_3 16

using namespace std;

class cLine {
	vector<COBJECT*> lineData;
	bool direction; //0: to the left, 1: to the right
	bool greenLight = true;
	int speed;
	int currentRow;
	int objectInLine;
public:
	cLine();
	cLine(int speed, bool direction, bool greenLight, int currentRow);
	~cLine() = default;
	void pushObject(COBJECT* Object);
	COBJECT* generateObject(cPoint pos);
	void setSpeed(int _x);
	bool doHaveSlot();
	void popObject();
	void printObject(cPoint pos, char** shape, int height, int width);
	void deleteObject(cPoint pos, char** shape, int height, int width);
	void nextMove(CPEOPLE, bool&);
	void changeLight(bool light);
	bool getLight();
	vector<COBJECT*> getData();
	void setDirection(bool _x) {
		this->direction = _x;
	}
	bool getDirection() {
		return this->direction;
	}
};