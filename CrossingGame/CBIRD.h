#pragma once
#include "CANIMAL.h"
#include "CPOSTION.h"

class CBIRD : public CANIMAL {
private:
	char** birdShape;

public:
	CBIRD(CPOSITION pos);
	~CBIRD();
	char** shape();
	int getWidth();
	int getHeight();
};