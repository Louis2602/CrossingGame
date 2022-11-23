#pragma once
#ifndef Graphics

#include "Controller.h"
#include "Sound.h"

class Graphics {
public:
	Graphics() {};
	~Graphics() {};
	static void LoadBackground();
	static void DrawMenuBox();
	static void DrawRectangle(int, int, int, int);
	static void PrintInstruct();
	static void PrintInfo();
	static void DrawMap();
	static void PrintInterface();
	static void DrawGoodbyeScreen();
};

#endif // !Graphics
