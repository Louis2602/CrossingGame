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
	thread vehicle([this] {initLine(); });
	CPEOPLE p;
	int x, y;
	while (IS_RUNNING) {
		//Graphics::initLine();

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

void Game::initLine() {
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
	
	while (true) {


		if (t2 % 15 && line2->getLight()) {
			//cPoint pos1(dx - t * 15, dy);
			cPoint pos2(dx - t2 * 15, dy + 4);
			/*cPoint pos3(dx - t3 * 15, dy + 4 * 2);
			cPoint pos4(dx - t4 * 15, dy + 4 * 3);
			cPoint pos5(dx - t5 * 15, dy + 4 * 4);*/
			//cPoint pos6(dx - t * 15, dy + 4 * 5);
			
			//CVEHICLE* car1;
			CVEHICLE* car2;
			/*CVEHICLE* car3;
			CVEHICLE* car4;
			CVEHICLE* car5;*/
			//CVEHICLE* car6;
			
			//car1 = new cCar(pos1);
			car2 = new cTruck(pos2);
			//car3 = new cCar(pos3);
			//car4 = new cTruck(pos4);
			//car5 = new cCar(pos5);
			//car6 = new cTruck(pos6);

			//line1->pushVehicle(car1);
			line2->pushVehicle(car2);
			//line3->pushVehicle(car3);
			//line4->pushVehicle(car4);
			//line5->pushVehicle(car5);
			//line6->pushVehicle(car6);
		}

		if (t3 % 15 && line3->getLight()) {
			cPoint pos3(dx - t3 * 15, dy + 4 * 2);

			CVEHICLE* car3;

			car3 = new cCar(pos3);

			line3->pushVehicle(car3);
		}

		if (t4 % 15 && line4->getLight()) {
			cPoint pos4(dx - t4 * 15, dy + 4 * 3);

			CVEHICLE* car4;

			car4 = new cTruck(pos4);

			line4->pushVehicle(car4);
		}

		if (t5 % 15 && line5->getLight()) {
			cPoint pos5(dx - t5 * 15, dy + 4 * 4);
			
			CVEHICLE* car5;
			
			car5 = new cCar(pos5);

			line5->pushVehicle(car5);
		}

		line2->changeLight(l.getState());
		line3->changeLight(l.getState());
		line4->changeLight(l.getState());
		line5->changeLight(l.getState());

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
