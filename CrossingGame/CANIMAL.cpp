#include "CANIMAL.h"

CANIMAL::CANIMAL() {}

CANIMAL::CANIMAL(cPoint point) : pos(point) {}

cPoint CANIMAL::getPos() {
	return this->pos;
}

void CANIMAL::newPosition(int _x, int _y) {
	this->pos.setX(_x);
	this->pos.setY(_y);
}

int CANIMAL::getHeight() {
	return 3;
}

void CANIMAL::updatePosition(int _x, int _y) {
	if ((pos.getY() + _y) > 50) {
		pos.setXY(10, 0);
	}
	else
		pos.setXY(pos.getX() + _x, pos.getY() + _y);
}