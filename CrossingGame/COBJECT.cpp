#include "COBJECT.h";

COBJECT::COBJECT() {}

COBJECT::COBJECT(cPoint point) :pos(point) {}

cPoint COBJECT::getPos() {
	return this->pos;
}

void COBJECT::newPosition(int dx, int dy) {
	this->pos.setX(dx);
	this->pos.setY(dy);
}

int COBJECT::getHeight() {
	return 3;
}

void COBJECT::updatePosition(int dx, int dy) {
	pos.setXY(pos.getX() + dx, pos.getY() + dy);
}