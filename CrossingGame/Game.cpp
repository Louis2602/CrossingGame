#include "Game.h";

Game::Game(int _level) {
	level = _level;
	score = 0;
	IS_RUNNING = true;
	PAUSE_STATE = false;
	SAVE_GAME = false;
}

void Game::StartGame() {
	Graphics::PrintInterface();
	thread light([this] { l.mainLight(); });
	CPEOPLE p;
	int x, y;
	while (IS_RUNNING) {
		
		if (PAUSE_STATE) {
			l.setState(false);
			while (PAUSE_STATE) {
				askContinue();
			}
		}
		while (SAVE_GAME)
			SaveGame();
		while (!PAUSE_STATE && p.isDead()) {
			Controller::GotoXY(100, 17);
			cout << p.getScore();
			x = p.getPosX();
			y = p.getPosY();
			if (p.isFinish(x))
			{
				p.updatePos(36, 24);
			}
			else
			{
				Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
				p.DRAW_PEOPLE(p.getPosX(), p.getPosY());
				switch (Controller::GetConsoleInput()) {
				case 1:  //ESC
					IS_RUNNING = false;
					l.setState(false);
					light.join();
					Graphics::DrawGoodbyeScreen();
					break;
				case 2: //UP
				{
					p.Delete(x, y);
					p.Up(y);
					break;
				}
				case 3: //LEFT
				{
					p.Delete(x, y);
					p.Left(x);
					break;
				}
				case 4: //RIGHT
				{
					p.Delete(x, y);
					p.Right(x);
					break;
				}
				case 5: //DOWN
				{
					p.Delete(x, y);
					p.Down(y);
					break;
				}
				case 7: //PAUSE GAME
					PAUSE_STATE = true;
					break;

				case 8: // SAVE GAME
					SAVE_GAME = true;
					break;
				}
				p.updatePos(x, y);
			}
		}
	}
}

void Game::SetUpGame() {
	
}

void Game::EndGame(thread* t) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	t->join();
}

void Game::SaveGame() //Save game
{
	fstream fs("gameData\\game.txt", ios::app);
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
			s.PlayerMove();
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
			else
				IS_RUNNING = false;
			return;
		}
		else
			s.PlayerMove();
	}
}
