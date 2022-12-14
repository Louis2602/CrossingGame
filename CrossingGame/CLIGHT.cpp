#include "CLIGHT.h"

CLIGHT::CLIGHT() {
	isPlay = true;
	state = true;
	posX = 0;
	posY = 0;
	timer = 0;
}
bool CLIGHT::getisPlay() {
	return isPlay;
}
void CLIGHT::setisPlay(bool play) {
	isPlay = play;
}
bool CLIGHT::getState() {
	return state;
}
void CLIGHT::setState(bool _state) {
	state = _state;
}
void CLIGHT::setTimer(int timer) {
	while (timer && isPlay) {
		spawn_light(posX, posY);
		Sleep(1000);
		timer -= 10;
	}
	this->setState(!state);
}
void CLIGHT::setPos(int x, int y) {
	posX = x;
	posY = y;
}
void CLIGHT::spawn_light(int x, int y) {
	setPos(x, y);
	if (state) {
		//Draw green light.
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
		Controller::GotoXY(x, y + 1);
		cout << TopDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(x, y);
		cout << BottomDot;
		mtx.unlock();
	}
	else {
		//Draw red light
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(x, y);
		cout << BottomDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(x, y + 1);
		cout << TopDot;
		mtx.unlock();

	}
}