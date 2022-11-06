#include "cLine.h"

cLine::cLine(int speed, bool direction, bool light, int currentLine) {
	this->_speed = speed;
	this->_direction = direction;
	this->_trafficLight = light;
	this->_currentLine = currentLine;
}

bool cLine::printVehicle(cPoint pos, char** shape, int width, int height) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT)
		return false;
	if (Y > RIGHT)
		return false;
	for (int i = 0; i < height; ++i) {
		for (int j = max(1, Y); j <= min(RIGHT, Y + width - 1); ++j) {
			Controller::GotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return true;
}

bool cLine::pushVehicle(cVehicle* vehicle) {
	/*if (!_direction)
		vehicle->updatePosition(0, RIGHT - vehicle->getY());*/
	if (vehicle->getY() > RIGHT || vehicle->getY() <= 3 || (_vehicleBox.size() && abs(_vehicleBox.back()->getY() - vehicle->getY()) <= 8))
		return false;
	_vehicleBox.push_back(vehicle);
	printVehicle(vehicle->getPos(), vehicle->returnShape(), vehicle->getWidth(), vehicle->getHeight());
	return true;
}

void cLine::deleteVehicle(cPoint pos, int width, int height) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT)
		return;
	if (Y > RIGHT)
		return;
	for (int i = 0; i < height; ++i) {
		for (int j = max(1, Y); j <= min(RIGHT, Y + width - 1); ++j) {
			Controller::GotoXY(Y + j, X + i);
			cout << ' ';
		}
	}
}

//int cLine::Reload(int t) {
//	
//}

int cLine::getSpeed() {
	return _speed;
}

vector<cVehicle*> cLine::getVehicle() {
	return _vehicleBox;
}

bool cLine::getDirection() {
	return _direction;
}
