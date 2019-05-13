#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) 
		:xpos(x), ypos(y)
	{ }
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++() { //멤버함수로 오버로딩
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point &ref);//전역함수로 오버로딩 

	//Point operator-(const Point &ref) {//멤버변수 부호를 반대로 하는 객체 반환
	//	Point pos(-ref.xpos, -ref.ypos);
	//	return pos;
	//}

	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}

	friend Point operator~(const Point &ref);//멤버변수가 반대로 되도록 정의해보자
};

Point& operator--(Point & ref)//객체 자기 자신을 참조할 수 있는 '참조 값'반환
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;//pos의 참조자를 그대로 반환
}

//Point& operator~(Point & ref)
//{
//	int tmp = ref.xpos;
//	ref.xpos = ref.ypos;
//	ref.ypos = tmp;
//	return ref;
//}

Point operator~(const Point &ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main() {
	Point pos1(1, 2);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();
	Point pos3 = ~pos1;
	pos3.ShowPosition();
	(~pos3).ShowPosition();
	return 0;
}