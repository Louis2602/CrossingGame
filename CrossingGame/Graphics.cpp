#include "Header.h";

void DrawMenuBox() {
	TextColor(17);
	GotoXY(41, 11); cout << "==========================================";
	GotoXY(41, 22); cout << "==========================================";

	for (int i = 12; i < 22; i++)
	{
		GotoXY(41, i);
		cout << "||";
		GotoXY(81, i);
		cout << "||";
	}
}
void LoadBackground() {
	GotoXY(7, 2); TextColor(9); cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	GotoXY(5, 3); TextColor(9); cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	GotoXY(5, 4); TextColor(10); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	GotoXY(5, 5); TextColor(11); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	GotoXY(5, 6); TextColor(12); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	GotoXY(5, 7); TextColor(12); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |\n";
	GotoXY(5, 7); TextColor(13); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	GotoXY(5, 8); TextColor(13); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	TextColor(11);
	GotoXY(23, 5); cout << " /";
	GotoXY(23, 6); cout << "//";
	GotoXY(22, 7); cout << "//";
	GotoXY(21, 8); cout << "//";
	GotoXY(20, 9); cout << "//";
	GotoXY(19, 10); cout << "//";
	GotoXY(18, 11); cout << "//";
	GotoXY(17, 12); cout << "//";
	GotoXY(16, 13); cout << "//";
	GotoXY(16, 14); cout << "\\\\";
	GotoXY(17, 15); cout << "\\\\";
	GotoXY(18, 16); cout << "\\\\";
	GotoXY(19, 17); cout << "\\\\";
	GotoXY(20, 18); cout << "\\\\";
	GotoXY(21, 19); cout << "\\\\";
	GotoXY(22, 20); cout << "\\\\";
	GotoXY(23, 21); cout << "\\\\";
	GotoXY(24, 22); cout << "\\\\";
	GotoXY(25, 23); cout << "\\\\";
	GotoXY(26, 24); cout << "\\\\";
	GotoXY(27, 25); cout << "\\\\";
	GotoXY(28, 26); cout << "\\\\";
	GotoXY(29, 27); cout << "\\\\";
	GotoXY(30, 28); cout << "\\\\";

	GotoXY(103, 4); cout << "\\";
	GotoXY(103, 5); cout << "\\\\";
	GotoXY(104, 6); cout << "\\\\";
	GotoXY(105, 7); cout << "\\\\";
	GotoXY(106, 8); cout << "\\\\";
	GotoXY(107, 9); cout << "\\\\";
	GotoXY(108, 10); cout << "\\\\";
	GotoXY(109, 11); cout << "\\\\";
	GotoXY(110, 12); cout << "\\\\";
	GotoXY(111, 13); cout << "\\\\";
	GotoXY(111, 14); cout << "//";
	GotoXY(110, 15); cout << "//";
	GotoXY(109, 16); cout << "//";
	GotoXY(108, 17); cout << "//";
	GotoXY(107, 18); cout << "//";
	GotoXY(106, 19); cout << "//";
	GotoXY(105, 20); cout << "//";
	GotoXY(104, 21); cout << "//";
	GotoXY(103, 22); cout << "//";
	GotoXY(102, 23); cout << "//";
	GotoXY(101, 24); cout << "//";
	GotoXY(100, 25); cout << "//";
	GotoXY(99, 26); cout << "//";
	GotoXY(98, 27); cout << "//";
	GotoXY(97, 28); cout << "//";

	GotoXY(32, 28); cout << "========================";
	GotoXY(72, 28); cout << "=========================";

	TextColor(14);
	GotoXY(55, 24); cout << "    ||     ||     ";
	GotoXY(55, 25); cout << "   |  |___|  |    ";
	GotoXY(55, 26); cout << "  [    |_|    ]    ";
	GotoXY(55, 27); cout << " [_____________]   ";
	GotoXY(55, 28); cout << "[_______________]";
	GotoXY(55, 29); cout << "    ||     ||       ";
}

void Menu() {
	LoadBackground();
	DrawMenuBox();
	GotoXY(43, 12);
	TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	GotoXY(53, 13);
	cout << "GAME: CROSSING GAME";
	int idx = 15, idx_t = 15;
	GotoXY(53, idx);
	TextColor(14);
	cout << (char)175;
	GotoXY(56, 15);
	cout << "Start Game    " << endl;
	GotoXY(56, 16);
	TextColor(7);
	cout << "Rule       " << endl;
	GotoXY(50, 17);
	cout << "      About      " << endl;
	GotoXY(50, 18);
	cout << "      Score      " << endl;
	GotoXY(56, 19);
	cout << "Quit Game      " << endl;

	while (true)
	{
		char s = toupper(_getch());
		TextColor(11);
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
		GotoXY(53, idx_t);
		cout << "  ";
		GotoXY(53, idx);
		TextColor(14);
		cout << (char)175;
		GotoXY(56, 15);
		TextColor(7);
		if (idx == 15)
			TextColor(14);
		cout << "Start Game" << endl;
		GotoXY(56, 16);
		TextColor(7);
		if (idx == 16)
			TextColor(14);
		cout << "Rule" << endl;
		GotoXY(56, 17);
		TextColor(7);
		if (idx == 17)
			TextColor(14);
		cout << "About" << endl;
		GotoXY(56, 18);
		TextColor(7);
		if (idx == 18)
			TextColor(14);
		cout << "Score" << endl;
		TextColor(7);
		if (idx == 19)
			TextColor(14);
		GotoXY(56, 19);
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
		MenuGameplay();
		break;
	case 2:
		MenuRule();
		break;
	case 3:
		MenuAbout();
		break;
	case 4:
		MenuScore();
		break;
	case 5:
		MenuQuitGame();
		break;
	}
}