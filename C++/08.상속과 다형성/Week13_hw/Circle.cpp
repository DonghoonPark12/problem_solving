// Member-function definitions for class Circle
#include <iostream>
using std::cout;

#include "Circle.h"

// default constructor
Circle::Circle(double r, double x, double y)
	: TwoDimensionalShape(x, y)
{
	radius = ((r > 0.0) ? r : 0.0);
} // end Circle constructor

// return radius of circle object
double Circle::getRadius() const
{
	return radius;
} // end function getRadius

// return area of circle object
double Circle::getArea() const
{
	return 3.14159 * radius * radius;
} // end function getArea

// output circle object
void Circle::print() const
{
	cout << "Circle with radius " << radius << "; center at ("
		<< xCenter << ", " << yCenter << ")";
} // end function print