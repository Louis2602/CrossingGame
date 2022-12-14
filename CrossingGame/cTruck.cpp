#include "cTruck.h"


cTruck::cTruck(cPoint pos) : COBJECT(pos) {
	//TRUCK shape
	// __.----.
	//|__|____|
	//'-0---0-'

	shape = new char* [TRUCK_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[TRUCK_WIDTH];
	}

	//Row1
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0) {
			shape[0][i] = ' ';
		}
		else if (i == 1 || i == 2) {
			shape[0][i] = '_';
		}
		else if (i == 3 || i == 8) {
			shape[0][i] = '.';
		}
		else {
			shape[0][i] = '-';
		}
	}

	//Row2
	for (int i = 0; i < TRUCK_WIDTH; i++) {

		if (i == 0 || i == 3 || i == 8)
			shape[1][i] = '|';
		else
			shape[1][i] = '_';

	}

	//Row3
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0 || i == 8)
			shape[2][i] = '\'';
		else if (i == 2 || i == 6)
			shape[2][i] = '0';
		else
			shape[2][i] = '-';
	}
}

cTruck::cTruck() {
	//TRUCK shape
	// __.----.
	//|__|____|
	//'-0---0-'

	shape = new char* [TRUCK_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[TRUCK_WIDTH];
	}

	//Row1
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0) {
			shape[0][i] = ' ';
		}
		else if (i == 1 || i == 2) {
			shape[0][i] = '_';
		}
		else if (i == 3 || i == 8) {
			shape[0][i] = '.';
		}
		else {
			shape[0][i] = '-';
		}
	}

	//Row2
	for (int i = 0; i < TRUCK_WIDTH; i++) {

		if (i == 0 || i == 3 || i == 8)
			shape[1][i] = '|';
		else
			shape[1][i] = '_';

	}

	//Row3
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0 || i == 8)
			shape[2][i] = '\'';
		else if (i == 2 || i == 6)
			shape[2][i] = '0';
		else
			shape[2][i] = '-';
	}
}

cTruck::~cTruck() {
	for (int i = 0; i < TRUCK_HEIGHT; i++)
		delete[] shape[i];
	delete[] shape;
	delete[] shape;
}

char** cTruck::returnShape() {
	return shape;
}

int cTruck::getWidth() {
	return TRUCK_WIDTH;
}

int cTruck::getHeight() {
	return TRUCK_HEIGHT;
}

int cTruck::inGameWidth() {
	return 6;
}