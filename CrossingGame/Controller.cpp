#include "Controller.h";

HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void Controller::SetUpConsole() {
	SetFontInfo();
	SetAndCenterWindow();
	FixConsoleWindow();
	ConsoleTitle();
	HideScrollBars();
	ShowCursor(false);
	DisableMouseInput();
	system("color F0");
}
void Controller::FixConsoleWindow() {
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Controller::SetAndCenterWindow() {
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int posX = (GetSystemMetrics(SM_CXSCREEN) - WIDTH_CONSOLE) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - HEIGH_CONSOLE) / 2;
	MoveWindow(consoleWindow, posX, posY, WIDTH_CONSOLE, HEIGH_CONSOLE, TRUE);
}
void Controller::GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(consoleOutput, coord);
}
void Controller::HideScrollBars() {
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}
void Controller::SetFontInfo() {
	// 12 - 24
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;
	info.dwFontSize.Y = 24;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}
void Controller::DisableMouseInput() {
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}
void Controller::ShowCursor(bool show) {
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}
void Controller::ConsoleTitle() {
	SetConsoleTitleA("Crossing Game");
}
void Controller::ClearConsole() {
	system("cls");
}
void Controller::SetConsoleColor(int background, int text) {
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}
int Controller::GetConsoleInput()
{
	int c = _getch();
	// Arrow key
	if (c == 0 || c == 224)
	{
		switch (_getch())
		{
		case KEY_UP:				//up
			return 2;
		case KEY_LEFT:				//left
			return 3;
		case KEY_RIGHT:				//right
			return 4;
		case KEY_DOWN:				//down
			return 5;
		default:					//others
			return 0;
		}
	}
	else
	{
		if (c == KEY_ESC)             //Esc
			return 1;
		else if (c == 87 || c == 119) //W, w
			return 2;
		else if (c == 65 || c == 97)  //A, a
			return 3;
		else if (c == 68 || c == 100) //D, d
			return 4;
		else if (c == 83 || c == 115) //S, s
			return 5;
		else if (c == 13)             //Enter
			return 6;
		else if (c == 80 || c == 112) //P, p
			return 7;
		else if (c == 76 || c == 108) //L, l
			return 8;
		else if (c == 72 || c == 104) //H, h
			return 9;
		else
			return 0;                 //others
	}
}