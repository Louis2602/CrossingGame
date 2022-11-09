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

void CPEOPLE::setScore(int score) {
	this->score = score;
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
	Sound s;
	s.PlayerMove();
	if (mY == 4)
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
	if (mY + 3 == 27)
		return;
	mY += 4;
	setBack();
}

/*
bool isImpact(const CVEHICLE*& vehicle);
bool isImpact(const CANIMAL*& animal) {

}
*/
bool CPEOPLE::isFinish(int mX) {
	if (pos.getY() == 4)
		return true;
	return false;
}