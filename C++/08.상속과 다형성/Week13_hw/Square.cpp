// Member-function definitions for class Square
#include <iostream>
using std::cout;

#include "Square.h"

// default constructor
Square::Square(double s, double x, double y)
	: TwoDimensionalShape(x, y)
{
	sideLength = ((s > 0.0) ? s : 0.0);
} // end Square constructor

// return side of Square
double Square::getSideLength() const
{
	return sideLength;
} // end function getSideLength

// return area of Square
double Square::getArea() const
{
	return sideLength * sideLength;
} // end function getArea

// output Square object
void Square::print() const
{
	cout << "Square with side length " << sideLength << "; center at ("
		<< xCenter << ", " << yCenter << ")";
} // end function print