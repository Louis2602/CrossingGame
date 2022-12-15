#include "CDINO.h"

CDINO::CDINO(cPoint pos) : COBJECT(pos) {

    shape = new char* [DINO_HEIGHT];
    for (int i = 0; i < DINO_HEIGHT; i++)
        shape[i] = new char[DINO_WIDTH];

    for (int i = 0; i < DINO_HEIGHT; i++)
        for (int j = 0; j < DINO_WIDTH; j++)
            shape[i][j] = ' ';
    // Draw head
    shape[0][1] = '(';
    shape[0][2] = '`';
    shape[0][3] = '~';
    shape[0][4] = '~';
    shape[0][5] = ')';

    shape[1][1] = '//';
    shape[1][2] = '>';
    shape[1][4] = '>';

    shape[2][0] = '//';
    shape[2][2] = ')';
    shape[2][4] = ')';
}

CDINO::CDINO() {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [DINO_HEIGHT];
    for (int i = 0; i < DINO_HEIGHT; i++)
        shape[i] = new char[DINO_WIDTH];

    for (int i = 0; i < DINO_HEIGHT; i++)
        for (int j = 0; j < DINO_WIDTH; j++)
            shape[i][j] = ' ';

    // Draw head
    shape[0][1] = '(';
    shape[0][2] = '`';
    shape[0][3] = '~';
    shape[0][4] = '~';
    shape[0][5] = ')';

    shape[1][1] = '//';
    shape[1][2] = '>';
    shape[1][4] = '>';

    shape[2][0] = '//';
    shape[2][2] = ')';
    shape[2][4] = ')';
}

CDINO::~CDINO() {
    for (int i = 0; i < 4; i++)
        delete[] shape[i];

    delete[] shape;
}

char** CDINO::returnShape() {
    return shape;
}

int CDINO::getHeight() {
    return DINO_HEIGHT;
}

int CDINO::getWidth() {
    return DINO_WIDTH;
}

int CDINO::inGameWidth() {
    return 5;
}