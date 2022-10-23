#include "CANIMAL.h"

CANIMAL::CANIMAL() : outmap(false) {}

CANIMAL::CANIMAL(const CPOSITION& start) : pos(start), outmap(false) {}

int CANIMAL::getX() {
	return pos.getX();
}

int CANIMAL::getY() {
	return pos.getY();
}

CPOSITION CANIMAL::getPos() {
	return pos;
}

bool CANIMAL::isOutMap() {
	return outmap;
}

void CANIMAL::setOutMap() {
	outmap = true;
}

void CANIMAL::updatePos(const int x, const int y) {
	pos.setPos(pos.getX() + x, pos.getY() + y);
}