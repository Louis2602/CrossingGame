#include "Header.h";

HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void SetUpConsole() {
	SetFontInfo();
	SetAndCenterWindow();
	FixConsoleWindow();
	ConsoleTitle();
	HideScrollBars();
	ShowCursor(false);
	DisableMouseInput();
}

void FixConsoleWindow() {
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void SetAndCenterWindow() {
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int posX = (GetSystemMetrics(SM_CXSCREEN) - WIDTH_CONSOLE) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - HEIGH_CONSOLE) / 2;
	MoveWindow(consoleWindow, posX, posY, WIDTH_CONSOLE, HEIGH_CONSOLE, TRUE);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(consoleOutput, coord);
}

void HideScrollBars() {
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void SetFontInfo() {
	// 12 - 24
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;
	info.dwFontSize.Y = 24;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

void DisableMouseInput() {
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void ShowCursor(bool show) {
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}

void ConsoleTitle() {
	SetConsoleTitleA("Crossing Game");
}

void ClearConsole() {
	system("cls");
}

void TextColor(int x) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

void SetColor(int ForgC) {
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the foreground color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}