#pragma once
#pragma comment(lib, "Winmm.lib")

#include <Windows.h>


class Sound {
public:
	static void SoundBackground();
	static void SoundByeBye();
	static void EndSoundGame();
	static void SoundRocket();
};