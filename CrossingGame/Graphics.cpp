#include "Graphics.h";
void Graphics::PrintInterface() {
	Controller::ClearConsole();
	DrawMap();
	PrintInstruct();
	PrintInfo();
}
void Graphics::DrawMenuBox() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 40; i < 83; i++) {
		Controller::GotoXY(i, 11);
		putchar(178);
		Controller::GotoXY(i, 23);
		putchar(178);
	}
	for (int i = 11; i < 24; i++)
	{
		Controller::GotoXY(40, i);
		putchar(219);
		Controller::GotoXY(82, i);
		putchar(219);
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
	Controller::GotoXY(7, 2); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE); cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 3); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE); cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 4); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_GREEN); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 5); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 6); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 7); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |\n";
	Controller::GotoXY(5, 7); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 8); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA);
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
	Controller::GotoXY(69, 28); cout << "============================";

	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	Controller::GotoXY(53, 24); cout << "    ||     ||     ";
	Controller::GotoXY(53, 25); cout << "   |  |___|  |    ";
	Controller::GotoXY(53, 26); cout << "  [    |_|    ]    ";
	Controller::GotoXY(53, 27); cout << " [_____________]   ";
	Controller::GotoXY(53, 28); cout << "[_______________]";
	Controller::GotoXY(53, 29); cout << "    ||     ||       ";
}
void Graphics::PrintInstruct() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	DrawRectangle(79, 14, 14, 2);
	DrawRectangle(98, 14, 14, 2);
	DrawRectangle(79, 17, 14, 2);
	DrawRectangle(98, 17, 14, 2);

	Controller::SetConsoleColor(BRIGHT_WHITE, PURPLE);
	Controller::GotoXY(83, 15);
	cout << "L : Save";
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::GotoXY(102, 15);
	cout << "H : Help";
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Controller::GotoXY(83, 18);
	cout << "P : Pause";
	Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
	Controller::GotoXY(101, 18);
	cout << "Esc : Exit";
}

void Graphics::DrawMap() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	int left = 4, top = 5, size = 8;
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

	for (int j = 1; j <= 3; j++) {
		Controller::GotoXY(left + 2, j + top);
		for (int i = 1; i < size * 8; i++)
		{
			Sleep(5);
			if (i % 2 == 0 && j % 2 == 0)
				putchar(178);
			else if(i % 2 != 0 && j % 2 != 0)
				putchar(178);
			else
				putchar(176);
		}
	}
}

void Graphics::PrintInfo() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	DrawRectangle(79, 3, 33, 10);
	DrawRectangle(80, 4, 31, 2);
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	Controller::GotoXY(87, 5);
	cout << "PLAYER'S INFORMATION";	
}

void draw_bye1() {
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
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
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_GREEN);
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

void Graphics::DrawGoodbyeScreen() {
	Controller::ClearConsole();
	Sleep(500);
	const char rocket[] = R"(       
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
	Controller::GotoXY(7, 101); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE); cout << "_______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	Controller::GotoXY(5, 102); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);  cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	Controller::GotoXY(5, 103); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_GREEN); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	Controller::GotoXY(5, 104); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	Controller::GotoXY(5, 105); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	Controller::GotoXY(5, 106); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	Controller::GotoXY(5, 107); Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";

	Controller::GotoXY(43, 109);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA);
	printf("CSC10003 - OBJECT ORIENTED PROGRAMMING");
	Controller::GotoXY(53, 110);
	cout << "GAME: CROSSING GAME";
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED);
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
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << " SEE YOU AGAIN ";
	Controller::GotoXY(68, 116);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED);
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
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << rocket;
	Controller::GotoXY(0, 85);
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	cout << fire;
	Controller::GotoXY(0, 0);	cout << " ";
	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_AQUA);
	int rocketSpeed = 300;
	Sound s;
	s.EndSoundGame();
	s.SoundRocket();
	for (int i = 0; i < 63; i++) {
		Sleep(rocketSpeed); // move faster and faster,
		rocketSpeed -= 30; // so sleep less each time
		if (rocketSpeed <= 40)
			rocketSpeed = 40;
		Controller::GotoXY(0, 66 + i);
		cout << " "; // move rocket a line upward
	}
	s.EndSoundGame();
	Sleep(200);
	s.SoundByeBye();
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	Sleep(1500);
	Controller::GotoXY(0, 122);
	exit(0);
}
void Graphics::PrintLevel(int level) {
	const char levelASCII[] = R"(  
			  _             _ 
			 | |_____ _____| |
			 | / -_) V / -_) |
			 |_\___|\_/\___|_|
)";
	
	Controller::GotoXY(0, 0);
	cout << levelASCII;
	if (level == 1) {
		Controller::GotoXY(45, 1); cout << " _";
		Controller::GotoXY(45, 2); cout << "/ |";
		Controller::GotoXY(45, 3); cout << "| |";
		Controller::GotoXY(45, 4); cout << "|_|";
	}
	else if (level == 2) {
		Controller::GotoXY(45, 1); cout << " ___ ";
		Controller::GotoXY(45, 2); cout << "|_  )";
		Controller::GotoXY(45, 3); cout << " / / ";
		Controller::GotoXY(45, 4); cout << "/___|";
	}
	else if (level == 3) {
		Controller::GotoXY(45, 1); cout << " ____";
		Controller::GotoXY(45, 2); cout << "|__ /";
		Controller::GotoXY(45, 3); cout << " |_ \\";
		Controller::GotoXY(45, 4); cout << "|___/ ";
	}
	else if (level == 4) {
		Controller::GotoXY(45, 1); cout << " _ _ ";
		Controller::GotoXY(45, 2); cout << "| | | ";
		Controller::GotoXY(45, 3); cout << "|_  _|";
		Controller::GotoXY(45, 4); cout << "  |_| ";
	}
	else if (level == 5) {
		Controller::GotoXY(45, 1); cout << " ___ ";
		Controller::GotoXY(45, 2); cout << "| __| ";
		Controller::GotoXY(45, 3); cout << "|__ \\ ";
		Controller::GotoXY(45, 4); cout << "|___/ ";
	}
	else {
		return;
	}
}