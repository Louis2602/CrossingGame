#pragma once

#include "Sound.h"
#include "Controller.h"
#include "Menu.h"

#include <Windows.h>
#include <thread>
#include <iostream>
#include <conio.h>

using namespace std;

class Graphics {
public:
	static void Menu(int);
	static void LoadBackground();
	static void DrawMenuBox();
};