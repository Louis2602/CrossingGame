#pragma once

#include <Windows.h>
#include <string>	

using namespace std;

#define WIDTH_CONSOLE 1366
#define HEIGH_CONSOLE 768

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