#include "CDINOSAUR.h"

CDINOSAUR::CDINOSAUR(CPOSITION pos) : CANIMAL(pos) {
	dinoShape = new char* [4];
    for (int i = 0; i < 4; i++)
        dinoShape[i] = new char[7];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 7; j++)
            dinoShape[i]][j] = ' ';
  
    dinoShape[0][4] = '_';
    dinoShape[0][5] = '_';

    // Draw head
    dinoShape[1][3] = '/';
    dinoShape[1][4] = 'o';
    dinoShape[1][5] = '_';
    dinoShape[1][6] = ')';

    // Draw body
    dinoShape[2][0] = '|';
    dinoShape[2][1] = '\\';
    dinoShape[2][2] = '/';
    dinoShape[2][4] = '>';
    dinoShape[2][5] = '>';

    // Draw 
    dinoShape[3][0] = '\';
    dinoShape[3][1] = '_';
    dinoShape[3][2] = 'v';
    dinoShape[3][3] = '_';
    dinoShape[3][4] = '|';
}

CDINOSAUR::~CDINOSAUR() {
    for (int i = 0; i < 4; i++)
        delete dinoShape[i];
    delete dinoShape;
}

char** CDINOSAUR::shape() {
    return dinoShape;
}

int CBIRD::getHeight() {
    return 4;
}   

int CBIRD::getWidth() {
    return 7;
}