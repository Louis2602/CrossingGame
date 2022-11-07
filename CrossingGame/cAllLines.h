//#pragma once

#ifndef cAllLines_h
#define cAllLines_h
	
#include <vector>
#include "cLine.h"


using namespace std;
#define RIGHT 65
#define LEFT 2

class cAllLines
{
private:
	vector <cLine*> lines;
public:
	cAllLines();
	~cAllLines() = default;
	bool pushVehicle(int line, cVehicle* vehicle); //  push a new enemy to a row
	void pushRow(cLine*);
	vector <cVehicle*> listVehicle(); // return all enemies from all rowsgit ad
	vector <cLine*> listRow();
};

#endif // !cAllLines_h
