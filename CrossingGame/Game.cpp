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
	while (IS_RUNNING) {
		//p.mainPeople(l);
		if (PAUSE_STATE) {
			//light.join();
			l.setState(false);
			askContinue();
		}
		if (SAVE_GAME)
			SaveGame();
		while (!PAUSE_STATE) {
			switch (Controller::GetConsoleInput()) {
			case 1:
				IS_RUNNING = false;
				Graphics::DrawGoodbyeScreen();
				break;
			case 7:
				PAUSE_STATE = true;
				break;
			case 8:
				SAVE_GAME = true;
				break;
			}
		}	
	}


	/*Để people là thread chính, các hàm sử dụng std::thread là các thread phụ chạy song song vs thread chính
	* các thread phụ sẽ được tạo và gọi trước khi thread chính chạy
	* hàm join() dùng để cho thread phụ và thread chính kêt thúc cùng nhau
	*/
}

void Game::SetUpGame() {
	
}

void Game::EndGame(thread* t) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	t->join();
}
void Game::SaveGame() {
	fstream fs("gameData\\game.txt", ios::app);
	fs.close();
}
void Game::askContinue()
{
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Controller::GotoXY(0, 0);
	Controller::SetConsoleColor(BRIGHT_WHITE, RED);
	Controller::SetConsoleColor(BRIGHT_WHITE, BLACK);
	Graphics::DrawRectangle(34, 13, 35, 8);
	Graphics::DrawRectangle(37, 18, 7, 2);
	Graphics::DrawRectangle(60, 18, 6, 2);
	Controller::GotoXY(36, 16);
	Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to play another round?";
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
