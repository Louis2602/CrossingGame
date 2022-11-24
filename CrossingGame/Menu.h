#pragma once
#include "Header.h"
#include "Graphics.h"
#include "Controller.h"
#include "Sound.h"
#include "Game.h"

class Menu {
public:	
	void MainMenu();
	void MenuGameplay();
	void MenuRule();
	void MenuAbout();
	void MenuScore();
	void PlayGame();
	void LoadGame();
};