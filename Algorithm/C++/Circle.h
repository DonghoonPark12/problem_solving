#include <iostream>
#include "Point2.h"

class Circle {
private:
	Point2 center; //xpos, ypos : ���� �߽�
	int radius; //������
public:
	Circle (int x, int y, int r)
		:radius(r), center(x,y)
	{
		//radius = r;		
		//center.Init(x, y);
	}
	void ShowCircleCenterInfo() const{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();//Point�� x, y ��ǥ ǥ��
	}
	/*
	void ShowCirclePointInfo() {
		center.ShowPointInfo();//Point�� x, y ��ǥ ǥ��
	}
	*/
};
