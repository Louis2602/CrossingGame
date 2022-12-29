#pragma once

#ifndef CBIRD_h
#define CBIRD_h

#include "COBJECT.h"
#define BIRD_HEIGHT 3
#define BIRD_WIDTH 5

class CBIRD : public COBJECT {
private:
	char** shape;

public:
	CBIRD(cPoint);
	CBIRD();
	~CBIRD();
	char** returnShape();
	int getHeight();
	int getWidth();
	int inGameWidth();
};

#endif 