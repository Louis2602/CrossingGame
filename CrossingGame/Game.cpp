#include "Game.h";

Game::Game(int _level) {
	level = _level;
	score = 0;
}

void Game::StartGame() {
	CPEOPLE p;
	CLIGHT l;
	int timer = 3000;
	Graphics::PrintInterface();


	thread light(l.mainLight);
	p.mainPeople();

	light.join();

	/*Để people là thread chính, các hàm sử dụng std::thread là các thread phụ chạy song song vs thread chính
	* các thread phụ sẽ được tạo và gọi trước khi thread chính chạy
	* hàm join() dùng để cho thread phụ và thread chính kêt thúc cùng nhau
	*/
}

void Game::EndGame(thread* t) {
	Controller::ClearConsole();
	IS_RUNNING = false;
	t->join();
}
