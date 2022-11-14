#pragma once


#include "COBJECT.h"

#define TRUCK_HEIGHT 3
#define TRUCK_WIDTH 9

class cTruck : public COBJECT
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