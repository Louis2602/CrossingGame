#pragma once

#include "CANIMAL.h"
#include "COBJECT.h"
#include "CLIGHT.h"
#include "Sound.h"
#include "cPoint.h"


class CPEOPLE {
private:
	cPoint pos; //Position of character
	bool mState = true;		// dead or alive state
	int level = 0, score = 0;
	int back = 0, forward = 0;
public:
	CPEOPLE() {
		pos.setXY(36, 24);
	}
	~CPEOPLE() {};
	int getPosX();     //Get mX value of character
	int getPosY();     //Get mY value of character
	int getScore();   //Get player's score
	int getForward();
	int getBack();
	bool isDead();     //Return if character is dead or not

	void updateScore(); //Update score when player move
	void updatePos(int, int);  //Update position of character after move
	void setForward();
	void setBack();

	void DRAW_PEOPLE(int mX, int mY);  //Draw player's character to screen
	void Delete(int mX, int mY); //Delete character at previous position

	void Up(int& mY);            //Move character up
	void Left(int& mX);          //Move character left
	void Right(int& mX);         //Move character right
	void Down(int& mY);          //Move character down

	bool isImpact(const COBJECT*& Object); //Check if player impact with Object
	bool isImpact(const CANIMAL*& animal);   //Check if player impact with animal
	bool isFinish(int mX);             //Check if player has completed the stage
};