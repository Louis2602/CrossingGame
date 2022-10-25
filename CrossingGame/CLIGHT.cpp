#include "CLIGHT.h"

CLIGHT::CLIGHT() {
	state = false;
}
bool CLIGHT::getState() {
	return state;
}
void CLIGHT::setState(bool _state) {
	state = _state;
}

void CLIGHT::update_light() {
	//Draw red light
	if (getState()) {
		//Draw green light.
		Controller::SetConsoleColor(BRIGHT_WHITE, GREEN);
		Controller::GotoXY(6, 21);
		cout << TopDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(6, 20);
		cout << BottomDot;
		setState(false);
	}
	else {
		Controller::SetConsoleColor(BRIGHT_WHITE, RED);
		Controller::GotoXY(6, 20);
		cout << BottomDot;
		Controller::SetConsoleColor(BRIGHT_WHITE, GRAY);
		Controller::GotoXY(6, 21);
		cout << TopDot;
		setState(true);
	}

	//Set color back.
	//Controller::SetConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
}

void CLIGHT::mainLight() {
	CLIGHT light;
	int timer = 3000;
	while (timer) {
		light.update_light();
		Sleep(1000);
		timer -= 50;
	}
}