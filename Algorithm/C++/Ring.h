#include <iostream>
#include "Circle.h"
using namespace std;

class Ring {
private:
	Circle a;
	Circle b;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) 
		:a(x1, y1, r1), b(x2, y2, r2) //원 a의 반지름 초기화
	{
		//a.Init(x1,y1,r1);//원 a의 반지름 초기화
		//b.Init(x2, y2, r2);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		a.ShowCircleCenterInfo();
	
		cout << "Outer Circle Info..." << endl;
		b.ShowCircleCenterInfo();
	}
};

