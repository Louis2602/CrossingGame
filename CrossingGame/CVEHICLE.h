#ifndef cVehicle_h
#define cVehicle_h


#include "CPOINT.h"
#include <Windows.h>
#include <iostream>
#include <mmsystem.h>


class cVehicle {
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
	

	cVehicle();
	cVehicle(cPoint); 
	virtual ~cVehicle() = default;
	virtual char** returnShape() = 0;

	void newPosition(int dx, int dy);

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;


	void updatePosition(int dx, int dy);
};

#endif // !cVehicle_h