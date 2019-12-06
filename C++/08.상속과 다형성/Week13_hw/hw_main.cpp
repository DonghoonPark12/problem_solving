// Driver to test Shape hierarchy
#include <iostream> 
#include <vector>

using namespace std;

#include <typeinfo>

#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Square.h"
#include "Sphere.h"
#include "Cube.h"

int main()
{
	// create vector shapes
	vector < Shape * > shapes(4); //클래스 포인터를 벡터로 저장하는 것이 메모리 효율.

	// initialize vector with Shapes
	shapes[0] = new Circle(3.5, 6, 9); //upcasting
	shapes[1] = new Square(12, 2, 2);
	shapes[2] = new Sphere(5, 1.5, 4.5);
	shapes[3] = new Cube(2.2);

	// output Shape objects and display area and volume as appropriate
	for (int i = 0; i < 4; i++)
	{
		cout << *shapes[i] << endl;

		// downcast pointer
		TwoDimensionalShape *twoDimensionalShapePtr = dynamic_cast <TwoDimensionalShape *> (shapes[i]);

		// if Shape is a TwoDimensionalShape, display its area
		if (twoDimensionalShapePtr != 0) //??
			cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;

		// downcast pointer
		ThreeDimensionalShape *threeDimensionalShapePtr = dynamic_cast <ThreeDimensionalShape *> (shapes[i]);

		// if Shape is a ThreeDimensionalShape, display its area and volume
		if (threeDimensionalShapePtr != 0)
			cout << "Area: " << threeDimensionalShapePtr->getArea()
			<< "\nVolume: " << threeDimensionalShapePtr->getVolume()
			<< endl;

		cout << endl;
	} // end for

	return 0;
} // end main