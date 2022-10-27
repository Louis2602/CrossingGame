#ifndef CVehicle
#define CVehicle

#include "CPOINT.h"
#include <Windows.h>
#include <iostream>
#include <mmsystem.h>


class CVEHICLE {
private:
	cPoint pos;
public:
	//virtual void Move(int, int);
	cPoint getPos();

	int getX() {
		return pos.getX();
	}
	int getY() {
		return pos.getY();
	}
	

	CVEHICLE();
	CVEHICLE(cPoint); 
	virtual ~CVEHICLE() = default;
	virtual char** returnShape() = 0;

	void newPosition(int dx, int dy);

	virtual int getWidth() = 0;

	int getHeight();
};

#endif 