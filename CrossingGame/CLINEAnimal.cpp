#include "CLINEAnimal.h"

CLINEAnimal::CLINEAnimal(int speed, bool direction, bool light, int currentLine) {
	this->_speed = speed;
	this->_direction = direction;
	this->_trafficLight = light;
	this->_currentLine = currentLine;
}

bool CLINEAnimal::printAnimal(cPoint pos, char** shape, int width, int height) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT)
		return false;
	if (Y > RIGHT)
		return false;
	for (int i = 0; i < height; ++i) {
		for (int j = max(4, Y); j <= min(31, Y + width - 1); ++j) {
			Controller::GotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return true;
}

bool CLINEAnimal::pushAnimal(CANIMAL* animal) {
	/*if (!_direction)
		vehicle->updatePosition(0, RIGHT - vehicle->getY());*/
		/*if (animal->getY() > RIGHT || animal->getY() <= 3 || (_animalBox.size() && abs(_animalBox.back()->getY() - animal->getY()) <= 8))
			return false;*/
	_animalBox.push_back(animal);
	//printAnimal(animal->getPos(), animal->returnShape(), animal->getWidth(), animal->getHeight());
	return true;
}

void CLINEAnimal::deleteAnimal(cPoint pos, int width, int height) {
	int X = pos.getX();
	int Y = pos.getY();
	//if (Y == LEFT)
	//	return;
	//if (Y > RIGHT)
	//	return;
	for (int i = 0; i < height; ++i) {
		for (int j = max(4, Y); j <= min(31, Y + width - 1); ++j) {
			Controller::GotoXY(Y + j, X + i);
			cout << ' ';
		}
	}
}

//int cLine::Reload(int t) {
//	
//}

int CLINEAnimal::getSpeed() {
	return _speed;
}

vector<CANIMAL*> CLINEAnimal::getAnimal() {
	return _animalBox;
}

bool CLINEAnimal::getDirection() {
	return _direction;
}
void CLINEAnimal::setTrafficLightState(bool curState) {
	_trafficLight = curState;
}
bool CLINEAnimal::getTrafficLightState() {
	return _trafficLight;
}
void CLINEAnimal::DrawAnimalLine() {
	for (int i = 0; i < 3; i++) {
		CBIRD* bird = new CBIRD;
		bird->newPosition(4, i * 7 + 5);
		pushAnimal(bird);
	}
	while (_trafficLight) {
		for (int i = 0; i < getAnimal().size(); i++) {
			printAnimal(getAnimal()[i]->getPos(),
				getAnimal()[i]->returnShape(),
				getAnimal()[i]->getWidth(),
				getAnimal()[i]->getHeight());
		}
		Sleep(100);
		for (int i = 0; i < getAnimal().size(); i++) {
			deleteAnimal(getAnimal()[i]->getPos(),
				getAnimal()[i]->getWidth(),
				getAnimal()[i]->getHeight());
		}
		for (int i = 0; i < getAnimal().size(); i++) {
			getAnimal()[i]->updatePosition(0, 1);
		}
	}
}