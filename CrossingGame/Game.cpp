#include "Game.h";

Game::Game(int _level) {
	level = _level;
	score = 0;
}

void Game::StartGame() {	
	CLIGHT light;
	int timer = 3000;
	while (true) {
		Graphics::PrintInterface();

		while (timer) {
			light.update_light();
			Sleep(1000);
			timer -= 50;
		}
	}
	thread t1(p.mainPeople);
}

void Game::EndGame(thread* t) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	t->join();
}
