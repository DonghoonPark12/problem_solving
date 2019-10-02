#include <iostream>
#include "Circle.h"
using namespace std;

class Ring {
private:
	Circle a;
	Circle b;
public:
	Ring();
	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
		Circle a(x1, y1, r1);
		Circle b(x2, y2, r2);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		a.ShowCircleCenterInfo();
	
		cout << "Outer Circle Info..." << endl;
		b.ShowCircleCenterInfo();
	}
};

