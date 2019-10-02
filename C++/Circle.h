#include <iostream>
#include "Point2.h"

class Circle {
private:
	Point2 center; //xpos, ypos : 원의 중심
	int radius; //반지름
public:
	Circle (int x, int y, int r)
		:radius(r), center(x,y)
	{ }
	void ShowCircleCenterInfo() const{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();//Point의 x, y 좌표 표현
	}
};
