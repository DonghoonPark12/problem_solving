// Definition of class TwoDimensionalShape
#ifndef TWODIM_H
#define TWODIM_H

#include "Shape.h"

class TwoDimensionalShape : public Shape
{
public:
	// default constructor
	TwoDimensionalShape(double x, double y) : Shape(x, y) { }

	virtual double getArea() const = 0; // area of TwoDimensionalShape
}; // end class TwoDimensionalShape

#endif
