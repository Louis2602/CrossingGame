#include "Header.h"

int Round = 1;
CPEOPLE people;
CANIMAL animal[];
CVEHICLE vehicle[];


int main() {
	srand(time(NULL));
	SetUpConsole();
	SoundBackground();
	Menu();
}