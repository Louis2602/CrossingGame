#include "Header.h";

void MenuGameplay() {
	int idx = 15, idx_t = 15;
	GotoXY(53, idx);
	TextColor(14);
	cout << (char)175;
	GotoXY(56, 15);
	cout << "New Game  " << endl;
	GotoXY(56, 16);
	TextColor(7);
	cout << "Load Game" << endl;
	GotoXY(56, 17);
	cout << "Settings " << endl;
	GotoXY(56, 18);
	cout << "                 " << endl;
	GotoXY(56, 19);
	cout << "                 " << endl;

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
		if (idx > 17)
			idx = 15;
		else
			if (idx < 15)
				idx = 17;
		GotoXY(53, idx_t);
		cout << "  ";
		GotoXY(53, idx);
		TextColor(14);
		cout << (char)175;
		GotoXY(56, 15);
		TextColor(7);
		if (idx == 15)
			TextColor(14);
		cout << "New Game" << endl;
		GotoXY(56, 16);
		TextColor(7);
		if (idx == 16)
			TextColor(14);
		cout << "Load Game" << endl;
		GotoXY(56, 17);
		TextColor(7);
		if (idx == 17)
			TextColor(14);
		cout << "Settings" << endl;
		TextColor(7);

		if (s == 13)	//press Enter
		{
			idx -= 14;
			break;
		}
	}
	switch (idx)
	{
	case 1:
		Round = 1;
		//PlayGame();
		break;
	case 2:
		//FlatContinue = true;
		//PlayGame();
		break;
	case 3:
		Menu();
		break;
	}
}

void MenuRule() {
	ClearConsole();
	LoadBackground();
	GotoXY(50, 13);
	SetColor(7);	cout << "FUNCTION KEYS";

	GotoXY(48, 15);
	SetColor(14);	cout << " L  :";
	SetColor(3);	cout << "   Save game";
	GotoXY(48, 16);
	SetColor(14);	cout << " P  :";
	SetColor(3);	cout << "   Pause game";
	GotoXY(48, 17);
	SetColor(14);	cout << "Esc :";
	SetColor(3);	cout << "   Exit";
	GotoXY(45, 19);
	SetColor(4);	cout << "Cross the road and dodge";
	GotoXY(45, 20); cout << "obstacles (cars & animals)";



	GotoXY(78, 13);
	SetColor(7);	cout << "MOVE";

	GotoXY(75, 15);
	SetColor(14);	cout << "     W   ";

	GotoXY(75, 16);
	SetColor(9);	cout << "     ^";

	GotoXY(75, 17);
	SetColor(14);	cout << " A ";

	GotoXY(78, 17);
	SetColor(9);	cout << "<   >";

	GotoXY(80, 17);
	SetColor(4);	cout << "O";

	GotoXY(84, 17);
	SetColor(14);	cout << "D";

	GotoXY(75, 18);
	SetColor(9);	cout << "     v   ";

	GotoXY(75, 19);
	SetColor(14);	cout << "     S";
	SetColor(14);

	TextColor(17);
	char c = 219;
	for (int i = 13; i < 22; i++) {
		GotoXY(72, i);
		cout << c;
		GotoXY(88, i);
		cout << c;
	}
	TextColor(11);
	SetColor(0);
	GotoXY(44, 23);
	system("pause");
	ClearConsole();
	Menu();
}

void MenuAbout() {
	ClearConsole();
	LoadBackground();
	GotoXY(40, 12);
	SetColor(14);
	printf("  GV Huong Dan:                                       ");
	GotoXY(41, 13);
	SetColor(7);
	printf("     - Truong Toan Thinh                        ");
	GotoXY(41, 14);
	SetColor(14);
	printf(" Code by:                                          ");
	GotoXY(41, 15);
	SetColor(7);
	printf("     - 21127337: Tran Tung Lam                 ");
	GotoXY(41, 16);
	printf("     - 21127337: Tran Tung Lam                    ");
	GotoXY(41, 17);
	printf("     - 21127337: Tran Tung Lam                    ");
	GotoXY(41, 18);
	printf("     - 21127337: Tran Tung Lam                    ");
	GotoXY(41, 19);
	printf("                                                     ");
	GotoXY(40, 21);
	SetColor(9);
	printf("  HCMUS _ Ho Chi Minh University of Sience.");
	GotoXY(59, 22);
	cout << "2022-2023";
	GotoXY(45, 23);
	SetColor(0);
	system("pause");
	ClearConsole();
	Menu();
}

void MenuScore() {
	ClearConsole();
}

void draw_bye1() {
	SetColor(10);
	GotoXY(20, 113);
	cout << " ____ ";
	GotoXY(20, 114);
	cout << "|  _ \\                        ";
	GotoXY(20, 115);
	cout << "| |_)|  __  __ ____";
	GotoXY(20, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	GotoXY(20, 117);
	cout << "| |__)|  \\  / | ___/";
	GotoXY(20, 118);
	cout << "|_____/  /_/  \\____|";
}
void draw_bye2() {
	SetColor(10);
	GotoXY(82, 113);
	cout << " ____ ";
	GotoXY(82, 114);
	cout << "|  _ \\                        ";
	GotoXY(82, 115);
	cout << "| |_)|  __  __ ____";
	GotoXY(82, 116);
	cout << "|  __`\\ \\ \\/ // __ \\";
	GotoXY(82, 117);
	cout << "| |__)|  \\  / | ___/";
	GotoXY(82, 118);
	cout << "|_____/  /_/  \\____|";
}

void MenuQuitGame() {
	ClearConsole();
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
	GotoXY(7, 99); TextColor(9);   cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	GotoXY(5, 100); TextColor(9);  cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	GotoXY(5, 101); TextColor(10); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	GotoXY(5, 102); TextColor(11); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	GotoXY(5, 103); TextColor(12); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	GotoXY(5, 104); TextColor(13); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	GotoXY(5, 105); TextColor(13); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	GotoXY(43, 108);
	TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	GotoXY(53, 109);
	cout << "GAME: CROSSING GAME";
	SetColor(12);
	GotoXY(49, 112);
	cout << "  *******     *******";
	GotoXY(49, 113);
	cout << " *       *   *       *";
	GotoXY(49, 114);
	cout << "*         ***         *";
	GotoXY(49, 115);
	cout << " *                   *";
	GotoXY(49, 116);
	cout << "  *";
	GotoXY(53, 116);
	SetColor(14);
	cout << " SEE YOU AGAIN ";
	GotoXY(68, 116);
	SetColor(12);
	cout << " *";
	GotoXY(49, 117);
	cout << "    *             *";
	GotoXY(49, 118);
	cout << "      *         *";
	GotoXY(49, 119);
	cout << "        *     *";
	GotoXY(49, 120);
	cout << "          ***";
	GotoXY(49, 121);

	draw_bye1();
	draw_bye2();

	GotoXY(0, 67);
	TextColor(14);
	cout << rocket;
	GotoXY(0, 85);
	TextColor(12);
	cout << fire;
	GotoXY(0, 0);	cout << " ";
	TextColor(11);
	int rocketSpeed = 300;
	EndSoundGame();
	SoundRocket();
	for (int i = 0; i < 63; i++) {
		Sleep(rocketSpeed); // move faster and faster,
		rocketSpeed -= 30; // so sleep less each time
		if (rocketSpeed <= 40)
			rocketSpeed = 40;
		GotoXY(0, 66 + i);
		printf(" "); // move rocket a line upward
	}
	EndSoundGame();
	Sleep(200);
	SoundByeBye();
	SetColor(0);
	Sleep(1500);
	GotoXY(0, 122);
	exit(0);
}