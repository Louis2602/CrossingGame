#include "Header.h"
#include "Controller.h"
#include "Menu.h"
#include "Sound.h"

mutex mtx;

int main() {
	srand(time(NULL));

	Controller::SetUpConsole();
	/*Sound s;
	s.SoundBackground();*/

	Menu game;
	game.MainMenu();
}
