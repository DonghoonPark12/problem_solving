// Definition of class Cube
#ifndef CUBE_H
#define CUBE_H

#include "ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape
{
public:
	// default constructor
	Cube(double = 0.0, double = 0.0, double = 0.0);

	virtual double getArea() const; // return area of Cube object
	virtual double getVolume() const; // return volume of Cube object
	double getSideLength() const; // return length of sides 
	void print() const; // output Cube object
private:
	double sideLength; // length of sides of Cube
}; // end class Cube

#endif
