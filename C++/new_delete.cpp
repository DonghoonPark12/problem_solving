#include <iostream>
#include <cstring>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2); //������ ������ const�� �پ��� ������ ��� ������ �����ϴ�. 

int main() {
	Point *p1 = new Point{ 3, 5 };//����ü ���� ����(���� �Ҵ�)
	Point *p2 = new Point{ 4, 5 };

	/* 	���� �Ҵ�� �޸� ������ ������ �����Ͽ� �������� ������ �����ϴ�.	*/
	Point &p = PntAdder(*p1, *p2);//�ּҸ� �����ڰ� �޴´�. 
	std::cout << p.xpos << ' ' << p.ypos << std::endl;
	delete p1;
	delete p2;
	delete &p;

	return 0;
}

/*
const Point &pref1, const Point &pref2 �� ���: pref1,pref2�� ������ ���� p1,p2�� �����ϴ� ���� �ƴ϶� ����ü p1,p2�� �����Ѵ�.
const Point *&p1, const Point *&p2 �� ���: pref1,pref2�� ������ ���� p1,p2�� �����Ѵ�. ������ ����. 
*/

Point &PntAdder(const Point &pref1, const Point &pref2) { 
	Point *p3 = new Point;                             
	p3->xpos= pref1.xpos + pref2.xpos;
	p3->ypos= pref1.ypos + pref2.ypos;

	return *p3;
}