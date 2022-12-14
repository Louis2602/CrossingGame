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
	int space;
public:
	cLine() = default;
	cLine(int, bool, string, int, int); //current line - direction - type of Obj - spacing - number of obj in 1 line
	~cLine() = default;
	void setSpeed(int _x);
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
	int getSpace() { return this->space; }
	void check(COBJECT*&);
};