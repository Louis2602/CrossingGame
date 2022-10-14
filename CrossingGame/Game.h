#pragma once
#include "Header.h"

class Game {
private:
	int score;
	int _level;

public:
	Game(int);
	~Game() {};
	void StartGame();
	void EndGame();
	void PauseGame();
	void SaveGame();
	void LoadGame();
};