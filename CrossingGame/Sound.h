#pragma once
#include "Header.h"

class Sound {
	bool isOn = true;
public:
	Sound() {};
	~Sound() {};
	bool getState();
	void setState(bool);
	void SoundBackground();
	//void SoundGameOver();		//Sound Game over when you lost
	//void SoundGameWin();		//Sound Game when you win the game
	void SoundByeBye();
	void SoundRocket();
	void EndSoundGame();         //End sound game
	void PlayerMove();
	void SoundSuccess();
};
