#include "Header.h"
#include "CCAR.h"

CPEOPLE people;
CANIMAL animal[];
CCAR car[];

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
