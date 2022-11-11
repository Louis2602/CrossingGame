#pragma once
#include "CANIMAL.h"
#define BIRD_HEIGHT 3
#define BIRD_WIDTH 5

class CBIRD : public CANIMAL {
private:
	char** shape;

public:
	CBIRD(cPoint);
	CBIRD();
	~CBIRD();
	char** returnShape();
	int getHeight();
	int getWidth();
};