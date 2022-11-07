#include "Header.h"
#include "cCar.h"

CPEOPLE people;
CANIMAL animal[];
CVEHICLE* car;

bool Continue = false;
bool PlayAgain = false;
bool Impact = false;

int main() {
	srand(time(NULL));

	Controller::SetUpConsole();
	//Sound::SoundBackground();

	Menu game;
	game.MainMenu();
}
