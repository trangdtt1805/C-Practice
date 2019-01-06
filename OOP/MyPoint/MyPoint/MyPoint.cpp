#include "MyPoint.h"
#include <iostream>
#include <math.h>

using namespace std;

MyPoint::MyPoint() {};

MyPoint::~MyPoint() {};

MyPoint::MyPoint(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}

void MyPoint::display() {
	cout << mPosX << "," << mPosY;
}

void MyPoint::setX(int x)
{
	this->mPosX = x;
}
int MyPoint::getX()
{
	return mPosX;
}
void MyPoint::setY(int y)
{
	this->mPosY = y;
}
int MyPoint::getY()
{
	return mPosY;
}
float MyPoint::distance(MyPoint *p)
{
	return sqrt(pow((mPosX - p->mPosX),2) + pow(mPosY - p->mPosY,2));
}
