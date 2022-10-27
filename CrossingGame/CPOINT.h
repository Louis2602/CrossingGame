#pragma once
#ifndef CPOINT
#define CPOINT

class cPoint {
	int x, y;
public:
	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	cPoint() {}
	cPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~cPoint() {};
};

#endif // !CPOINT

