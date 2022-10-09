#pragma once
#include "Controller.h"
#include "Graphics.h"

#include <iostream>
#include <conio.h>

using namespace std;

class Menu {
public:
	static void MenuGameplay(int);
	static void MenuRule(int);
	static void MenuAbout(int);
	static void MenuScore(int);
	static void MenuQuitGame();
};