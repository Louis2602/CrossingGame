#pragma once
#include "Header.h"

class Game {
private:
	int score;
	int level;
	bool IS_RUNNING = false;
	bool PAUSE_STATE = false;

public:
	Game(int);
	~Game() {};
	void StartGame();
	void EndGame(thread*);
	void PauseGame();
	void SaveGame();
	void LoadGame();
};