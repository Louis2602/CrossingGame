#pragma once

#include "CVEHICLE.h"

#define CAR_HEIGHT 3
#define CAR_WIDTH 9

class CCAR : public CVEHICLE 
{
	char** shape; //a[3][8]
public:
	CCAR(cPoint);
	CCAR();
	~CCAR();
	char** returnShape();
	int getWidth();
};