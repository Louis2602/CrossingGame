#pragma once
#include "CPOSTION.h"
#include "Controller.h"

class CANIMAL {
private:
	CPOSITION pos;
	bool outmap;
public:
	int getX();
	int getY();
	CANIMAL();
	CANIMAL(const CPOSITION&);
	~CANIMAL() {};
	CPOSITION getPos();
	bool isOutMap();
	virtual int getH() = 0;
	virtual int getW() = 0;
	void updatePos(const int x, const int y);
	void setOutMap();
	virtual char** kind() = 0;
};