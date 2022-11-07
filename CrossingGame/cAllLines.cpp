#include "cAllLines.h"

cAllLines::cAllLines() {
	//subRows.reserve(100);
}

bool cAllLines::pushVehicle(int line, cVehicle* vehicle) {
	if (line >= (int)_lines.size())  return false;
	return _lines[line]->pushVehicle(vehicle);
}

void cAllLines::pushRow(cLine* line) {
	_lines.push_back(line);
}

vector<cVehicle*> cAllLines::listVehicle() {
	vector<cVehicle*> listEnemy, tmp;
	for (int i = 0; (unsigned)i < _lines.size(); i++) {
		tmp = _lines[i]->getVehicle();
		listEnemy.insert(listEnemy.end(), tmp.begin(), tmp.end());
	}
	return listEnemy;
}

vector <cLine*> cAllLines::listRow() {
	return _lines;
}

