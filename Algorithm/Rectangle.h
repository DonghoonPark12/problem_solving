#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectangle
{
private:
	Point upleft;
	Point lowRight;
public:
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
	void ShowRecInfo() const;
	
	//~Rectangle();
};

#endif