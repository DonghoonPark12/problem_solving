// Member and friend definitions for class Shape

#include "Shape.h"

// default constructor
Shape::Shape(double x, double y)
{
	xCenter = x;
	yCenter = y;
} // end Shape constructor

// return x from coordinate pair
double Shape::getCenterX() const
{
	return xCenter;
} // end function getCenterX

// return y from coordinate pair
double Shape::getCenterY() const
{
	return yCenter;
} // end function getCenterY

// overloaded output operator
ostream & operator<<(ostream &out, Shape &s)
{
	s.print();
	return out;
} // end overloaded output operator function