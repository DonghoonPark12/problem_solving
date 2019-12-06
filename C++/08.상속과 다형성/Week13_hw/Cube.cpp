// Member-function definitions for class Cube
#include <iostream>
using std::cout;

#include "Cube.h"

// default constructor
Cube::Cube(double s, double x, double y)
	: ThreeDimensionalShape(x, y)
{
	sideLength = ((s > 0.0) ? s : 0.0);
} // end Cube constructor

// return area of Cube
double Cube::getArea() const
{
	return 6 * sideLength * sideLength;
} // end function getArea

// return volume of Cube
double Cube::getVolume() const
{
	return sideLength * sideLength * sideLength;
} // end function getVolume

// return length of sides
double Cube::getSideLength() const
{
	return sideLength;
} // end function getSideLength

// output Cube object
void Cube::print() const
{
	cout << "Cube with side length " << sideLength << "; center at ("
		<< xCenter << ", " << yCenter << ")";
} // end function print
