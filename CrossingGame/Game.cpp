#include "Game.h";

Game::Game() {
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
	level = 1;
	score = 0;
}
Game::Game(int _level) {
	level = _level;
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
	score = 0;
}
void Game::renderLight() {
	while (mLight.getisPlay()) {
		if (mLight.getState()) {
			// Green
			mLight.spawn_light(70, 9);
			mLight.spawn_light(4, 13);
			mLight.spawn_light(70, 17);
			mLight.spawn_light(4, 21);
			mLight.setTimer(50);
		}
		else {
			// Red
			mLight.spawn_light(70, 9);
			mLight.spawn_light(4, 13);
			mLight.spawn_light(70, 17);
			mLight.spawn_light(4, 21);
			mLight.setTimer(30);
		}
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
	getline(cin, playerName);
	Controller::GotoXY(45, 17);
	cout << "Enter your ID:  ";
	getline(cin, playerID);
	Controller::GotoXY(45, 19);
	cout << "Enter your class's name:  ";
	getline(cin, className);
	Controller::ShowCursor(false);
}
void Game::StartGame() {
	Graphics::PrintInterface();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	Controller::GotoXY(85, 7);
	if (playerName.size() != 0)
		cout << "Player's name: " << playerName;
	else {
		playerName = "unknown";
		cout << "Player's name: " << playerName;
	}
	Controller::GotoXY(85, 9);
	if (playerID.size() != 0)
		cout << "Student's ID: " << playerID;
	else {
		playerID = "unknown";
		cout << "Student's ID: " << playerID;
	}
	Controller::GotoXY(85, 11);
	if (className.size() != 0)
		cout << "Class: " << className;
	else {
		className = "unknown";
		cout << "Class: " << className;
	}
	thread light;
	thread people;

	thread mainGame([&] {renderObject(light, people); });

	mainGame.join();
	light.join();
	people.join();
}

void Game::playGame(cLine* line2, cLine* line3, cLine* line4, cLine* line5) {
	vector<COBJECT*> line;
	while (IS_RUNNING) {
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(10, 1);
		Graphics::PrintLevel(level);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		Graphics::DrawRectangle(90, 0, 10, 2);
		Controller::GotoXY(92, 1);
		cout << "SCORE: " << score + mPeople.getScore();
		mtx.unlock();
		int x = mPeople.getPosX();
		int y = mPeople.getPosY();

		mtx.lock();
		line = line2->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				IS_RUNNING = false;
				break;
			}
		}

		line = line3->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				IS_RUNNING = false;
				break;
			}
		}

		line = line4->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				IS_RUNNING = false;
				break;
			}
		}

		line = line5->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				IS_RUNNING = false;
				break;
			}
		}
		mtx.unlock();

		if (level == 5) {
			mLight.setisPlay(false);
			IS_RUNNING = false;
			break;
		}
		if (mPeople.isFinish(x))
		{
			mPeople.updatePos(36, 26);
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
				PAUSE_STATE = true;
				break;

			case 8: // SAVE GAME
				SAVE_GAME = true;
				break;
			case 9: // HELP
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
	filename = "./gameData/" + filename + ".txt";

	fstream saveFile("listFile.txt", ios::app);
	saveFile << filename << "\n";
	saveFile.close();

	if (_mkdir("./gameData") == -1) {
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(82, 26);
		cerr << " Error : " << strerror(errno) << endl;
	}
	fstream fs(filename, ios::app);
	if (SAVE_GAME) {
		fs << "Player's name: " << playerName << '\n' << "ID: " << playerID << '\n' << "Class: " <<
			className << '\n' << "Level: " << level << "\n" << "Score: " << mPeople.getScore() << '\n';
		fs << "Position: " << mPeople.getPosX() << "," << mPeople.getPosY() << '\n';
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
	SAVE_GAME = false;
	mLight.setisPlay(true);
}
void Game::LoadGame() {
	Controller::ClearConsole();
	Graphics::LoadBackground();
	fstream fs("listFile.txt", ios::in);
	string tmp;
	while (!fs.eof()) {
		getline(fs, tmp);
		listSaveFile.push_back(tmp);
	}
	fs.close();
	Controller::GotoXY(47, 11);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
	cout << "Choose your saving game to load!";

	int idx = 13, idx_t = 13;

	for (int i = 0; i < listSaveFile.size(); i++) {
		Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
		Controller::GotoXY(51, i + 13);
		cout << listSaveFile[i] << endl;
		if (i > 6)
			break;
	}
	Controller::GotoXY(48, idx);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << (char)175;
	Controller::GotoXY(51, idx);
	cout << listSaveFile[0] << endl;

	while (true) {
		char s = Controller::GetConsoleInput();
		idx_t = idx;

		if (s == 2) {
			idx--;
			if (idx < 13)
				idx = 13;
			Controller::GotoXY(51, idx);
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
			cout << listSaveFile[idx - 13];
			Controller::GotoXY(51, idx + 1);
			Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
			cout << listSaveFile[idx - 12];
		}
		else if (s == 5) {
			idx++;
			if (idx > 11 + listSaveFile.size())
				idx = 11 + listSaveFile.size();
			Controller::GotoXY(51, idx);
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
			cout << listSaveFile[idx - 13];
			Controller::GotoXY(51, idx - 1);
			Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
			cout << listSaveFile[idx - 14];

		}

		Controller::GotoXY(48, idx_t);
		cout << "  ";
		Controller::GotoXY(48, idx);
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << (char)175;

		// if enter
		if (s == 6)
		{
			idx -= 13;
			break;
		}
	}
	fstream readFile(listSaveFile[idx], ios::in);
	int posX{}, posY{};
	while (!readFile.eof()) {
		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, playerName);
		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, playerID);
		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, className);
		readFile.get();
		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> level;
		readFile.ignore();
		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> score;
		readFile.ignore();
		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> posX;
		readFile.ignore();
		readFile >> posY;
		readFile.ignore();
	}
	readFile.close();
	IS_RUNNING = true;
	mPeople.updatePos(posX, posY);
	StartGame();
}
void Game::printHelp() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(79, 20, 33, 8);

	Controller::GotoXY(90, 21);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << "Instructions";

	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(80, 22);	cout << "- Cross the road and dodge all the";
	Controller::GotoXY(80, 23); cout << "obstacles (cars & animals)";
	Controller::GotoXY(80, 24); cout << "- Use W, A, S, D to move";

	Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
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
}
void Game::renderObject(thread& tL, thread& tO) {
	int dx = -6, dy = 6;
	int _dx = 58;
	int ObjSpace;
	cLine* line2 = new cLine(1, 1, "bird", 15, 4);
	cLine* line3 = new cLine(2, 0, "truck", 20, 3);
	cLine* line4 = new cLine(3, 1, "dino", 20, 1);
	cLine* line5 = new cLine(4, 0, "car", 30, 2);
	vector<COBJECT*> line;
	tL = thread([this] {renderLight(); });
	tO = thread([&] {playGame(line2, line3, line4, line5); });

	while (IS_RUNNING) {
		line2->setSpeed(curLevel() * 5);
		line3->setSpeed(curLevel() * 4);
		line4->setSpeed(curLevel() * 3);
		line5->setSpeed(curLevel() * 2);
		
		line2->changeLight(mLight.getState());
		line3->changeLight(mLight.getState());
		line4->changeLight(mLight.getState());
		line5->changeLight(mLight.getState());

		if (line2->getLight()) {
			line2->nextMove(mPeople, IS_RUNNING);
		}

		if (line3->getLight()) {
			line3->nextMove(mPeople, IS_RUNNING);
		}

		if (line4->getLight()) {
			line4->nextMove(mPeople, IS_RUNNING);
		}

		if (line5->getLight()) {
			line5->nextMove(mPeople, IS_RUNNING);
		}

		mtx.lock();
		line = line2->getData();
		for (int i = 0; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				cout << "Line 2";
				IS_RUNNING = false;
				break;
			}
		}

		line = line3->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				cout << "Line 3";
				IS_RUNNING = false;
				break;
			}
		}

		line = line4->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				IS_RUNNING = false;
				break;
			}
		}

		line = line5->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				cout << line[i]->getX() << "|" << mPeople.getPosX();
				Sleep(5000);
				IS_RUNNING = false;
				break;
			}
		}


		mtx.unlock();
		Sleep(50);
	}

	Graphics::DrawGoodbyeScreen();
	tL.join();
	tO.join();
}