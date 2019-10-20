#include <iostream>
using namespace std;

class Point;

class PointOP {
private:
	int opcnt;
public:
	PointOP()
		:opcnt(0)
	{}

	Point PointAdd(const Point&, const Point&); //Point 객체를 반환하는 PointOP클래스의 멤버함수
	Point PointSub(const Point&, const Point&);
	~PointOP() {
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point {
private:
	int x, y;
public:
	Point(const int &xpos, const int &ypos)
		:x(xpos), y(ypos)
	{}
	//★ friend함수 프로토 타입이 Point 클래스내에 있더라도, Point함수의 멤버 함수는 아니다!!!

	friend Point PointOP::PointAdd(const Point &, const Point &); //PointOP클래스의 멤버함수를 대상으로 friend선언
	friend Point PointOP::PointSub(const Point &, const Point &); //Point <-- PointOP 멤버함수 접근 허용.
	friend void ShowPointPos(const Point &);                     //Point <-- 전역함수, 두가지 역할(ShowPointPos 전역함수가 존재한다. 해당 전역함수를 friend로 선언한다.)
};

Point PointOP::PointAdd(const Point &pnt1, const Point &pnt2){ //PointOP::PointAdd 멤버함수가 Point의 private 멤버에 접근 가능하다.
	opcnt++;												   //Point <-- PointOP::PointAdd
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point &pnt1, const Point &pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void ShowPointPos(const Point &pos) { //
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}

int main() {
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));

	return 0;
}
