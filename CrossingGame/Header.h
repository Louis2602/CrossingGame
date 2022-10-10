#pragma comment(lib, "Winmm.lib")
#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include<MMsystem.h>		//include library for playing sound

using namespace std::chrono;
//using namespace std::literals::chrono_literals;
using namespace std;

extern int Round;
//extern bool Right;
//extern bool Up;
//extern char MOVING;
//extern int nums_bullet;
//extern int HP;
//extern int Score;
//extern int coin;
//extern int Life;
//extern bool FlatContinue;
//extern bool FlatPAgain;
//extern bool FlatImpact;
//extern int chon;
//extern int SkillShot;
//extern int numSkin;
//extern int countt;
//extern int Sec;
//extern int Min;
//static steady_clock::time_point start;

//static int choice;
#define WIDTH_CONSOLE 1366
#define HEIGH_CONSOLE 728
#define COORD_SPACE_X  (WIDTH_CONSOLE/2)
#define COORD_SPACE_Y  24
#define COORD_ENEMY_X  0
#define COORD_ENEMY_Y  0
#define BULLETS 300
#define NUMs_ENEMY 120
#define SPEED 20
#define STAR 70
#define FILENAME "Data.txt"
//
////banphaohoa
//#define minx 1
//#define maxx 79
//#define miny 1
//#define maxy 50
//
//class Coordinate
//{
//protected:
//	int x;
//	int y;
//public:
//	void Draw(char);
//	int getX();
//	int getY();
//	void setCoord(int, int);
//	bool state = true;
//};
//class SpaceShip :public Coordinate
//{
//public:
//	SpaceShip();
//	void Left();
//	void Down();
//	void Up();
//	void Right();
//	void Draww();
//	void Erase();
//
//};
//class Bullet :public Coordinate
//{
//public:
//	Bullet();
//};
//class Enemy :public Coordinate
//{
//public:
//	Enemy();
//	bool TouchBoundary();
//};
//class Star :public Coordinate
//{
//public:
//	Star();
//};
//extern SpaceShip space;
//extern Enemy enemy[NUMs_ENEMY];
//extern Bullet bullet[BULLETS];
//extern Star star[STAR];

//Controller.cpp
void SetUpConsole();
void FixConsoleWindow();
void SetAndCenterWindow();
void GotoXY(int, int);
void HideScrollBars();
void SetFontInfo();
void DisableMouseInput();
void ShowCursor(bool);
void ConsoleTitle();
void ClearConsole();
void TextColor(int);
void SetColor(int);

//Graphic.cpp
void Menu();
void LoadBackground();
void DrawMenuBox();

//Menu.cpp
void MenuGameplay();
void MenuRule();
void MenuAbout();
void MenuScore();
void MenuQuitGame();

//Function.cpp
void PlayGame();
void StartGame();
void EndGame();
void PauseGame();
void SaveGame();
void LoadGame();

//Sound.cpp
void SoundBackground();
//void SoundGameOver();		//Sound Game over when you lost
//void SoundGameWin();		//Sound Gamw when you win the game
void SoundByeBye();
void SoundRocket();
void EndSoundGame();         //End sound game

//Animal.cpp
class CANIMAL {
	int mX, mY;
public:
	virtual void Move(int, int);
	virtual void Tell();
};

//Vehicle.cpp
class CVEHICLE {
	int mX, mY;
public:
	virtual void Move(int, int);
};

//People.cpp
class CPEOPLE {
	int mX, mY;
	bool mState;		// dead or alive state
public:
	CPEOPLE() {};
	~CPEOPLE() {};
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

//Move.cpp
//void MoveRight(Enemy enemy[NUMs_ENEMY]);	// move enemy right
//void MoveLeft(Enemy enemy[NUMs_ENEMY]);		// move enemy left
//void MoveUp(Enemy enemy[NUMs_ENEMY]);
//void MoveDown(Enemy enemy[NUMs_ENEMY]);
//void MoveEnemy();							// move enemy
//void MoveBullets();			// move bullets
//void MoveStar();

//Time.cpp
//int modernization(int sec, int min);
//void printTime();
//void startTime();