#pragma once

#include "cVehicle.h"

#define TRUCK_HEIGHT 3
#define TRUCK_WIDTH 9

class cTruck : public cVehicle
{
	char** shape; //a[3][8]
public:
	cTruck(cPoint);
	cTruck();
	~cTruck();
	char** returnShape();
	int getWidth();
	int getHeight();
};