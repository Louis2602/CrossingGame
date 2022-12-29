#pragma once
#include "Controller.h"

class CLIGHT {
private:
	const char BottomDot = 220;
	const char TopDot = 223;
	bool state; //red is false, green is true.
	bool isPlay;
	int posX, posY;
	int timer;
public:
	CLIGHT();
	~CLIGHT() {};
	void spawn_light(int, int);
	bool getisPlay();
	void setisPlay(bool);
	bool getState();
	void setState(bool);
	void setTimer(int);
	void setPos(int, int);
};