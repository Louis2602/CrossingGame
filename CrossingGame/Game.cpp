#include "Game.h";

Game::Game(int level) {
	_level = level;
	score = 0;
}

void Game::StartGame() {
	Graphics::PrintInterface();
	system("pause");
}