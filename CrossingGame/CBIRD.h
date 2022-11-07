#pragma once
#include "CANIMAL.h"
#define BIRD_HEIGHT 4
#define BIRD_WIDTH 6

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