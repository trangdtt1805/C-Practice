#pragma once

#include <iostream>

using namespace std;

class MyPoint
{

private:
	int mPosX;
	int mPosY;

public:
	MyPoint();
	~MyPoint();

	MyPoint(int, int);
	void display();
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	float distance(MyPoint *p);
};
