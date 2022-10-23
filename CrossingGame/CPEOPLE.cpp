#include"CPEOPLE.h"
#include"Graphics.h"

const string people[] = { " o ", R"(/|\)", R"(/ \)" };

int CPEOPLE::getPosX() {
	return mX;
}

int CPEOPLE::getPosY() {
	return mY;
}

void CPEOPLE::updatePos(int x, int y) {
	mX = x;
	mY = y;
}

bool CPEOPLE::isDead() {
	return mState;
}

void CPEOPLE::DRAW_PEOPLE(int mX, int mY) {
	for (int i = 0; i < 3; i++) {
		Controller::GotoXY(mX, mY + i);
		cout << people[i];
	}
}

void CPEOPLE::Delete(int mX, int mY) {
	for (int i = 0; i < 3; i++) {
		Controller::GotoXY(mX, mY + i);
		cout << "   ";
	}
}

void CPEOPLE::Up(int& mY) {
	CPEOPLE::sound(1);
	if (mY == 4)
		return;
	mY -= 4;
}

void CPEOPLE::Left(int& mX) {
	CPEOPLE::sound(1);
	if (mX == 6)
		return;
	mX -= 2;
}

void CPEOPLE::Right(int& mX) {
	CPEOPLE::sound(1);
	if (mX + 3 == 69)
		return;
	mX += 2;
}

void CPEOPLE::Down(int& mY) {
	CPEOPLE::sound(1);
	if (mY + 3 == 27)
		return;
	mY += 4;
}

/*
bool isImpact(const CVEHICLE*& vehicle);
bool isImpact(const CANIMAL*& animal) {
}
*/
bool CPEOPLE::isFinish(int mX) {
	if (mY == 4)
		return true;
	return false;
}
void CPEOPLE::sound(int s) {
	switch (s)
	{
	case 1:
		PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
	}
}

void CPEOPLE::mainPeople() {
	CPEOPLE p;
	int x, y;
	while (p.isDead()) {
		x = p.getPosX();
		y = p.getPosY();
		if (p.isFinish(x))
		{
			p.updatePos(36, 24);
		}
		else
		{
			p.DRAW_PEOPLE(p.getPosX(), p.getPosY());
			switch (Controller::GetConsoleInput()) {
			case 2:
			{
				p.Delete(x, y);
				p.Up(y);
				break;
			}
			case 3:
			{
				p.Delete(x, y);
				p.Left(x);
				break;
			}
			case 4:
			{
				p.Delete(x, y);
				p.Right(x);
				break;
			}
			case 5:
			{
				p.Delete(x, y);
				p.Down(y);
				break;
			}
			}
			p.updatePos(x, y);
		}
	}
}