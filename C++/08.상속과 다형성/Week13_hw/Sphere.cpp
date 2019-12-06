// Member-function definitions for class Sphere
#include <iostream>
using std::cout;

#include "Sphere.h"

// default constructor
Sphere::Sphere(double r, double x, double y)
	: ThreeDimensionalShape(x, y)
{
	radius = ((r > 0.0) ? r : 0.0);
} // end Sphere constructor

// return area of Sphere
double Sphere::getArea() const
{
	return 4.0 * 3.14159 * radius * radius;
} // end function getArea

// return volume of Sphere
double Sphere::getVolume() const
{
	return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
} // end function getVolume

// return radius of Sphere
double Sphere::getRadius() const
{
	return radius;
} // end function getRadius

// output Sphere object
void Sphere::print() const
{
	cout << "Sphere with radius " << radius << "; center at ("
		<< xCenter << ", " << yCenter << ")";
} // end function print
