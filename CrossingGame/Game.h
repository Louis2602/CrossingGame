#pragma once
#ifndef Game

#include "Header.h"
#include "CPEOPLE.h"
#include "Graphics.h"
#include "cCar.h"

class Game {
private:
	int score;
	int level;
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
	CLINEAnimal line;
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
	void playing();
};
#endif // !Game