#include "Graphics.h";
void Graphics::PrintInterface() {
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
	/*Controller::GotoXY(138, 2); cout << "<Crossing Road Game>";
	Controller::GotoXY(138, 4); cout << "LV. 1" << endl;
	Controller::GotoXY(138, 6); cout << "CONTROL MANUAL" << endl;
	Controller::GotoXY(138, 7); cout << "[" << 'W' << "]: UP" << endl;
	Controller::GotoXY(138, 8); cout << "[" << 'S' << "]: DOWN" << endl;
	Controller::GotoXY(138, 9); cout << "[" << 'A' << "]: LEFT" << endl;
	Controller::GotoXY(138, 10); cout << "[" << 'D' << "]: RIGHT" << endl;
	Controller::GotoXY(138, 12); cout << "COMMANDS" << endl;
	Controller::GotoXY(138, 13); cout << "[ L ]: Save game" << endl;
	Controller::GotoXY(138, 14); cout << "[ T ]: Load game" << endl;
	Controller::GotoXY(138, 15); cout << "[ P ]: Pause game/Menu" << endl;*/


	Controller::SetColor(BLACK);
	DrawRectangle(59, 24, 33, 2);
	DrawRectangle(59, 27, 14, 2);
	DrawRectangle(78, 27, 14, 2);

	Controller::SetColor(PURPLE);
	Controller::GotoXY(67, 25);
	cout << "M : Move suggestion";
	Controller::SetColor(GREEN);
	Controller::GotoXY(63, 28);
	cout << "H : Help";
	Controller::SetColor(YELLOW);
	Controller::GotoXY(81, 28);
	cout << "Esc : Exit";
}

void Graphics::DrawMap() {

}

void Graphics::PrintScoreboard() {
	Controller::SetColor(BLACK);
	DrawRectangle(59, 1, 33, 10);
	DrawRectangle(59, 12, 33, 10);

	DrawRectangle(60, 2, 31, 2);
	Controller::SetColor(RED);
	Controller::GotoXY(67, 3);
	cout << "PLAYER'S INFORMATION";

	Controller::SetColor(BLUE);
	Controller::GotoXY(65, 5);
	cout << "Player's name: ";

	Controller::SetColor(BLACK);
	DrawRectangle(60, 13, 31, 2);
	Controller::SetColor(RED);
	Controller::GotoXY(69, 14);
	cout << "GAME INFORMATION";
	Controller::SetColor(BLUE);
	Controller::GotoXY(65, 16);
	cout << "Moves:";
	Controller::GotoXY(65, 17);
	cout << "Current score:";
	Controller::GotoXY(80, 17);
	cout << 1;
}