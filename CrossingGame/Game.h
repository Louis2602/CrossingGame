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
	char playerName[15] = "", playerID[9] = "", className[8] = "";
	string filename;
	int level;
	bool IS_RUNNING;
	bool PAUSE_STATE;
	bool SAVE_GAME;
	//CLINEAnimal mLine;
	CPEOPLE mPeople;
	CLIGHT mLight;
	Sound mSound;
public:
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