#pragma once
#include "Header.h"

class CLIGHT {
private:
	char BottomDot = 220;
	char TopDot = 223;
	bool state; //red is false, green is true.
	bool isPlay = true;
public:
	CLIGHT();
	~CLIGHT() {};
	void update_light();
	bool getisPlay();
	void setisPlay(bool);
	bool getState();
	void setState(bool);
	static void mainLight();
};