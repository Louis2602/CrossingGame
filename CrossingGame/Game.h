#pragma once
#ifndef GAME_h
#define GAME_h

#include "Header.h"
#include "CPEOPLE.h"
#include "Graphics.h"
#include "CLINEAnimal.h"

class Game {
private:
	int score;
	int level;
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
	CLINEAnimal mLine;
	CPEOPLE mPeople;
	CLIGHT mLight;
	Sound mSound;
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
	void askSaveGame();
	void playGame();
};
#endif // !Game