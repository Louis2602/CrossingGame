#include "Menu.h";

void Menu::MainMenu() {
	Graphics::LoadBackground();
	Graphics::DrawMenuBox();
	Controller::GotoXY(43, 12);
	Controller::TextColor(LIGHT_AQUA);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	Controller::GotoXY(53, 13);
	cout << "GAME: CROSSING GAME";
	int idx = 15, idx_t = 15;
	Controller::GotoXY(53, idx);
	Controller::TextColor(LIGHT_YELLOW);
	cout << (char)175;
	Controller::GotoXY(56, 15);
	cout << "Play    " << endl;
	Controller::GotoXY(56, 16);
	Controller::TextColor(WHITE);
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
		Controller::TextColor(LIGHT_AQUA);
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
		Controller::TextColor(LIGHT_YELLOW);
		cout << (char)175;
		Controller::GotoXY(56, 15);
		Controller::TextColor(WHITE);
		if (idx == 15)
			Controller::TextColor(14);
		cout << "Play" << endl;
		Controller::GotoXY(56, 16);
		Controller::TextColor(WHITE);
		if (idx == 16)
			Controller::TextColor(LIGHT_YELLOW);
		cout << "Rule" << endl;
		Controller::GotoXY(56, 17);
		Controller::TextColor(WHITE);
		if (idx == 17)
			Controller::TextColor(LIGHT_YELLOW);
		cout << "About" << endl;
		Controller::GotoXY(56, 18);
		Controller::TextColor(WHITE);
		if (idx == 18)
			Controller::TextColor(LIGHT_YELLOW);
		cout << "Score" << endl;
		Controller::TextColor(WHITE);
		if (idx == 19)
			Controller::TextColor(LIGHT_YELLOW);
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

void Menu::MenuGameplay() {
	int idx = 15, idx_t = 15;
	Controller::GotoXY(53, idx);
	Controller::TextColor(LIGHT_YELLOW);
	cout << (char)175;
	Controller::GotoXY(56, 15);
	cout << "New Game  " << endl;
	Controller::GotoXY(56, 16);
	Controller::TextColor(WHITE);
	cout << "Load Game" << endl;
	Controller::GotoXY(56, 17);
	cout << "Settings " << endl;
	Controller::GotoXY(56, 18);
	cout << "                 " << endl;
	Controller::GotoXY(56, 19);
	cout << "                 " << endl;

	while (true)
	{
		char s = toupper(_getch());
		Controller::TextColor(LIGHT_AQUA);
		idx_t = idx;
		if (s == 'W' || s == 72)
			idx--;
		else
			if (s == 'S' || s == 80)
				idx++;
		if (idx > 17)
			idx = 15;
		else
			if (idx < 15)
				idx = 17;
		Controller::GotoXY(53, idx_t);
		cout << "  ";
		Controller::GotoXY(53, idx);
		Controller::TextColor(LIGHT_YELLOW);
		cout << (char)175;
		Controller::GotoXY(56, 15);
		Controller::TextColor(WHITE);
		if (idx == 15)
			Controller::TextColor(14);
		cout << "New Game" << endl;
		Controller::GotoXY(56, 16);
		Controller::TextColor(WHITE);
		if (idx == 16)
			Controller::TextColor(LIGHT_YELLOW);
		cout << "Load Game" << endl;
		Controller::GotoXY(56, 17);
		Controller::TextColor(WHITE);
		if (idx == 17)
			Controller::TextColor(LIGHT_YELLOW);
		cout << "Settings" << endl;
		Controller::TextColor(WHITE);

		if (s == 13)	//press Enter
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
		Continue = true;
		//Game::PlayGame();
		break;
	case 3:
		Menu::MainMenu();
		break;
	}
}

void Menu::MenuRule() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(50, 13);
	Controller::SetColor(WHITE);	cout << "FUNCTION KEYS";

	Controller::GotoXY(48, 15);
	Controller::SetColor(14);	cout << " L  :";
	Controller::SetColor(AQUA);	cout << "   Save game";
	Controller::GotoXY(48, 16);
	Controller::SetColor(14);	cout << " P  :";
	Controller::SetColor(AQUA);	cout << "   Pause game";
	Controller::GotoXY(48, 17);
	Controller::SetColor(14);	cout << "Esc :";
	Controller::SetColor(AQUA);	cout << "   Exit";
	Controller::GotoXY(45, 19);
	Controller::SetColor(RED);	cout << "Cross the road and dodge";
	Controller::GotoXY(45, 20); cout << "obstacles (cars & animals)";



	Controller::GotoXY(78, 13);
	Controller::SetColor(WHITE);	cout << "MOVE";

	Controller::GotoXY(75, 15);
	Controller::SetColor(LIGHT_YELLOW);	cout << "     W   ";

	Controller::GotoXY(75, 16);
	Controller::SetColor(LIGHT_BLUE);	cout << "     ^";

	Controller::GotoXY(75, 17);
	Controller::SetColor(LIGHT_YELLOW);	cout << " A ";

	Controller::GotoXY(78, 17);
	Controller::SetColor(LIGHT_BLUE);	cout << "<   >";

	Controller::GotoXY(80, 17);
	Controller::SetColor(RED);	cout << "O";

	Controller::GotoXY(84, 17);
	Controller::SetColor(LIGHT_YELLOW);	cout << "D";

	Controller::GotoXY(75, 18);
	Controller::SetColor(LIGHT_BLUE);	cout << "     v   ";

	Controller::GotoXY(75, 19);
	Controller::SetColor(LIGHT_YELLOW);	cout << "     S";
	Controller::SetColor(LIGHT_YELLOW);

	Controller::TextColor(17);
	char c = 219;
	for (int i = 13; i < 22; i++) {
		Controller::GotoXY(72, i);
		cout << c;
		Controller::GotoXY(88, i);
		cout << c;
	}
	Controller::TextColor(LIGHT_AQUA);
	Controller::SetColor(BLACK);
	Controller::GotoXY(44, 23);
	system("pause");
	Controller::ClearConsole();
	Menu::MainMenu();
}

void Menu::MenuAbout() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(40, 12);
	Controller::SetColor(LIGHT_YELLOW);
	printf("  GV Huong Dan:                                       ");
	Controller::GotoXY(41, 13);
	Controller::SetColor(WHITE);
	printf("     - Truong Toan Thinh                        ");
	Controller::GotoXY(41, 14);
	Controller::SetColor(LIGHT_YELLOW);
	printf(" Code by:                                          ");
	Controller::GotoXY(41, 15);
	Controller::SetColor(WHITE);
	printf("     - 21127337: Tran Tung Lam                 ");
	Controller::GotoXY(41, 16);
	printf("     - 21127337: Tran Tung Lam                    ");
	Controller::GotoXY(41, 17);
	printf("     - 21127337: Tran Tung Lam                    ");
	Controller::GotoXY(41, 18);
	printf("     - 21127337: Tran Tung Lam                    ");
	Controller::GotoXY(41, 19);
	printf("                                                     ");
	Controller::GotoXY(40, 21);
	Controller::SetColor(LIGHT_BLUE);
	printf("  HCMUS _ Ho Chi Minh University of Sience.");
	Controller::GotoXY(59, 22);
	cout << "2022-2023";
	Controller::GotoXY(45, 23);
	Controller::SetColor(BLACK);
	system("pause");
	Controller::ClearConsole();
	Menu::MainMenu();
}

void Menu::MenuScore() {
	Controller::ClearConsole();
}

void draw_bye1() {
	Controller::SetColor(LIGHT_GREEN);
	Controller::GotoXY(20, 113);
	cout << " ____ ";
	Controller::GotoXY(20, 114);
	cout << "|  _ \\                        ";
	Controller::GotoXY(20, 115);
	cout << "| |_)|  __  __ ____";
	Controller::GotoXY(20, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	Controller::GotoXY(20, 117);
	cout << "| |__)|  \\  / | ___/";
	Controller::GotoXY(20, 118);
	cout << "|_____/  /_/  \\____|";
}
void draw_bye2() {
	Controller::SetColor(LIGHT_GREEN);
	Controller::GotoXY(82, 113);
	cout << " ____ ";
	Controller::GotoXY(82, 114);
	cout << "|  _ \\                        ";
	Controller::GotoXY(82, 115);
	cout << "| |_)|  __  __ ____";
	Controller::GotoXY(82, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	Controller::GotoXY(82, 117);
	cout << "| |__)|  \\  / | ___/";
	Controller::GotoXY(82, 118);
	cout << "|_____/  /_/  \\____|";
}

void Menu::MenuQuitGame() {
	Controller::ClearConsole();
	const char rocket[] =R"(       
							   !
							   !
							   ^
							  / \
							 /___\
							|=   =|
							|  B  |
							|  Y  |
							|  E  |
							|     |
							|  B  |
							|  Y  |
							|  E  |
							|     |
						       /|##!##|\
						      / |##!##| \
						     /  |##!##|  \
						    |  / ^ | ^ \  |
						    | /         \ |
						    |/           \|
)";
	
	const char fire[] = R"(
							 ( | )  
							 ( | ) 
							((   ))
						       ((  :  ))
						       ((  :  ))
							((   ))
							 (( ))
							  ( )
							   .
							   .
							   .
)";
	Controller::GotoXY(7, 101); Controller::TextColor(LIGHT_BLUE);   cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 102); Controller::TextColor(LIGHT_BLUE);  cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 103); Controller::TextColor(LIGHT_GREEN); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 104); Controller::TextColor(LIGHT_AQUA); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 105); Controller::TextColor(LIGHT_RED); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 106); Controller::TextColor(LIGHT_PURPLE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 107); Controller::TextColor(LIGHT_PURPLE); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	Controller::GotoXY(43, 109);
	Controller::TextColor(LIGHT_AQUA);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	Controller::GotoXY(53, 110);
	cout << "GAME: CROSSING GAME";
	Controller::SetColor(LIGHT_RED);
	Controller::GotoXY(49, 112);
	cout << "  *******     *******";
	Controller::GotoXY(49, 113);
	cout << " *       *   *       *";
	Controller::GotoXY(49, 114);
	cout << "*         ***         *";
	Controller::GotoXY(49, 115);
	cout << " *                   *";
	Controller::GotoXY(49, 116);
	cout << "  *";
	Controller::GotoXY(53, 116);
	Controller::SetColor(LIGHT_YELLOW);
	cout << " SEE YOU AGAIN ";
	Controller::GotoXY(68, 116);
	Controller::SetColor(LIGHT_RED);
	cout << " *";
	Controller::GotoXY(49, 117);
	cout << "    *             *";
	Controller::GotoXY(49, 118);
	cout << "      *         *";
	Controller::GotoXY(49, 119);
	cout << "        *     *";
	Controller::GotoXY(49, 120);
	cout << "          ***";
	Controller::GotoXY(49, 121);

	draw_bye1();
	draw_bye2();

	Controller::GotoXY(0, 67);
	Controller::TextColor(LIGHT_YELLOW);
	cout << rocket;
	Controller::GotoXY(0, 85);
	Controller::TextColor(LIGHT_RED);
	cout << fire;
	Controller::GotoXY(0, 0);	cout << " ";
	Controller::TextColor(LIGHT_AQUA);
	int rocketSpeed = 300;
	Sound::EndSoundGame();
	Sound::SoundRocket();
	for (int i = 0; i < 63; i++) {
		Sleep(rocketSpeed); // move faster and faster,
		rocketSpeed -= 30; // so sleep less each time
		if (rocketSpeed <= 40)
			rocketSpeed = 40;
		Controller::GotoXY(0, 66 + i);
		printf(" "); // move rocket a line upward
	}
	Sound::EndSoundGame();
	Sleep(200);
	Sound::SoundByeBye();
	Controller::SetColor(BLACK);
	Sleep(1500);
	Controller::GotoXY(0, 122);
	exit(0);
}

void Menu::PlayGame() {
	Game g(_EASY);
	g.StartGame();
}