#include "Graphics.h";
void Graphics::PrintInterface() {
	Controller::ClearConsole();
	DrawMap();
	PrintInstruct();
	PrintScoreboard();
}
void Graphics::DrawMenuBox() {
	Controller::TextColor(17);
	Controller::GotoXY(41, 11); cout << "==========================================";
	Controller::GotoXY(41, 22); cout << "==========================================";

	for (int i = 12; i < 22; i++)
	{
		Controller::GotoXY(41, i);
		cout << "||";
		Controller::GotoXY(81, i);
		cout << "||";
	}
}
void Graphics::DrawRectangle(int left, int top, int width, int height) {
	Controller::GotoXY(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		Controller::GotoXY(left, top + i + 1);
		putchar(179);
		Controller::GotoXY(left + width + 1, top + i + 1);
		putchar(179);
	}

	Controller::GotoXY(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
void Graphics::LoadBackground() {
	Controller::GotoXY(7, 2); Controller::TextColor(LIGHT_BLUE); cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 3); Controller::TextColor(LIGHT_BLUE); cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 4); Controller::TextColor(LIGHT_GREEN); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 5); Controller::TextColor(LIGHT_AQUA); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 6); Controller::TextColor(LIGHT_RED); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 7); Controller::TextColor(LIGHT_RED); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |\n";
	Controller::GotoXY(5, 7); Controller::TextColor(LIGHT_PURPLE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 8); Controller::TextColor(LIGHT_PURPLE); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	Controller::TextColor(11);
	Controller::GotoXY(23, 5); cout << " /";
	Controller::GotoXY(23, 6); cout << "//";
	Controller::GotoXY(22, 7); cout << "//";
	Controller::GotoXY(21, 8); cout << "//";
	Controller::GotoXY(20, 9); cout << "//";
	Controller::GotoXY(19, 10); cout << "//";
	Controller::GotoXY(18, 11); cout << "//";
	Controller::GotoXY(17, 12); cout << "//";
	Controller::GotoXY(16, 13); cout << "//";
	Controller::GotoXY(16, 14); cout << "\\\\";
	Controller::GotoXY(17, 15); cout << "\\\\";
	Controller::GotoXY(18, 16); cout << "\\\\";
	Controller::GotoXY(19, 17); cout << "\\\\";
	Controller::GotoXY(20, 18); cout << "\\\\";
	Controller::GotoXY(21, 19); cout << "\\\\";
	Controller::GotoXY(22, 20); cout << "\\\\";
	Controller::GotoXY(23, 21); cout << "\\\\";
	Controller::GotoXY(24, 22); cout << "\\\\";
	Controller::GotoXY(25, 23); cout << "\\\\";
	Controller::GotoXY(26, 24); cout << "\\\\";
	Controller::GotoXY(27, 25); cout << "\\\\";
	Controller::GotoXY(28, 26); cout << "\\\\";
	Controller::GotoXY(29, 27); cout << "\\\\";
	Controller::GotoXY(30, 28); cout << "\\\\";

	Controller::GotoXY(103, 4); cout << "\\";
	Controller::GotoXY(103, 5); cout << "\\\\";
	Controller::GotoXY(104, 6); cout << "\\\\";
	Controller::GotoXY(105, 7); cout << "\\\\";
	Controller::GotoXY(106, 8); cout << "\\\\";
	Controller::GotoXY(107, 9); cout << "\\\\";
	Controller::GotoXY(108, 10); cout << "\\\\";
	Controller::GotoXY(109, 11); cout << "\\\\";
	Controller::GotoXY(110, 12); cout << "\\\\";
	Controller::GotoXY(111, 13); cout << "\\\\";
	Controller::GotoXY(111, 14); cout << "//";
	Controller::GotoXY(110, 15); cout << "//";
	Controller::GotoXY(109, 16); cout << "//";
	Controller::GotoXY(108, 17); cout << "//";
	Controller::GotoXY(107, 18); cout << "//";
	Controller::GotoXY(106, 19); cout << "//";
	Controller::GotoXY(105, 20); cout << "//";
	Controller::GotoXY(104, 21); cout << "//";
	Controller::GotoXY(103, 22); cout << "//";
	Controller::GotoXY(102, 23); cout << "//";
	Controller::GotoXY(101, 24); cout << "//";
	Controller::GotoXY(100, 25); cout << "//";
	Controller::GotoXY(99, 26); cout << "//";
	Controller::GotoXY(98, 27); cout << "//";
	Controller::GotoXY(97, 28); cout << "//";

	Controller::GotoXY(32, 28); cout << "========================";
	Controller::GotoXY(72, 28); cout << "=========================";

	Controller::TextColor(14);
	Controller::GotoXY(55, 24); cout << "    ||     ||     ";
	Controller::GotoXY(55, 25); cout << "   |  |___|  |    ";
	Controller::GotoXY(55, 26); cout << "  [    |_|    ]    ";
	Controller::GotoXY(55, 27); cout << " [_____________]   ";
	Controller::GotoXY(55, 28); cout << "[_______________]";
	Controller::GotoXY(55, 29); cout << "    ||     ||       ";
}
void Graphics::PrintInstruct() {
	Controller::SetColor(BRIGHT_WHITE);
	DrawRectangle(79, 24, 33, 2);
	DrawRectangle(79, 27, 14, 2);
	DrawRectangle(98, 27, 14, 2);

	Controller::SetColor(PURPLE);
	Controller::GotoXY(90, 25);
	cout << "L : Save Game";
	Controller::SetColor(GREEN);
	Controller::GotoXY(83, 28);
	cout << "P : Pause";
	Controller::SetColor(GRAY);
	Controller::GotoXY(101, 28);
	cout << "Esc : Exit";
}

void Graphics::DrawMap() {
	Controller::SetColor(BRIGHT_WHITE);
	int left = 4, top = 3, size = 8;
	// Draw top line
	Controller::GotoXY(left + 1, top);
	putchar(201);
	for (int i = 1; i < size * 8; i++)
	{
		Sleep(5);
		if (i % 8 == 0)
			putchar(205);
		else
			putchar(205);
	}
	putchar(187);

	// Draw right line
	for (int i = 1; i < size * 3; i++)
	{
		Sleep(10);
		Controller::GotoXY(size * 8 + left + 1, i + top);
		if (i % 4 != 0)
			putchar(186);
		else
			putchar(186);
	}
	Controller::GotoXY(size * 8 + left + 1, size * 3 + top);
	putchar(188);

	// Draw bottom line
	for (int i = 1; i < size * 8; i++)
	{
		Controller::GotoXY(size * 8 + left - i + 1, size * 3 + top);
		Sleep(5);
		if (i % 8 == 0)
			putchar(205);
		else
			putchar(205);
	}
	Controller::GotoXY(left + 1, size * 3 + top);
	putchar(200);

	// Draw left line
	for (int i = 1; i < size * 3; i++)
	{
		Sleep(10);
		Controller::GotoXY(left + 1, size * 3 + top - i);
		if (i % 4 != 0)
			putchar(186);
		else
			putchar(186);
	}

	// Draw horizontal lines
	for (int i = 1; i < size * 8; i++)
	{
		for (int j = 4; j < size * 3; j += 4)
		{
			Controller::GotoXY(i + left + 1, j + top);
				putchar(196);
		}
		Sleep(5);
	}
}

void Graphics::PrintScoreboard() {
	Controller::SetColor(BRIGHT_WHITE);
	DrawRectangle(79, 1, 33, 10);
	DrawRectangle(79, 12, 33, 10);

	DrawRectangle(80, 2, 31, 2);
	Controller::SetColor(YELLOW);
	Controller::GotoXY(87, 3);
	cout << "PLAYER'S INFORMATION";

	Controller::SetColor(AQUA);
	Controller::GotoXY(85, 5);
	cout << "Player's name: ";

	Controller::SetColor(BRIGHT_WHITE);
	DrawRectangle(80, 13, 31, 2);
	Controller::SetColor(YELLOW);
	Controller::GotoXY(89, 14);
	cout << "GAME INFORMATION";
	Controller::SetColor(AQUA);
	Controller::GotoXY(85, 16);
	cout << "Moves:";
	Controller::GotoXY(85, 17);
	cout << "Current score:";
	Controller::GotoXY(100, 17);
	cout << 1;
}