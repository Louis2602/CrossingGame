#pragma once

#include "cLine.h"

using namespace std;

class cRows
{
private:
	vector <cLine*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, cVehicle* enemy); //  push a new enemy to a row
	void pushRow(cLine*);
	vector <cVehicle*> listEnemy(); // return all enemies from all rowsgit ad
	vector <cLine*> listRow();
	void redrawState();

};