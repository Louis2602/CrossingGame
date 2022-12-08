#pragma once
#include "Header.h"

class Sound {
	bool isOn = true;
public:
	Sound() {};
	~Sound() {};
	bool getState();
	void setState(bool);
	void SoundBackground(bool);
	void SoundByeBye();
	void SoundRocket();
	void EndSoundGame();         //End sound game
	void PlayerMove();
	void SoundSuccess();
	void SoundWin();
	void SoundLose();
};
