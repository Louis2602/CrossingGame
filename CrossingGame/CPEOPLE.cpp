#include"CPEOPLE.h"

const string people[] = { " o ", R"(/|\)", R"(/ \)" };

int CPEOPLE::getPosX() {
	return this->pos.getX();
}

int CPEOPLE::getPosY() {
	return pos.getY();
}

int CPEOPLE::getScore() {
	return score;
}

int CPEOPLE::getForward() {
	return forward;
}

int CPEOPLE::getBack() {
	return back;
}

int CPEOPLE::getHeight() {
	return height;
}

int CPEOPLE::getWidth() {
	return width;
}

void CPEOPLE::updateScore() {
	if (score < getForward() - getBack())
		this->score++;
}

void CPEOPLE::updatePos(int x, int y) {
	pos.setXY(x, y);
}

void CPEOPLE::setBack() {
	this->back++;
}

void CPEOPLE::setForward() {
	this->forward++;
}

void CPEOPLE::DRAW_PEOPLE(int mX, int mY) {
	for (int i = 0; i < 3; i++) {
		mtx.lock();
		Controller::SetConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		Controller::GotoXY(mX, mY + i);
		cout << people[i];
		mtx.unlock();
	}
}

void CPEOPLE::Delete(int mX, int mY) {
	for (int i = 0; i < 3; i++) {
		mtx.lock();
		Controller::GotoXY(mX, mY + i);
		cout << "   ";
		mtx.unlock();
	}
}

void CPEOPLE::Up(int& mY) {
	Sound s;
	s.PlayerMove();
	if (mY == 6)
		return;
	mY -= 4;
	setForward();
	updateScore();
}

void CPEOPLE::Left(int& mX) {
	Sound s;
	s.PlayerMove();
	if (mX == 6)
		return;
	mX -= 2;
}

void CPEOPLE::Right(int& mX) {
	Sound s;
	s.PlayerMove();
	if (mX + 3 == 69)
		return;
	mX += 2;
}

void CPEOPLE::Down(int& mY) {
	Sound s;
	s.PlayerMove();
	if (mY + 3 == 29)
		return;
	mY += 4;
	setBack();
}

bool CPEOPLE::isImpact(COBJECT* Object, int space) {
	int ppX = this->getPosX();
	int ppY = this->getPosY();
	int objX = Object->getX() + space;
	int objY = Object->getY();
	int width = Object->getWidth();
	if (ppY == objY) {
		if ((ppX >= objX && ppX <= objX + width) ||
			(ppX + 2 >= objX && ppX + 2 <= objX + width))
			return true;
	}
	return false;
}

bool CPEOPLE::isFinish(int mX) {
	if (pos.getY() == 6)
		return true;
	return false;
}