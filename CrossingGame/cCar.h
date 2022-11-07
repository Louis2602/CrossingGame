#pragma once

#ifndef cCar_h
#define cCar_h

#include "CVEHICLE.h"

#define CAR_HEIGHT 3
#define CAR_WIDTH 9

class cCar : public CVEHICLE 
{
	char** shape; //a[3][8]
public:
	cCar(cPoint);
	cCar();
	~cCar();
	char** returnShape();
	int getWidth();
	int getHeight();
};

#endif // !cCar_h