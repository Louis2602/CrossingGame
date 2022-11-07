#pragma once
#ifndef CANIMAL_h
#define CANIMAL_h

#include "cPoint.h"
#include "Controller.h"
#include <Windows.h>
#include <iostream>
#include <mmsystem.h>

class CANIMAL {
private:
	cPoint pos;
public:
	cPoint getPos();
	int getX() {
		return pos.getX();
	}
	int getY() {
		return pos.getY();
	}
	CANIMAL();
	CANIMAL(cPoint);
	virtual ~CANIMAL() = default;
	virtual char** returnShape() = 0;
	void newPosition(int _x, int _y);
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	void updatePosition(int _x, int _y);
};

#endif // !CANIMAL_h