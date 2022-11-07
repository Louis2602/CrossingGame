#pragma once


#include "CVEHICLE.h"

#define TRUCK_HEIGHT 3
#define TRUCK_WIDTH 9

class cTruck : public CVEHICLE
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