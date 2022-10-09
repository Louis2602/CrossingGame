#include "Graphics.h"

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
void Graphics::LoadBackground() {
	Controller::GotoXY(7, 2); Controller::TextColor(9); cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 3); Controller::TextColor(9); cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 4); Controller::TextColor(10); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 5); Controller::TextColor(11); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 6); Controller::TextColor(12); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 7); Controller::TextColor(12); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |\n";
	Controller::GotoXY(5, 7); Controller::TextColor(13); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 8); Controller::TextColor(13); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

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

void Graphics::Menu(int Round) {
	LoadBackground();
	DrawMenuBox();
	Controller::GotoXY(43, 12);
	Controller::TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	Controller::GotoXY(53, 13);
	cout << "GAME: CROSSING GAME";
	int idx = 15, idx_t = 15;
	Controller::GotoXY(53, idx);
	Controller::TextColor(14);
	cout << (char)175;
	Controller::GotoXY(56, 15);
	cout << "Start Game    " << endl;
	Controller::GotoXY(56, 16);
	Controller::TextColor(7);
	cout << "Rule       " << endl;
	Controller::GotoXY(50, 17);
	cout << "      About      " << endl;
	Controller::GotoXY(50, 18);
	cout << "      Score      " << endl;
	Controller::GotoXY(56, 19);
	cout << "Quit Game      " << endl;

	while (true)
	{
		char s = toupper(_getch());
		Controller::TextColor(11);
		idx_t = idx;
		if (s == 'W' || s == 72)
			idx--;
		else
			if (s == 'S' || s == 80)
				idx++;
		if (idx > 19)
			idx = 15;
		else
			if (idx < 15)
				idx = 19;
		Controller::GotoXY(53, idx_t);
		cout << "  ";
		Controller::GotoXY(53, idx);
		Controller::TextColor(14);
		cout << (char)175;
		Controller::GotoXY(56, 15);
		Controller::TextColor(7);
		if (idx == 15)
			Controller::TextColor(14);
		cout << "Start Game" << endl;
		Controller::GotoXY(56, 16);
		Controller::TextColor(7);
		if (idx == 16)
			Controller::TextColor(14);
		cout << "Rule" << endl;
		Controller::GotoXY(56, 17);
		Controller::TextColor(7);
		if (idx == 17)
			Controller::TextColor(14);
		cout << "About" << endl;
		Controller::GotoXY(56, 18);
		Controller::TextColor(7);
		if (idx == 18)
			Controller::TextColor(14);
		cout << "Score" << endl;
		Controller::TextColor(7);
		if (idx == 19)
			Controller::TextColor(14);
		Controller::GotoXY(56, 19);
		cout << "Quit Game" << endl;
		if (s == 13)
		{
			idx -= 14;
			break;
		}
	}
	switch (idx)
	{
	case 1:
		Menu::MenuGameplay(Round);
		break;
	case 2:
		Menu::MenuRule(Round);
		break;
	case 3:
		Menu::MenuAbout(Round);
		break;
	case 4:
		Menu::MenuScore(Round);
		break;
	case 5:
		Menu::MenuQuitGame();
		break;
	}
}