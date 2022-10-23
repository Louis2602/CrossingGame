#pragma once

#include "CANIMAL.h"
#include "CVEHICLE.h"

class CPEOPLE {
private:
	int mX = 36, mY = 24;   //Position of character
	bool mState = true;		// dead or alive state
	int level = 0, score = 0;
public:
	CPEOPLE() {};
	~CPEOPLE() {};
	int getPosX();     //Get mX value of character
	int getPosY();     //Get mY value of character
	void updatePos(int x, int y);  //Update position of character after move
	bool isDead();     //Return if character is dead or not
	void DRAW_PEOPLE(int mX, int mY);  //Draw player's character to screen
	void Delete(int mX, int mY); //Delete character at previous position
	void Up(int& mY);            //Move character up
	void Left(int& mX);          //Move character left
	void Right(int& mX);         //Move character right
	void Down(int& mY);          //Move character down
	//bool isImpact(const CVEHICLE*& vehicle); //Check if player impact with vehicle
	//bool isImpact(const CANIMAL*& animal);   //Check if player impact with animal
	bool isFinish(int mX);             //Check if player has completed the stage
	void sound(int s);                //Play character's sound effects
	static void mainPeople();    //Main function of character
};