#include "CBIRD.h"

CBIRD::CBIRD(cPoint pos) : CANIMAL(pos) {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [4];
    for (int i = 0; i < 4; i++)
        shape[i] = new char[6];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            shape[i][j] = ' ';

    shape[0][3] = '(';
    shape[0][4] = 'o';
    shape[0][5] = '>';

    // Draw head
    shape[1][0] = '\\';
    shape[1][1] = '\\';
    shape[1][2] = '_';
    shape[1][3] = '/';
    shape[1][4] = '/';
    shape[1][5] = ')';

    // Draw body
    shape[2][1] = '\\';
    shape[2][2] = '_';
    shape[2][3] = '/';
    shape[2][4] = '_';
    shape[2][5] = ')';

    // Draw leg
    shape[3][2] = '_';
    shape[3][3] = '|';
    shape[3][4] = '_';
}

CBIRD::CBIRD() {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [4];
    for (int i = 0; i < 4; i++)
        shape[i] = new char[6];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            shape[i][j] = ' ';

    shape[0][3] = '(';
    shape[0][4] = 'o';
    shape[0][5] = '>';

    // Draw head
    shape[1][0] = '\\';
    shape[1][1] = '\\';
    shape[1][2] = '_';
    shape[1][3] = '/';
    shape[1][4] = '/';
    shape[1][5] = ')';

    // Draw body
    shape[2][1] = '\\';
    shape[2][2] = '_';
    shape[2][3] = '/';
    shape[2][4] = '_';
    shape[2][5] = ')';

    // Draw leg
    shape[3][2] = '_';
    shape[3][3] = '|';
    shape[3][4] = '_';
}

CBIRD::~CBIRD() {
    for (int i = 0; i < 4; i++)
        delete[] shape[i];

    delete[] shape;
}

char** CBIRD::returnShape() {
    return shape;
}

int CBIRD::getHeight() {
    return BIRD_HEIGHT;
}

int CBIRD::getWidth() {
    return BIRD_WIDTH;
}
