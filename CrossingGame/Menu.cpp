#include "Menu.h";

void Menu::MainMenu() {
	Graphics::LoadBackground();
	Graphics::DrawMenuBox();
	Controller::GotoXY(43, 12);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "CSC10003 - OBJECT ORIENTED PROGRAMMING";
	Controller::GotoXY(53, 13);
	cout << "GAME: CROSSING GAME";
	int idx = 15, idx_t = 15;
	Controller::GotoXY(53, idx);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << (char)175;
	Controller::GotoXY(56, 15);
	cout << "New Game    " << endl;
	Controller::GotoXY(56, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	cout << "Load Game       " << endl;
	Controller::GotoXY(50, 17);
	cout << "      Settings      " << endl;
	Controller::GotoXY(50, 18);
	cout << "      About      " << endl;
	Controller::GotoXY(56, 19);
	cout << "Quit      " << endl;

	while (true)
	{
		char s = toupper(_getch());
		Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA);
		idx_t = idx;

		if (s == 'W' || s == KEY_UP)
			idx--;
		else if (s == 'S' || s == KEY_DOWN)
			idx++;
		if (s == KEY_ESC)
			Graphics::DrawGoodbyeScreen();

		if (idx > 19)
			idx = 15;
		else if (idx < 15)
			idx = 19;
		Controller::GotoXY(53, idx_t);
		cout << "  ";
		Controller::GotoXY(53, idx);
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << (char)175;
		Controller::GotoXY(56, 15);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		if (idx == 15)
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << "New Game" << endl;
		Controller::GotoXY(56, 16);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		if (idx == 16)
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << "Load Game" << endl;
		Controller::GotoXY(56, 17);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		if (idx == 17)
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << "Settings" << endl;
		Controller::GotoXY(56, 18);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		if (idx == 18)
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << "About" << endl;
		Controller::GotoXY(56, 19);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		if (idx == 19)
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << "Quit" << endl;
		if (s == 13)
		{
			idx -= 14;
			break;
		}

	}
	switch (idx)
	{
	case 1:
		PlayGame();
		break;
	case 2:
		LoadGame();
		break;
	case 3:
		MenuSettings();
		break;
	case 4:
		MenuAbout();
		break;
	case 5:
		Graphics::DrawGoodbyeScreen();
		break;
	}
}
void Menu::MenuSettings() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(45, 13, 35, 8);
	Graphics::DrawRectangle(48, 18, 7, 2);
	Graphics::DrawRectangle(71, 18, 6, 2);

	Controller::GotoXY(49, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Turn Background Music On/Off";
	string str[2] = { "On", "Off" };
	int left[] = { 46,51,58,69,74,80 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			Controller::SetConsoleColor(BRIGHT_WHITE, color[i]);
			Controller::GotoXY(left[choice * 3], top);        putchar(word[i * 2]);
			Controller::GotoXY(left[choice * 3 + 1], top);    cout << str[choice];
			Controller::GotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	bool isOn = true;
	while (true)
	{
		int key = Controller::GetConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice)
				isOn = true;
			else
				isOn = false;
			break;
		}
	}

	if (!isOn) {
		bgSound.setState(false);
		bgSound.SoundBackground();
	}
	else {
		bgSound.setState(true);
		bgSound.SoundBackground();
	}

	Controller::ClearConsole();
	Menu::MainMenu();
}
void Menu::MenuRule() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(50, 13);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	cout << "FUNCTION KEYS";

	Controller::GotoXY(42, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "L : ";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "Save game";
	Controller::GotoXY(42, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "P : ";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "Pause game";
	Controller::GotoXY(42, 17);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "M : ";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "Turn off background music";
	Controller::GotoXY(42, 18);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "Esc : ";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "Exit";
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::GotoXY(45, 20);
	cout << "Cross the road and dodge";
	Controller::GotoXY(45, 21);
	cout << "obstacles (cars & animals)";

	Controller::GotoXY(78, 13);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	cout << "MOVE";

	Controller::GotoXY(75, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "     W   ";

	Controller::GotoXY(75, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "     ^";

	Controller::GotoXY(75, 17);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << " A ";

	Controller::GotoXY(78, 17);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "<   >";

	Controller::GotoXY(80, 17);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << "O";

	Controller::GotoXY(84, 17);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "D";

	Controller::GotoXY(75, 18);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "     v   ";

	Controller::GotoXY(75, 19);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "     S";
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);

	Controller::SetConsoleColor(BLACK, BLACK);
	char c = 219;
	for (int i = 13; i < 22; i++) {
		Controller::GotoXY(72, i);
		cout << c;
		Controller::GotoXY(88, i);
		cout << c;
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA);
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	Controller::GotoXY(44, 23);
	system("pause");
	Controller::ClearConsole();
	Menu::MainMenu();
}

void Menu::MenuAbout() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(40, 12);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	printf("  GV Huong Dan:                                       ");
	Controller::GotoXY(41, 13);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	printf("     - Truong Toan Thinh                        ");
	Controller::GotoXY(41, 14);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	printf(" Code by:                                          ");
	Controller::GotoXY(41, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	printf("     - 21127337: Tran Tung Lam                 ");
	Controller::GotoXY(41, 16);
	printf("     - 21127333: Nguyen Viet Kim                    ");
	Controller::GotoXY(41, 17);
	printf("     - 21127105: Bui Nguyen Nhat Minh                    ");
	Controller::GotoXY(41, 18);
	printf("     - 21127233: Vo Quoc Binh                    ");
	Controller::GotoXY(41, 19);
	printf("                                                     ");
	Controller::GotoXY(40, 21);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	printf("  HCMUS _ Ho Chi Minh University of Sience.");
	Controller::GotoXY(59, 22);
	cout << "2022-2023";
	Controller::GotoXY(45, 23);
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	system("pause");
	Controller::ClearConsole();
	Menu::MainMenu();
}

void Menu::MenuScore() {
	Controller::ClearConsole();
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << R"(
	  _      ______          _____  ______ _____  ____   ____          _____  _____  
	 | |    |  ____|   /\   |  __ \|  ____|  __ \|  _ \ / __ \   /\   |  __ \|  __ \ 
	 | |    | |__     /  \  | |  | | |__  | |__) | |_) | |  | | /  \  | |__) | |  | |
	 | |    |  __|   / /\ \ | |  | |  __| |  _  /|  _ <| |  | |/ /\ \ |  _  /| |  | |
	 | |____| |____ / ____ \| |__| | |____| | \ \| |_) | |__| / ____ \| | \ \| |__| |
	 |______|______/_/    \_\_____/|______|_|  \_\____/ \____/_/    \_\_|  \_\_____/                                                                 
	)";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(5, 8, 85, 17);

	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(8, 9);
	cout << "STT";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 1; i < 17; i++)
	{
		Controller::GotoXY(13, 8 + i);
		putchar(179);
	}
	for (int i = 6; i < 13; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(18, 9);
	cout << "Name";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 1; i < 17; i++)
	{
		Controller::GotoXY(30, 8 + i);
		putchar(179);
	}
	for (int i = 14; i < 30; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(36, 9);
	cout << "ID";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 1; i < 17; i++)
	{
		Controller::GotoXY(45, 8 + i);
		putchar(179);
	}
	for (int i = 31; i < 45; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(52, 9);
	cout << "Class";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 1; i < 17; i++)
	{
		Controller::GotoXY(62, 8 + i);
		putchar(179);
	}
	for (int i = 46; i < 62; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(68, 9);
	cout << "Level";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 1; i < 17; i++)
	{
		Controller::GotoXY(78, 8 + i);
		putchar(179);
	}
	for (int i = 63; i < 78; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}

	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(82, 9);
	cout << "Score";
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 79; i < 91; i++)
	{
		Controller::GotoXY(i, 10);
		putchar(196);
	}
	int y = 11;
	int lines = 8;
	int n = 0;
	/*string tmp;
	fstream fs("rank\\leaderboard.txt", ios::in);

	while (!fs.eof()) {
		getline(fs, p[n].playerName);
		getline(fs, p[n].playerID);
		getline(fs, p[n].className);
		getline(fs, p[n].mode);
		fs >> p[n].score;
		fs.ignore();
		n++;
	}
	fs.close();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[j].score > p[i].score) {
				swap(p[i], p[j]);
			}
		}
	}
	for (int i = 1; i < lines; i++) {
		Controller::GotoXY(9, y);
		cout << i;
		Controller::GotoXY(16, y);
		cout << p[i - 1].playerName;
		Controller::GotoXY(33, y);
		cout << p[i - 1].playerID;
		Controller::GotoXY(50, y);
		cout << p[i - 1].className;
		Controller::GotoXY(68, y);
		cout << p[i - 1].mode;
		Controller::GotoXY(84, y);
		cout << p[i - 1].score;
		y += 2;
	}*/

	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(45, 27, 8, 2);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::GotoXY(43, 28);
	putchar(175);
	Controller::GotoXY(48, 28);
	cout << "Back";
	Controller::GotoXY(56, 28);
	putchar(174);

	Controller::GotoXY(45, 30);
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	system("pause");
	Controller::ClearConsole();
	Menu::MainMenu();
}


void Menu::PlayGame() {
	Game g(_EASY);
	g.SetUpGame();
	g.StartGame();
}
void Menu::LoadGame() {
	Game g;
	g.LoadGame();
}