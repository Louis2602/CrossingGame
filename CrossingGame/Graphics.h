#pragma once
#include "Header.h"

class Graphics {
public:
	Graphics() {};
	~Graphics() {};
	static void LoadBackground();
	static void DrawMenuBox();
	static void DrawRectangle(int, int, int, int);
	void PrintInstruct();
	void PrintScoreboard();
	void DrawMap();
	void PrintInterface();
};