#include "CVEHICLE.h";

CVEHICLE::CVEHICLE() {}

CVEHICLE::CVEHICLE(cPoint point) :pos(point) {}

cPoint CVEHICLE::getPos() {
	return this->pos;
}

void CVEHICLE::newPosition(int dx, int dy) {
	this->pos.setX(dx);
	this->pos.setY(dy);
}

int CVEHICLE::getHeight() {
	return 3;
}

void CVEHICLE::updatePosition(int dx, int dy) {
	pos.setXY(pos.getX() + dx, pos.getY() + dy);
}