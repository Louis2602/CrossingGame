#include "CBIRD.h"

CBIRD::CBIRD(CPOSITION pos) : CANIMAL(pos) {
	birdShap = new char* [4];
	for (int i = 0; i < 4; i++)
		birdShape[i] = new char[6];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			birdShape[i]][j] = ' ';

    birdShape[0][3] = '(';
    birdShape[0][4] = 'o';
    birdShape[0][5] = '>';

    // Draw head
    birdShape[1][0] = '\\';
    birdShape[1][1] = '\\';
    birdShape[1][2] = '_';
    birdShape[1][3] = '/';
    birdShape[1][4] = '/';
    birdShape[1][5] = ')';

    // Draw body
    birdShape[2][1] = '\\';
    birdShape[2][2] = '_';
    birdShape[2][3] = '/';
    birdShape[2][4] = '_';
    birdShape[2][5] = ')';

    // Draw leg
    birdShape[3][2] = '_';
    birdShape[3][3] = '|';
    birdShape[3][4] = '_';
}

CBIRD::~CBIRD() {
    for (int i = 0; i < 4; i++)
        delete birdShape[i];

    delete birdShape;
}

char ** CBIRD::shape() {
    return birdShape;
}

int CBIRD::getHeight() {
    return 4;
}

int CBIRD::getWidth() {
    return 6
}
