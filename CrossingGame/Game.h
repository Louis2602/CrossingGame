#pragma once
#ifndef GAME_h
#define GAME_h

#include "Header.h"
#include "CPEOPLE.h"
#include "Graphics.h"
#include "cLine.h"
#include "Menu.h"

class Game {
private:
	string playerName, playerID, className;
	string filename;
	vector<string> listSaveFile;
	int level;
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
	CPEOPLE mPeople;
	CLIGHT mLight;
	Sound mSound;
	int score;
public:
	Game();
	Game(int);
	~Game() {};
	int curLevel() {
		return this->level;
	}
	void SetUpGame();
	void StartGame();
	void EndGame(thread*);
	void SaveGame();
	void PauseGame();
	void LoadGame();
	void playGame(thread&, thread&);
	void printHelp();
	void renderLight();
	void renderObject();
};
#endif // !Game