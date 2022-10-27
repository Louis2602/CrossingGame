#pragma once

#include "CVEHICLE.h"

#define TRUCK_HEIGHT 3
#define TRUCK_WIDTH 9

class CTRUCK : public CVEHICLE
{
	char** shape; //a[3][8]
public:
	CTRUCK(cPoint);
	CTRUCK();
	~CTRUCK();
	char** returnShape();
	int getWidth();
};