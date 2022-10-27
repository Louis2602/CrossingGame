#pragma once
#include "Header.h"

class Sound {
	bool isOn = true;
public:
	Sound() {};
	~Sound() {};
	bool getState();
	void setState(bool);
	static void SoundBackground();
	//void SoundGameOver();		//Sound Game over when you lost
	//void SoundGameWin();		//Sound Gamw when you win the game
	static void SoundByeBye();
	static void SoundRocket();
	static void EndSoundGame();         //End sound game
	static void PlayerMove();
};
