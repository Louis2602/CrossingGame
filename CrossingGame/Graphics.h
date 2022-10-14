#pragma once
#include "Header.h"

class Graphics {
public:
	Graphics() {};
	~Graphics() {};
	static void LoadBackground();
	static void DrawMenuBox();
	static void DrawRectangle(int, int, int, int);
	static void PrintInstruct();
	static void PrintScoreboard();
	static void DrawMap();
	static void PrintInterface();
};