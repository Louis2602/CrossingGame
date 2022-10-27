#include "CCAR.h"


CCAR::CCAR(cPoint pos): CVEHICLE(pos) {
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
		switch (i)
		{
		case 0: case 3: case 8:
		{
			shape[1][i] = ' ';
			break;
		}
		case 1: case 5: case 7:
		{
			shape[1][i] = '_';
			break;
		}
		case 2:
		{
			shape[1][i] = '/';
			break;
		}
		case 6:
		{
			shape[1][i] = '\\';
			break;
		}
		default:
			break;
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

CCAR::CCAR(){
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
		switch (i)
		{
		case 0: case 3: case 8:
		{
			shape[1][i] = ' ';
			break;
		}
		case 1: case 5: case 7:
		{
			shape[1][i] = '_';
			break;
		}	
		case 2:
		{
			shape[1][i] = '/';
			break;
		}
		case 6:
		{
			shape[1][i] = '\\';
			break;
		}
			default:
				break;
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

CCAR::~CCAR() {
	for (int i = 0; i < CAR_HEIGHT; i++)
		delete[] shape[i];
	delete[] shape;
	delete[] shape;
}

char** CCAR::returnShape() {
	return shape;
}

int getWidth() {
	return 8;
}

