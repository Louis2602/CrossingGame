#include "cVehicle.h";

cVehicle::cVehicle() {}

cVehicle::cVehicle(cPoint point) :pos(point) {}

cPoint cVehicle::getPos() {
	return this->pos;
}

void cVehicle::newPosition(int dx, int dy){
	this->pos.setX(dx);
	this->pos.setY(dy);
}

int cVehicle::getHeight() {
	return 3;
}

void cVehicle::updatePosition(int dx, int dy) {
	pos.setXY(pos.getX() + dx, pos.getY() + dy);
}