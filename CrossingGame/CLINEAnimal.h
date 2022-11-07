#pragma once
#include "CANIMAL.h"
#include "Controller.h"
#include <vector>
using namespace std;
#define RIGHT 65
#define LEFT 2

class CLINEAnimal
{
	vector<CANIMAL*> _animalBox;
	int _speed;
	bool _direction;
	bool _trafficLight;
	int _currentLine;
public:
	CLINEAnimal() = default;
	~CLINEAnimal() = default;
	CLINEAnimal(int speed, bool direction, bool light, int currentLine);
	bool printAnimal(cPoint pos, char** shape, int width, int height);
	bool pushAnimal(CANIMAL* animal);
	void deleteAnimal(cPoint pos, int w, int h);
	//int Transfer(int t);
	int getSpeed();
	vector<CANIMAL*> getAnimal();
	bool getDirection();
};