#include "cCar.h"


cCar::cCar(cPoint pos): cVehicle(pos) {
	//car shape
	//     ___
	//   _/ |_\_
	//  '-0---0-'

	shape = new char* [CAR_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[CAR_WIDTH];
	}

	//Row1
	for (int i = 0; i < CAR_WIDTH; i++) {
		if (i < 3 || i >5)
			shape[0][i] = ' ';
		else
			shape[0][i] = '_';
	}

	//Row2
	for (int i = 0; i < CAR_WIDTH; i++) {
		if (i == 0 || i == 3 || i == 8) {
			shape[1][i] = ' ';
		}
		else if (i == 1 || i == 5 || i == 7) {
			shape[1][i] = '_';
		}
		else if (i == 2) {
			shape[1][i] = '/';
		}
		else if (i == 6) {
			shape[1][i] = '\\';
		}
		else if (i == 4) {
			shape[1][i] = '|';
		}
	}

	//Row3
	for (int i = 0; i < CAR_WIDTH; i++) {
		switch (i)
		{
		case 0: case 8:
		{
			shape[2][i] = '\'';
			break;
		}
		case 1: case 3: case 4: case 5: case 7:
		{
			shape[2][i] = '-';
			break;
		}
		case 2: case 6:
		{
			shape[2][i] = '0';
			break;
		}
		default:
			break;
		}
	}
}

cCar::cCar(){
	//car shape
	//     ___
	//   _/ |_\_
	//  '-0---0-'

	shape = new char* [CAR_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[CAR_WIDTH];
	}

	//Row1
	for (int i = 0; i < CAR_WIDTH; i++) {
		if (i < 3 || i >5)
			shape[0][i] = ' ';
		else
			shape[0][i] = '_';
	}

	//Row2
	for (int i = 0; i < CAR_WIDTH; i++) {
		if (i == 0 || i == 3 || i == 8) {
			shape[1][i] = ' ';
		}
		else if (i == 1 || i == 5 || i == 7) {
			shape[1][i] = '_';
		}
		else if (i == 2) {
			shape[1][i] = '/';
		}
		else if (i == 6) {
			shape[1][i] = '\\';
		}
		else if (i == 4) {
			shape[1][i] = '|';
		}
	}

	//Row3
	for (int i = 0; i < CAR_WIDTH; i++) {
		switch (i)
		{
		case 0: case 8:
		{
			shape[2][i] = '\'';
			break;
		}
		case 1: case 3: case 4: case 5: case 7:
		{
			shape[2][i] = '-';
			break;
		}
		case 2: case 6:
		{
			shape[2][i] = '0';
			break;
		}
		default:
			break;
		}
	}
}

cCar::~cCar() {
	for (int i = 0; i < CAR_HEIGHT; i++)
		delete[] shape[i];
	delete[] shape;
	delete[] shape;
}

char** cCar::returnShape() {
	return shape;
}

int cCar::getWidth() {
	return CAR_WIDTH;
}

int cCar::getHeight() {
	return CAR_HEIGHT;
}

