#include "Game.h";

Game::Game(int _level) {
	level = _level;
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
}
void Game::renderLight() {
	Sleep(10);
	while (mLight.getState() && mLight.getisPlay()) {
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
	Controller::GotoXY(85, 7);
	if (strlen(playerName) != 0)
		cout << "Player's name: " << playerName;
	else {
		strcpy_s(playerName, "unknown");
		cout << "Player's name: " << playerName;
	}
	Controller::GotoXY(85, 9);
	if (strlen(playerID) != 0)
		cout << "Student's ID: " << playerID;
	else {
		strcpy_s(playerID, "unknown");
		cout << "Student's ID: " << playerID;
	}
	Controller::GotoXY(85, 11);
	if (strlen(className) != 0)
		cout << "Class: " << className;
	else {
		strcpy_s(className, "unknown");
		cout << "Class: " << className;
	}
	thread light;
	thread Object;

	thread mainGame([&] {playGame(light, Object); });

	mainGame.join();
	light.join();
	Object.join();
}

void Game::playGame(thread& tL, thread& tO) {
	tL = thread([this] {renderLight(); });
	tO = thread([&] {renderObject(); });
	while (!PAUSE_STATE && IS_RUNNING) {
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(10, 1);
		cout << "LEVEL: " << level;
		Controller::GotoXY(88, 1);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
		cout << mPeople.getScore();
		mtx.unlock();
		int x = mPeople.getPosX();
		int y = mPeople.getPosY();
		if (level == 5) {
			mLight.setisPlay(false);
			IS_RUNNING = false;
			break;
		}
		if (mPeople.isFinish(x))
		{
			mPeople.updatePos(36, 24);
			level++;
		}
		else
		{
			mPeople.DRAW_PEOPLE(mPeople.getPosX(), mPeople.getPosY());
			switch (Controller::GetConsoleInput()) {
			case 1:  //ESC
				IS_RUNNING = false;
				mLight.setisPlay(false);
				mLight.setState(false);
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
				mLight.setState(false);
				PAUSE_STATE = true;
				break;

			case 8: // SAVE GAME
				mLight.setisPlay(false);
				mLight.setState(false);
				SAVE_GAME = true;
				break;
			case 9: // HELP
				mLight.setisPlay(false);
				mLight.setState(false);
				mtx.lock();
				printHelp();
				mtx.unlock();
				break;
			}
			mPeople.updatePos(x, y);
		}
		if (SAVE_GAME) {
			mtx.lock();
			SaveGame();
			mtx.unlock();
		}
		if (PAUSE_STATE) {
			mtx.lock();
			PauseGame();
			mtx.unlock();
		}
	}
	Graphics::DrawGoodbyeScreen();
	tL.join();
	tO.join();
}
void Game::EndGame(thread* game) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	game->join();
	Graphics::DrawGoodbyeScreen();
}

void Game::SaveGame() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(79, 20, 33, 8);
	Graphics::DrawRectangle(80, 23, 31, 2);
	Controller::GotoXY(89, 22);
	Controller::ShowCursor(true);
	cout << "Enter a filename";
	Controller::GotoXY(81, 24);
	cin >> filename;
	Controller::ShowCursor(false);
	filename = "gameData\\" + filename + ".txt";
	fstream fs(filename, ios::app);
	if (SAVE_GAME) {
		fs << "Player's name: " << playerName << '\n' << "ID: " << playerID << '\n' << "Class: " <<
			className << '\n' << "Score: " << mPeople.getScore() << '\n';
	}
	fs.close();
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Controller::GotoXY(82, 26);
	cout << "----Save game successfully----";
	Sleep(500);
	// Clear up save game board
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			Controller::GotoXY(i, j);
			cout << " ";
		}
	}
	mLight.setisPlay(true);
	SAVE_GAME = false;
}
void Game::LoadGame() {
	Graphics::LoadBackground();
}
void Game::printHelp() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(79, 20, 33, 8);

	Controller::GotoXY(90, 21);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << "Instructions";

	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE); 
	Controller::GotoXY(80, 22);	cout << "- Cross the road and dodge";
	Controller::GotoXY(80, 23); cout << "obstacles (cars & animals)";

	Controller::GotoXY(80, 24); cout << "- Use W, A, S, D to move";

	Controller::SetConsoleColor(BRIGHT_WHITE, YELLOW);
	Controller::GotoXY(80, 25); cout << "- Finish 5 levels to win!!!";

	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Controller::GotoXY(91, 27);
	putchar(175);
	Controller::GotoXY(93, 27);
	cout << "Close";
	Controller::GotoXY(99, 27);
	putchar(174);
	while (Controller::GetConsoleInput() != 6) {
		mSound.PlayerMove();
	}
	mSound.SoundSuccess();
	// Clear up HELP board
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			Controller::GotoXY(i, j);
			cout << " ";
		}
	}
	mLight.setisPlay(true);
	mLight.setState(true);
}
void Game::PauseGame() {
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::GotoXY(79, 20); cout << R"(  _____       _    _  _____ ______  )";
	Controller::GotoXY(79, 21); cout << R"( |  __ \ /\  | |  | |/ ____|  ____| )";
	Controller::GotoXY(79, 22); cout << R"( | |__) /  \ | |  | | (___ | |__    )";
	Controller::GotoXY(79, 23); cout << R"( |  ___/ /\ \| |  | |\___ \|  __|   )";
	Controller::GotoXY(79, 24); cout << R"( | |  / ____ \ |__| |____) | |____  )";
	Controller::GotoXY(79, 25); cout << R"( |_| /_/    \_\____/|_____/|______| )";

	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Controller::GotoXY(88, 27);
	cout << "Press enter to Resume";

	while (Controller::GetConsoleInput() != 6) {
		mSound.PlayerMove();
	}
	mSound.SoundSuccess();
	// Clear up Pause board
	Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			Controller::GotoXY(i, j);
			cout << " ";
		}
	}
	Sleep(10);
	PAUSE_STATE = false;
	mLight.setisPlay(true);
	mLight.setState(true);
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
	cout << curLevel();
	int t2 = 0;
	int t3 = 0;
	int t4 = 0;
	int t5 = 0;

	while (IS_RUNNING) {
		line2->setSpeed(curLevel() * 5);
		line3->setSpeed(curLevel() * 4);
		line4->setSpeed(curLevel() * 3);
		line5->setSpeed(curLevel() * 2);
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
		Sleep(500);
	}

	PAUSE_STATE = true;
}