#include "cAllLines.h"

cAllLines::cAllLines() {
	//subRows.reserve(100);
}

bool cAllLines::pushVehicle(int line, cVehicle* vehicle) {
	if (line >= (int)lines.size())  return false;
	return lines[line]->pushVehicle(vehicle);
}

void cAllLines::pushRow(cLine* line) {
	lines.push_back(line);
}

vector<cVehicle*> cAllLines::listVehicle() {
	vector<cVehicle*> listEnemy, tmp;
	for (int i = 0; (unsigned)i < lines.size(); i++) {
		tmp = lines[i]->getVehicle();
		listEnemy.insert(listEnemy.end(), tmp.begin(), tmp.end());
	}
	return listEnemy;
}

vector <cLine*> cAllLines::listRow() {
	return lines;
}

