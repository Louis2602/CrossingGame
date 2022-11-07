#pragma once

#ifndef cLine_h
#define cLine_h

#include "cVehicle.h"
#include "Controller.h"
#include <vector>

using namespace std;

#define RIGHT 65
#define LEFT 2

class cLine
{
	vector<cVehicle*> _vehicleBox;
	int _speed;
	bool _direction; 
	bool _trafficLight;
	int _currentLine;
public:
	cLine() = default;
	~cLine() = default;
	cLine(int speed, bool direction, bool light, int currentLine);
	bool printVehicle(cPoint pos, char** shape, int width, int height);
	bool pushVehicle(cVehicle* vehicle);
	void deleteVehicle(cPoint pos, int w, int h);
	int getSpeed();
	vector<cVehicle*> getVehicle();
	bool getDirection();
};

#endif // !cLine_h