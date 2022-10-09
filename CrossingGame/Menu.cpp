#include "Menu.h"

void Menu::MenuGameplay(int Round) {
	int idx = 15, idx_t = 15;
	Controller::Controller::GotoXY(53, idx);
	Controller::Controller::Controller::TextColor(14);
	cout << (char)175;
	Controller::Controller::GotoXY(56, 15);
	cout << "New Game  " << endl;
	Controller::Controller::GotoXY(56, 16);
	Controller::Controller::Controller::TextColor(7);
	cout << "Load Game" << endl;
	Controller::Controller::GotoXY(56, 17);
	cout << "Settings " << endl;
	Controller::Controller::GotoXY(56, 18);
	cout << "                 " << endl;
	Controller::Controller::GotoXY(56, 19);
	cout << "                 " << endl;

	while (true)
	{
		char s = toupper(_getch());
		Controller::Controller::Controller::TextColor(11);
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
		Controller::Controller::GotoXY(53, idx_t);
		cout << "  ";
		Controller::Controller::GotoXY(53, idx);
		Controller::Controller::Controller::TextColor(14);
		cout << (char)175;
		Controller::Controller::GotoXY(56, 15);
		Controller::Controller::Controller::TextColor(7);
		if (idx == 15)
			Controller::Controller::Controller::TextColor(14);
		cout << "New Game" << endl;
		Controller::Controller::GotoXY(56, 16);
		Controller::Controller::Controller::TextColor(7);
		if (idx == 16)
			Controller::Controller::Controller::TextColor(14);
		cout << "Load Game" << endl;
		Controller::Controller::GotoXY(56, 17);
		Controller::Controller::Controller::TextColor(7);
		if (idx == 17)
			Controller::Controller::Controller::TextColor(14);
		cout << "Settings" << endl;
		Controller::Controller::Controller::TextColor(7);

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
		Graphics::Menu(Round);
		break;
	}
}

void Menu::MenuRule(int Round) {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(50, 13);
	Controller::SetColor(7);	cout << "FUNCTION KEYS";

	Controller::GotoXY(48, 15);
	Controller::SetColor(14);	cout << " L  :";
	Controller::SetColor(3);	cout << "   Save game";
	Controller::GotoXY(48, 16);
	Controller::SetColor(14);	cout << " P  :";
	Controller::SetColor(3);	cout << "   Pause game";
	Controller::GotoXY(48, 17);
	Controller::SetColor(14);	cout << "Esc :";
	Controller::SetColor(3);	cout << "   Exit";
	Controller::GotoXY(45, 19);
	Controller::SetColor(4);	cout << "Cross the road and dodge";
	Controller::GotoXY(45, 20); cout << "obstacles (cars & animals)";



	Controller::GotoXY(78, 13);
	Controller::SetColor(7);	cout << "MOVE";

	Controller::GotoXY(75, 15);
	Controller::SetColor(14);	cout << "     W   ";

	Controller::GotoXY(75, 16);
	Controller::SetColor(9);	cout << "     ^";

	Controller::GotoXY(75, 17);
	Controller::SetColor(14);	cout << " A ";

	Controller::GotoXY(78, 17);
	Controller::SetColor(9);	cout << "<   >";

	Controller::GotoXY(80, 17);
	Controller::SetColor(4);	cout << "O";

	Controller::GotoXY(84, 17);
	Controller::SetColor(14);	cout << "D";

	Controller::GotoXY(75, 18);
	Controller::SetColor(9);	cout << "     v   ";

	Controller::GotoXY(75, 19);
	Controller::SetColor(14);	cout << "     S";
	Controller::SetColor(14);

	Controller::TextColor(17);
	char c = 219;
	for (int i = 13; i < 22; i++) {
		Controller::GotoXY(72, i);
		cout << c;
		Controller::GotoXY(88, i);
		cout << c;
	}
	Controller::TextColor(11);
	Controller::SetColor(0);
	Controller::GotoXY(44, 23);
	system("pause");
	Controller::ClearConsole();
	Graphics::Menu(Round);
}

void Menu::MenuAbout(int Round) {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::GotoXY(40, 12);
	Controller::SetColor(14);
	printf("  GV Huong Dan:                                       ");
	Controller::GotoXY(41, 13);
	Controller::SetColor(7);
	printf("     - Truong Toan Thinh                        ");
	Controller::GotoXY(41, 14);
	Controller::SetColor(14);
	printf(" Code by:                                          ");
	Controller::GotoXY(41, 15);
	Controller::SetColor(7);
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
	Controller::SetColor(9);
	printf("  HCMUS _ Ho Chi Minh University of Sience.");
	Controller::GotoXY(59, 22);
	cout << "2022-2023";
	Controller::GotoXY(45, 23);
	Controller::SetColor(0);
	system("pause");
	Controller::ClearConsole();
	Graphics::Menu(Round);
}

void Menu::MenuScore(int Round) {
	Controller::ClearConsole();
}

void draw_bye1() {
	Controller::SetColor(10);
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
	Controller::SetColor(10);
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
	Controller::GotoXY(7, 99); Controller::TextColor(9);   cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 100); Controller::TextColor(9);  cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 101); Controller::TextColor(10); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 102); Controller::TextColor(11); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 103); Controller::TextColor(12); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 104); Controller::TextColor(13); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 105); Controller::TextColor(13); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	Controller::GotoXY(43, 108);
	Controller::TextColor(11);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	Controller::GotoXY(53, 109);
	cout << "GAME: CROSSING GAME";
	Controller::SetColor(12);
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
	Controller::SetColor(14);
	cout << " SEE YOU AGAIN ";
	Controller::GotoXY(68, 116);
	Controller::SetColor(12);
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
	Controller::TextColor(14);
	cout << rocket;
	Controller::GotoXY(0, 85);
	Controller::TextColor(12);
	cout << fire;
	Controller::GotoXY(0, 0);	cout << " ";
	Controller::TextColor(11);
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
	Controller::SetColor(0);
	Sleep(1500);
	Controller::GotoXY(0, 122);
	exit(0);
}