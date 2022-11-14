#pragma once

#include <iostream>
#include <vector>

#include "cCar.h"
#include "cTruck.h"
#include "CVEHICLE.h"
#include "cPoint.h"
#include "Controller.h"

#define LINE_1 8
#define LINE_2 12
#define LINE_3 16

using namespace std;

class cLine {
	vector<CVEHICLE*> lineData;
	bool direction; //0: to the left, 1: to the right
	bool greenLight = true;
	int speed;
	int currentRow;
	int objectInLine;
public:
	cLine();
	cLine(int speed, bool direction, bool greenLight, int currentRow);
	~cLine() = default;
	void pushVehicle(CVEHICLE* vehicle);
	CVEHICLE* generateVehicle(cPoint pos);
	bool doHaveSlot();
	void popVehicle();
	void printVehicle(cPoint pos, char** shape, int height, int width);
	void deleteVehicle(cPoint pos, char** shape, int height, int width);
	void nextMove();
	void changeLight(bool light);
	bool getLight();
};