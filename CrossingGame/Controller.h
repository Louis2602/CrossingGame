#pragma once
#include "Header.h"

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

class Controller {
public:
	Controller() {};
	~Controller() {};
	static void SetUpConsole();
	static void FixConsoleWindow();
	static void SetAndCenterWindow();
	static void GotoXY(int, int);
	static void HideScrollBars();
	static void SetFontInfo();
	static void DisableMouseInput();
	static void ShowCursor(bool);
	static void ConsoleTitle();
	static void ClearConsole();
	static void TextColor(int);
	static void SetColor(int);
};