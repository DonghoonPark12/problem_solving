// Definition of class Sphere
#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape
{
public:
	// default constructor
	Sphere(double = 0.0, double = 0.0, double = 0.0);

	virtual double getArea() const; // return area of Sphere
	virtual double getVolume() const; // return volume of Sphere
	double getRadius() const; // return radius of Sphere
	void print() const; // output Sphere object
private:
	double radius; // radius of Sphere
}; // end class Sphere

#endif
