#include <iostream>
#include <cstring>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2); //참조자 이지만 const가 붙었기 때문에 상수 참조가 가능하다. 

int main() {
	Point *p1 = new Point{ 3, 5 };//구조체 변수 선언(동적 할당)
	Point *p2 = new Point{ 4, 5 };

	/* 	동적 할당된 메모리 공간도 변수로 간주하여 참조자의 선언이 가능하다.	*/
	Point &p = PntAdder(*p1, *p2);//주소를 참조자가 받는다. 
	std::cout << p.xpos << ' ' << p.ypos << std::endl;
	delete p1;
	delete p2;
	delete &p;

	return 0;
}

/*
const Point &pref1, const Point &pref2 일 경우: pref1,pref2가 포인터 변수 p1,p2를 참조하는 것이 아니라 구조체 p1,p2를 참조한다.
const Point *&p1, const Point *&p2 일 경우: pref1,pref2가 포인터 변수 p1,p2를 참조한다. 에러가 떴다. 
*/

Point &PntAdder(const Point &pref1, const Point &pref2) { 
	Point *p3 = new Point;                             
	p3->xpos= pref1.xpos + pref2.xpos;
	p3->ypos= pref1.ypos + pref2.ypos;

	return *p3;
}