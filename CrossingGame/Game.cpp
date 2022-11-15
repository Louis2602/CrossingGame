#include "Game.h";

Game::Game(int _level) {
	level = _level;
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
}
void Game::renderLight() {
	while (IS_RUNNING) {
		// Green
		mLight.spawn_light(70, 7);
		mLight.spawn_light(70, 11);
		mLight.spawn_light(70, 15);
		mLight.spawn_light(70, 19);
		mLight.setTimer(50);
		// Red
		mLight.spawn_light(70, 7);
		mLight.spawn_light(70, 11);
		mLight.spawn_light(70, 15);
		mLight.spawn_light(70, 19);
		mLight.setTimer(30);
	}
}
void Game::SetUpGame() {
	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	Controller::ClearConsole();
	Controller::GotoXY(0, 0);
	Graphics::LoadBackground();
	Controller::ShowCursor(true);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::GotoXY(35, 12);
	cout << "Please enter your name shortly, under 10 characters!";

	Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	Controller::GotoXY(45, 15);
	cout << "Enter your name:  ";
	cin.getline(playerName, 15);
	Controller::GotoXY(45, 17);
	cout << "Enter your ID:  ";
	cin.getline(playerID, 9);
	Controller::GotoXY(45, 19);
	cout << "Enter your class's name:  ";
	cin.getline(className, 8);
	Controller::ShowCursor(false);
}
void Game::StartGame() {
	Graphics::PrintInterface();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(85, 5);
	if (strlen(playerName) != 0)
		cout << "Player's name: " << playerName;
	else {
		strcpy_s(playerName, "unknown");
		cout << "Player's name: " << playerName;
	}
	Controller::GotoXY(85, 7);
	if (strlen(playerID) != 0)
		cout << "Student's ID: " << playerID;
	else {
		strcpy_s(playerID, "unknown");
		cout << "Student's ID: " << playerID;
	}
	Controller::GotoXY(85, 9);
	if (strlen(className) != 0)
		cout << "Class: " << className;
	else {
		strcpy_s(className, "unknown");
		cout << "Class: " << className;
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(89, 16);
	cout << "Current score:";
	thread light;
	thread Object;

	thread mainGame([&] {playGame(light, Object); });

	mainGame.join();
}
void Game::playGame(thread& tL, thread& tO) {
	tL = thread([&] {renderLight(); });
	tO = thread([&] {renderObject(); });

	while (!PAUSE_STATE && mPeople.isDead() && IS_RUNNING) {
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		Controller::GotoXY(104, 16);
		cout << mPeople.getScore();
		mtx.unlock();
		int x = mPeople.getPosX();
		int y = mPeople.getPosY();
		if (mPeople.isFinish(x))
		{
			mPeople.updatePos(36, 24);
		}
		else
		{
			mPeople.DRAW_PEOPLE(mPeople.getPosX(), mPeople.getPosY());
			switch (Controller::GetConsoleInput()) {
			case 1:  //ESC	
				IS_RUNNING = false;
				mLight.setisPlay(false);
				Graphics::DrawGoodbyeScreen();
				break;
			case 2: //UP
			{
				mPeople.Delete(x, y);
				mPeople.Up(y);
				break;
			}
			case 3: //LEFT
			{
				mPeople.Delete(x, y);
				mPeople.Left(x);
				break;
			}
			case 4: //RIGHT
			{
				mPeople.Delete(x, y);
				mPeople.Right(x);
				break;
			}
			case 5: //DOWN
			{
				mPeople.Delete(x, y);
				mPeople.Down(y);
				break;
			}
			case 7: //PAUSE GAME
				mLight.setisPlay(false);
				PAUSE_STATE = true;
				break;

			case 8: // SAVE GAME
				mLight.setisPlay(false);
				SAVE_GAME = true;
				break;
			}
			mPeople.updatePos(x, y);
		}
		if (PAUSE_STATE) {
			mtx.lock();
			askContinue();
			mtx.unlock();
		}
		if (SAVE_GAME) {
			mtx.lock();
			SaveGame();
			mtx.unlock();
		}
	}
	tL.join();
	tO.join();
	Graphics::DrawGoodbyeScreen();
}
void Game::EndGame(thread* game) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	game->join();
	Graphics::DrawGoodbyeScreen();
}

void Game::SaveGame() //Save game
{
	askSaveGame();
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(50, 15);
	Controller::ShowCursor(true);
	cout << "Enter a filename: ";
	cin >> filename;
	Controller::ShowCursor(false);
	filename = "gameData\\" + filename + ".txt";
	fstream fs(filename, ios::app);
	if (SAVE_GAME) {
		fs << playerName << '\n' << playerID << '\n' << className << '\n' << mPeople.getScore() << '\n';
	}
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Controller::GotoXY(40, 17);
	cout << "---------Save game successfully---------";
	Sleep(1000);
	fs.close();
	IS_RUNNING = false;
}

void Game::askContinue() //ask player to continue or not when pause game
{
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(0, 0);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(44, 13, 35, 8);
	Graphics::DrawRectangle(47, 18, 7, 2);
	Graphics::DrawRectangle(70, 18, 6, 2);
	Controller::GotoXY(51, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to continue?";
	string str[2] = { "Yes", "No" };
	int left[] = { 45,50,57,68,73,79 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			mSound.PlayerMove();
			Controller::SetConsoleColor(BRIGHT_WHITE, color[i]);
			Controller::GotoXY(left[choice * 3], top);        putchar(word[i * 2]);
			Controller::GotoXY(left[choice * 3 + 1], top);    cout << str[choice];
			Controller::GotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = Controller::GetConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				IS_RUNNING = true;
				PAUSE_STATE = false;
			}
			else {
				IS_RUNNING = false;
				PAUSE_STATE = true;
				SAVE_GAME = true;
			}
			return;
		}
		else
			mSound.PlayerMove();
	}
}
void Game::askSaveGame()
{
	Controller::ClearConsole();
	Graphics::LoadBackground();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(0, 0);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(44, 13, 35, 8);
	Graphics::DrawRectangle(47, 18, 7, 2);
	Graphics::DrawRectangle(70, 18, 6, 2);
	Controller::GotoXY(51, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to save game?";
	string str[2] = { "Yes", "No" };
	int left[] = { 45,50,57,68,73,79 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			mSound.PlayerMove();
			Controller::SetConsoleColor(BRIGHT_WHITE, color[i]);
			Controller::GotoXY(left[choice * 3], top);        putchar(word[i * 2]);
			Controller::GotoXY(left[choice * 3 + 1], top);    cout << str[choice];
			Controller::GotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = Controller::GetConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				SAVE_GAME = true;
				IS_RUNNING = true;
			}
			else {
				SAVE_GAME = false;
				IS_RUNNING = false;
			}
			return;
		}
		else
			mSound.PlayerMove();
	}
}

void Game::renderObject() {
	int dx = -6, dy = 4;

	//cLine* line1;
	cLine* line2;
	cLine* line3;
	cLine* line4;
	cLine* line5;
	//cLine* line6;
	//line1 = new cLine;
	line2 = new cLine;
	line3 = new cLine;
	line4 = new cLine;
	line5 = new cLine;
	//line6 = new cLine;


	int t2 = 0;
	int t3 = 0;
	int t4 = 0;
	int t5 = 0;

	while (IS_RUNNING) {
		if (t2 % 15 && line2->getLight()) {
			//cPoint pos1(dx - t * 15, dy);
			cPoint pos2(dx - t2 * 15, dy + 4);
			/*cPoint pos3(dx - t3 * 15, dy + 4 * 2);
			cPoint pos4(dx - t4 * 15, dy + 4 * 3);
			cPoint pos5(dx - t5 * 15, dy + 4 * 4);*/
			//cPoint pos6(dx - t * 15, dy + 4 * 5);

			//COBJECT* car1;
			COBJECT* car2;
			/*COBJECT* car3;
			COBJECT* car4;
			COBJECT* car5;*/
			//COBJECT* car6;

			//car1 = new cCar(pos1);
			car2 = new CBIRD(pos2);
			//car3 = new cCar(pos3);
			//car4 = new cTruck(pos4);
			//car5 = new cCar(pos5);
			//car6 = new cTruck(pos6);

			//line1->pushObject(car1);
			line2->pushObject(car2);
			//line3->pushObject(car3);
			//line4->pushObject(car4);
			//line5->pushObject(car5);
			//line6->pushObject(car6);
		}

		if (t3 % 15 && line3->getLight()) {
			cPoint pos3(dx - t3 * 15, dy + 4 * 2);

			COBJECT* car3;

			car3 = new cCar(pos3);

			line3->pushObject(car3);
		}

		if (t4 % 15 && line4->getLight()) {
			cPoint pos4(dx - t4 * 15, dy + 4 * 3);

			COBJECT* car4;

			car4 = new cTruck(pos4);

			line4->pushObject(car4);
		}

		if (t5 % 15 && line5->getLight()) {
			cPoint pos5(dx - t5 * 15, dy + 4 * 4);

			COBJECT* car5;

			car5 = new CDINO(pos5);

			line5->pushObject(car5);
		}

		line2->changeLight(mLight.getState());
		line3->changeLight(mLight.getState());
		line4->changeLight(mLight.getState());
		line5->changeLight(mLight.getState());

		if (line2->getLight()) {
			//line1->nextMove();
			line2->nextMove();
			t2++;
			/*line3->nextMove();
			line4->nextMove();
			line5->nextMove();*/
			//line6->nextMove();
		}

		if (line3->getLight()) {
			line3->nextMove();
			t3++;
		}

		if (line4->getLight()) {
			line4->nextMove();
			t4++;
		}

		if (line5->getLight()) {
			line5->nextMove();
			t5++;
		}
		Sleep(100);
	}
}