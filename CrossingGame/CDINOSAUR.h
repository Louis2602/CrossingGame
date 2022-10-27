#pragma once
#include "CANIMAL.h"
#include "CPOSTION.h"

class CDINOSAUR : public CANIMAL {
private:
	char** dinoShape;
public:
	CDINOSAUR(CPOSITION pos);
	~CDINOSAUR();
	char** shape();
	int getWidth();
	int getHeight();
};