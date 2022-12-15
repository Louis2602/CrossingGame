#include "Header.h"
#include "Controller.h"
#include "Menu.h"
#include "Sound.h"

mutex mtx;

int main() {
	srand((unsigned int)time(NULL));

	Controller::SetUpConsole();
	Sound s;
	s.SoundBackground(true);

	Menu game;
	game.MainMenu();
}