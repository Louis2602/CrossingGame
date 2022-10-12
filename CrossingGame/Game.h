#pragma once
#include "Header.h"

class Game {
private:
	int score;
	int _level;
	Graphics gp;

public:
	Game(int);
	~Game() {};
	void StartGame();
	void PrintInterface();
	void EndGame();
	void PauseGame();
	void SaveGame();
	void LoadGame();
};