#include "Game.h";

Game::Game(int _level) {
	level = _level;
	score = 0;
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
}
void setLight(CLIGHT& mLight) {
	// Green
	mLight.spawn_light(70, 3);
	mLight.setTimer(50);
	// Red
	mLight.spawn_light(70, 3);
	mLight.setTimer(30);
	std::this_thread::sleep_for(chrono::milliseconds(100));
}
void setAnimal(CLINEAnimal mLine, CLIGHT& mLight) {
	mLine.setTrafficLightState(mLight.getState());
	mLine.DrawAnimalLine();
	std::this_thread::sleep_for(chrono::milliseconds(100));
}
void Game::playGame() {
	while (IS_RUNNING) {
		while (!PAUSE_STATE && mPeople.isDead()) {
			Controller::GotoXY(100, 17);
			cout << mPeople.getScore();
			int x = mPeople.getPosX();
			int y = mPeople.getPosY();
			if (mPeople.isFinish(x))
			{
				mPeople.updatePos(36, 24);
			}
			else
			{
				Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
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
					Controller::GotoXY(75, 10);
					mLight.setisPlay(false);
					mLight.setState(false);
					mLine.setTrafficLightState(false);
					PAUSE_STATE = true;
					break;

				case 8: // SAVE GAME
					SAVE_GAME = true;
					break;
				}
				mPeople.updatePos(x, y);
			}
			if (PAUSE_STATE) {
				askContinue();
			}
			while (SAVE_GAME)
				SaveGame();
		}
		std::this_thread::sleep_for(chrono::milliseconds(100));
	}
	SaveGame();
}
void Game::StartGame() {
	Graphics::PrintInterface();

	//thread light(&setLight, ref(mLight));
	//thread animal(&setAnimal, mLine, ref(mLight));
	thread mainGame([this] {playGame(); });
	setLight(mLight);
	setAnimal(mLine, mLight);
	Controller::GotoXY(75, 5);
	cout << mLight.getState();
	mainGame.join();
}

void Game::EndGame(thread* t) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	t->join();
}

void Game::SaveGame() //Save game
{
	fstream fs("gameData\\game.txt", ios::app);
	askSaveGame();
	fs.close();
}

void Game::askContinue() //ask player to continue or not when pause game
{
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(0, 0);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(34, 13, 35, 8);
	Graphics::DrawRectangle(37, 18, 7, 2);
	Graphics::DrawRectangle(60, 18, 6, 2);
	Controller::GotoXY(41, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to continue?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
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
			}
			return;
		}
		else
			mSound.PlayerMove();
	}
}
void Game::askSaveGame() //ask player to continue or not when pause game
{
	Controller::ClearConsole();
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(0, 0);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(34, 13, 35, 8);
	Graphics::DrawRectangle(37, 18, 7, 2);
	Graphics::DrawRectangle(60, 18, 6, 2);
	Controller::GotoXY(41, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to save game?";
	string str[2] = { "Yes", "No" };
	int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
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
			}
			else {
				SAVE_GAME = false;
				Graphics::DrawGoodbyeScreen();
			}
			return;
		}
		else
			mSound.PlayerMove();
	}
}