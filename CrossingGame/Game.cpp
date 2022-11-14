#include "Game.h";

Game::Game(int _level) {
	level = _level;
	score = 0;
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
void Game::renderAnimal(thread& tL) {
	mLine.setTrafficLightState(mLight.getState());
	//mLine.DrawAnimalLine();
	for (int i = 0; i < 3; i++) {
		CBIRD* bird = new CBIRD;
		bird->newPosition(4, i * 7 + 5);
		mLine.pushAnimal(bird);
	}
	while (mLine.getTrafficLightState()) {
		for (int i = 0; i < mLine.getAnimal().size(); i++) {
			mLine.printAnimal(mLine.getAnimal()[i]->getPos(),
				mLine.getAnimal()[i]->returnShape(),
				mLine.getAnimal()[i]->getWidth(),
				mLine.getAnimal()[i]->getHeight());
		}
		Sleep(100);
		for (int i = 0; i < mLine.getAnimal().size(); i++) {
			mLine.deleteAnimal(mLine.getAnimal()[i]->getPos(),
				mLine.getAnimal()[i]->getWidth(),
				mLine.getAnimal()[i]->getHeight());
		}
		for (int i = 0; i < mLine.getAnimal().size(); i++) {
			mLine.getAnimal()[i]->updatePosition(0, 1);
		}
	}
}

void Game::StartGame() {
	Graphics::PrintInterface();

	thread light;
	thread vehicle;
	thread animal;

	thread mainGame([&] {playGame(light, vehicle, animal); });

	mainGame.join();
}
void Game::playGame(thread& tL, thread& tV, thread& tA) {
	tL = thread([this] {renderLight(); });
	tV = thread([&] {renderVehicle(tL); });
	//tA = thread([&] {renderAnimal(tL); });

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
	}
	tV.join();
	//tA.join();
	tL.join(); 
	SaveGame();
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

void Game::renderVehicle(thread& tL) {
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

	//thread light([this] {renderLight(); });
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