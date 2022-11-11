#pragma once

#include <iostream>
#include <vector>

#include "cCar.h"
#include "cTruck.h"
#include "CVEHICLE.h"
#include "cPoint.h"
#include "Controller.h"

using namespace std;

class cLine {
	vector<CVEHICLE*> lineData;
	bool direction; //0: to the left, 1: to the right
	bool redLight = false;
	int speed;
	int currentRow;
	int objectInLine;
public:
	cLine();
	cLine(int speed, bool direction, bool redLight, int currentRow);
	~cLine() = default;
	void pushVehicle(CVEHICLE* vehicle);
	CVEHICLE* generateVehicle(cPoint pos);
	bool doHaveSlot();
	void popVehicle();
	void printVehicle(cPoint pos, char** shape, int height, int width);
	void deleteVehicle(cPoint pos, char** shape, int height, int width);
	void nextMove();
};