#include "cPoint.h"

void cPoint::setX(int x) {
	this->x = x;
}

void cPoint::setY(int y) {
	this->y = y;
}

void cPoint::setXY(int dx, int dy) {
	this->x = dx;
	this->y = dy;
}

int cPoint::getX() {
	return x;
}

int cPoint::getY() {
	return y;
}

cPoint::cPoint() {
	this->x = 0;
	this->y = 0;
}

cPoint::cPoint(int x, int y) {
	this->x = x;
	this->y = y;
}

cPoint::~cPoint() {};