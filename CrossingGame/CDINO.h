#pragma once

#ifndef CDINO_h
#define CDINO_h

#include "COBJECT.h"
#define DINO_HEIGHT 3
#define DINO_WIDTH 6

class CDINO : public COBJECT {
private:
	char** shape;

public:
	CDINO(cPoint);
	CDINO();
	~CDINO();
	char** returnShape();
	int getHeight();
	int getWidth();
	int inGameWidth();
};

#endif 