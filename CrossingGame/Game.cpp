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
string Game::getPlayerName() {
	return playerName;
}
string Game::getPlayerID() {
	return playerID;
}
string Game::getClassName() {
	return className;
}
int Game::getScore() {
	return score;
}
int Game::getLevel() {
	return level;
}
void Game::setInfo(string name, string id, string _class, int _score, int _level) {
	playerName = name;
	playerID = id;
	className = _class;
	score = _score;
	level = _level;
}
void Game::renderLight() {
	while (mLight.getisPlay()) {
		if (mLight.getState()) {
			// Green
			mLight.spawn_light(4, 13);
			mLight.spawn_light(70, 21);
			mLight.setTimer(50);
		}
		else {
			// Red
			mLight.spawn_light(4, 13);
			mLight.spawn_light(70, 21);
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
void Game::winGame() {
	mSound.SoundBackground(false);
	const char winText[] = R"(
		 __          _______ _   _ ______ _____   __          _______ _   _ ______ _____  
		 \ \        / /_   _| \ | |  ____|  __ \  \ \        / /_   _| \ | |  ____|  __ \ 
		  \ \  /\  / /  | | |  \| | |__  | |__) |  \ \  /\  / /  | | |  \| | |__  | |__) |
		   \ \/  \/ /   | | | . ` |  __| |  _  /    \ \/  \/ /   | | | . ` |  __| |  _  / 
		    \  /\  /   _| |_| |\  | |____| | \ \     \  /\  /   _| |_| |\  | |____| | \ \ 
		   __\/_ \/   |_____|_| \_|______|_|  \_\  _ _\/  \/   |_____|_| \_|______|_|  \_\
		  / ____| |   (_)    | |                  | (_)                                   
		 | |    | |__  _  ___| | _____ _ __     __| |_ _ __  _ __   ___ _ __              
		 | |    | '_ \| |/ __| |/ / _ \ '_ \   / _` | | '_ \| '_ \ / _ \ '__|             
		 | |____| | | | | (__|   <  __/ | | | | (_| | | | | | | | |  __/ |                
		  \_____|_| |_|_|\___|_|\_\___|_| |_|  \__,_|_|_| |_|_| |_|\___|_|                
)";
	Controller::ClearConsole();
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << winText;
	mSound.SoundWin();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(45, 13, 35, 8);
	Graphics::DrawRectangle(48, 18, 7, 2);
	Graphics::DrawRectangle(71, 18, 6, 2);

	Controller::GotoXY(49, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
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
	while (true)
	{
		int key = Controller::GetConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				IS_RUNNING = true;
				mSound.SoundSuccess();
				mSound.SoundBackground(true);
				Menu mMenu;
				mMenu.MainMenu();
			}
			else {
				mSound.SoundSuccess();
				IS_RUNNING = false;
			}
			break;
		}
		else
			mSound.PlayerMove();
	}
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

		if (mPeople.isFinish(x))
		{
			mPeople.updatePos(36, 26);
			level++;
		}
		else
		{
			mPeople.DRAW_PEOPLE(mPeople.getPosX(), mPeople.getPosY());
			if (PAUSE_STATE) {
				mtx.lock();
				PauseGame();
				mtx.unlock();
			}
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
	Sleep(1000);
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
	int idx = 13, idx_t = 13, it = 13;
	bool found = false;
	string name;
	while (true) {
		if (found)
			break;
		Controller::GotoXY(47, 11);
		Controller::SetConsoleColor(BRIGHT_WHITE, BLUE);
		cout << "Choose your saving game to load!";

		for (int i = listSaveFile.size() - 2; i >= 0; i--) {
			if (i >= listSaveFile.size() - 9) {
				Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
				Controller::GotoXY(61, 11 + listSaveFile.size() - i);
				name = listSaveFile[i].substr(11, listSaveFile[i].size() - 15);
				cout << name << "       ";
			}
		}

		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(46, 22);
		cout << "Press any keys to go back to menu";

		Controller::GotoXY(58, idx);
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		cout << (char)175;
		Controller::GotoXY(61, idx);
		name = listSaveFile[listSaveFile.size() - 2].substr(11, listSaveFile[listSaveFile.size() - 2].size() - 15);
		cout << name << "       ";
		//cout << listSaveFile[listSaveFile.size() - 2] << "       ";

		while (true) {

			char s = Controller::GetConsoleInput();
			idx_t = idx;

			if (s == 2) {
				idx--;
				if (idx < 13) {
					it--;
					if (it < 13) {
						it = 13;
					}
				}
				else it--;

				if (idx < 13)
					idx = 13;

				if (idx > 13) {
					Controller::GotoXY(61, idx + 1);
					Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
					name = listSaveFile[listSaveFile.size() - (it - 12) - 2].substr(11, listSaveFile[listSaveFile.size() - (it - 12) - 2].size() - 15);
					cout << name << "       ";
				}
				else {
					for (int i = listSaveFile.size() - 2; i >= 0; i--) {
						if (i >= listSaveFile.size() - 9) {
							Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
							Controller::GotoXY(61, 11 + listSaveFile.size() - i);
							name = listSaveFile[i - (it - idx)].substr(11, listSaveFile[i - (it - idx)].size() - 15);
							cout << name << "       ";
						}
					}
				}
				Controller::GotoXY(61, idx);
				Controller::SetConsoleColor(BRIGHT_WHITE, RED);
				name = listSaveFile[listSaveFile.size() - (it - 13) - 2].substr(11, listSaveFile[listSaveFile.size() - (it - 13) - 2].size() - 15);
				cout << name << "       ";
			}
			if (s == 5) {
				idx++;
				if (idx > 20) {
					it++;
					if (it > 13 + listSaveFile.size() - 2) {
						it = 13 + listSaveFile.size() - 2;
					}
				}
				else it = idx;
				
				if (idx > 20)
					idx = 20;
				
				Controller::GotoXY(61, idx);
				Controller::SetConsoleColor(BRIGHT_WHITE, RED);
				name = listSaveFile[listSaveFile.size() - (it - 13) - 2].substr(11, listSaveFile[listSaveFile.size() - (it - 13) - 2].size() - 15);
				cout << name << "       ";
				
				if (it <= 20) {
					Controller::GotoXY(61, idx - 1);
					Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
					name = listSaveFile[listSaveFile.size() - (it - 14) - 2].substr(11, listSaveFile[listSaveFile.size() - (it - 14) - 2].size() - 15);
					cout << name << "       ";
				}
				else {
					for (int i = listSaveFile.size() - 2; i >= 0; i--) {
						if (i >= listSaveFile.size() - 8) {
							Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
							Controller::GotoXY(61, 11 + listSaveFile.size() - i);
							name = listSaveFile[i - (it - idx)].substr(11, listSaveFile[i - (it - idx)].size() - 15);
							cout << name << "       ";
						}
					}
				}
			}

			Controller::GotoXY(58, idx_t);
			cout << "  ";
			Controller::GotoXY(58, idx);
			Controller::SetConsoleColor(BRIGHT_WHITE, RED);
			cout << (char)175;

			// if enter
			if (s == 6)
			{
				idx = listSaveFile.size() - (idx - 13) - 2;
				found = true;
				break;
			}
			if (s != 2 && s != 5 && s != 6) {
				Menu mMenu;
				mMenu.MainMenu();
			}
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
	PAUSE_STATE = true;
	StartGame();
}
void Game::printHelp() {
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(79, 20, 33, 8);

	Controller::GotoXY(90, 21);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << "Instructions";

	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(80, 22);	cout << "- Cross the road and dodge all";
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
	cLine* line3 = new cLine(2, 1, "truck", 20, 3);
	cLine* line4 = new cLine(3, 0, "dino", 20, 1);
	cLine* line5 = new cLine(4, 0, "car", 30, 2);
	vector<COBJECT*> line;
	tL = thread([this] {renderLight(); });
	tO = thread([&] {playGame(line2, line3, line4, line5); });

	while (IS_RUNNING) {
		line2->setSpeed(curLevel());
		line3->setSpeed(curLevel());
		line4->setSpeed(curLevel());
		line5->setSpeed(curLevel());

		//line2->changeLight(mLight.getState());
		line3->changeLight(mLight.getState());
		//line4->changeLight(mLight.getState());
		line5->changeLight(mLight.getState());


		line2->nextMove(mPeople, IS_RUNNING);

		if (line3->getLight()) {
			line3->nextMove(mPeople, IS_RUNNING);
		}


		line4->nextMove(mPeople, IS_RUNNING);


		if (line5->getLight()) {
			line5->nextMove(mPeople, IS_RUNNING);
		}

		mtx.lock();
		line = line2->getData();
		for (int i = 0; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				//cout << "Line 2";
				mLight.setisPlay(false);
				mLight.setState(false);
				IS_RUNNING = false;
				break;
			}
		}

		line = line3->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				//cout << "Line 3";
				mLight.setisPlay(false);
				mLight.setState(false);
				IS_RUNNING = false;
				break;
			}
		}

		line = line4->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				mLight.setisPlay(false);
				mLight.setState(false);
				IS_RUNNING = false;
				break;
			}
		}

		line = line5->getData();
		for (int i{}; i < line.size(); i++) {
			if (mPeople.isImpact(line[i])) {
				//cout << line[i]->getX() << "|" << mPeople.getPosX();
				//Sleep(5000);
				mLight.setisPlay(false);
				mLight.setState(false);
				IS_RUNNING = false;
				break;
			}
		}
		if (level == 6) {
			mLight.setisPlay(false);
			mLight.setState(false);
			IS_RUNNING = false;
			winGame();
		}
		mtx.unlock();
		Sleep(50);
	}
	if (!IS_RUNNING && level != 6) {
		loseGame();
	}
	Graphics::DrawGoodbyeScreen();
	tL.join();
	tO.join();
}
void Game::loseGame() {
	mSound.SoundBackground(false);
	const char loseText[] = R"(
		  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ 
		 /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$
		| $$  \__/| $$  \ $$| $$$$  /$$$$| $$            | $$  \ $$| $$   | $$| $$      | $$  \ $$
		| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/
		| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \  $$ $$/ | $$__/   | $$__  $$
		| $$  \ $$| $$  | $$| $$\  $ | $$| $$            | $$  | $$  \  $$$/  | $$      | $$  \ $$
		|  $$$$$$/| $$  | $$| $$ \/  | $$| $$$$$$$$      |  $$$$$$/   \  $/   | $$$$$$$$| $$  | $$
		 \______/ |__/  |__/|__/     |__/|________/       \______/     \_/    |________/|__/  |__/              
)";
	Controller::ClearConsole();
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	cout << loseText;
	mSound.SoundLose();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(45, 13, 35, 8);
	Graphics::DrawRectangle(48, 18, 7, 2);
	Graphics::DrawRectangle(71, 18, 6, 2);

	Controller::GotoXY(49, 15);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
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
	while (true)
	{
		int key = Controller::GetConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				IS_RUNNING = true;
				mSound.SoundSuccess();
				mSound.SoundBackground(true);
				Menu mMenu;
				mMenu.MainMenu();
			}
			else {
				mSound.SoundSuccess();
				IS_RUNNING = false;
			}
			break;
		}
		else
			mSound.PlayerMove();
	}
}