#pragma once
#ifndef CPOINT
#define CPOINT

class cPoint {
	int x, y;
public:
	void setX(int x);
	void setY(int y);
	void setXY(int dx, int dy);
	int getX();
	int getY();
	cPoint();
	cPoint(int x, int y);
	~cPoint();
};

#endif // !CPOINT