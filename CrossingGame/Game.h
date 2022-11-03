#pragma once
#include "CPEOPLE.h"
#include "Graphics.h"

class Game {
private:
	int score;
	int level;
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
	CPEOPLE p;
	CLIGHT l;
	Sound s;
public:
	Game(int);
	~Game() {};
	void SetUpGame();
	void StartGame();
	void EndGame(thread*);
	void PauseGame();
	void SaveGame();
	void LoadGame();
	void askContinue();
};