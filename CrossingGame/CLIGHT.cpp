#include "CLIGHT.h"

CLIGHT::CLIGHT() {
	state = true;
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

void CLIGHT::update_light() {
	if (getState()) {
		//Draw green light.
		Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
		Controller::GotoXY(4, 21);
		cout << TopDot;
		Controller::GotoXY(70, 17);
		cout << TopDot;
		Controller::GotoXY(4, 13);
		cout << TopDot;
		Controller::GotoXY(70, 9);
		cout << TopDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(4, 20);
		cout << BottomDot;
		Controller::GotoXY(70, 16);
		cout << BottomDot;
		Controller::GotoXY(4, 12);
		cout << BottomDot;
		Controller::GotoXY(70, 8);
		cout << BottomDot;
		setState(false);
	}
	else {
		//Draw red light
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(4, 20);
		cout << BottomDot;
		Controller::GotoXY(70, 16);
		cout << BottomDot;
		Controller::GotoXY(4, 12);
		cout << BottomDot;
		Controller::GotoXY(70, 8);
		cout << BottomDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(4, 21);
		cout << TopDot;
		Controller::GotoXY(70, 17);
		cout << TopDot;
		Controller::GotoXY(4, 13);
		cout << TopDot;
		Controller::GotoXY(70, 9);
		cout << TopDot;
		setState(true);
	}

	//Set color back.
	//Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
}

void CLIGHT::mainLight() {
	CLIGHT light;
	while (state) {
		light.update_light();
		Sleep(5000);
	}
}