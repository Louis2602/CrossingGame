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
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
public:
	Game(int);
	~Game() {};
	void StartGame();
	void EndGame(thread*);
	void PauseGame();
	void SaveGame();
	void LoadGame();
	void askContinue();
	void saveGame();
};