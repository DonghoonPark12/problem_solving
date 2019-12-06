// Definition of base-class Shape
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using std::ostream;

class Shape {
	friend ostream & operator<<(ostream &, Shape &);
protected:
	double xCenter; // x part of coordinate pair
	double yCenter; // y part of coordinate pair
public:
	Shape(double = 0.0, double = 0.0); // default constructor
	double getCenterX() const; // return x from coordinate pair
	double getCenterY() const; // return y from coordinate pair
	virtual void print() const = 0; // output Shape object
}; // end class Shape

#endif
