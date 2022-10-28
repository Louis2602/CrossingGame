#pragma once
#include "Header.h"
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CLIGHT.h"
#include "CVEHICLE.h"
#include "Graphics.h"

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