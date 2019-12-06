// Definition of class ThreeDimensionalShape
#ifndef THREEDIM_H
#define THREEDIM_H

#include "Shape.h"

class ThreeDimensionalShape : public Shape
{
public:
	// default constructor
	ThreeDimensionalShape(double x, double y) : Shape(x, y) { }

	virtual double getArea() const = 0; // area of 3-dimensional shape
	virtual double getVolume() const = 0; // volume of 3-dimensional shape
}; // end class ThreeDimensionalShape

#endif