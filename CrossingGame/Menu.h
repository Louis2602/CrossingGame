#pragma once
#include "Header.h"
#include "Graphics.h"
#include "Controller.h"
#include "Sound.h"
#include "Game.h"

class Menu {
public:	
	void MainMenu();
	void MenuRule();
	void MenuAbout();
	void MenuScore();
	void MenuSettings();
	void PlayGame();
	void LoadGame();
};