#pragma once
#include "Header.h"

class CLIGHT {
private:
	char BottomDot = 220;
	char TopDot = 223;
	bool state; //red is false, green is true.
public:
	CLIGHT();
	~CLIGHT() {};
	void update_light();
	bool getState();
	void setState(bool);
};