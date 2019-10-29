#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point &pos1, const Point &pos2);//전역함수 기반으로 오버로딩
	friend Point operator-(const Point &pos1, const Point &pos2);//전역함수 기반으로 오버로딩
	friend Point operator*(const Point &pos1, const Point &pos2);//전역함수 기반으로 오버로딩
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};
/*
* +연산자를 전역함수의 형태로 오버로딩 하였다. Point 클래스는 이 함수에 대해서 friend 선언을 하였으므로,
* 함수 내에서는 Point 클래스의 private 멤버에 접근이 가능하다. 
* Point Point::operator+( ... )  아닌가?? 
*/
Point operator+(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);//새로운 포인터 객체 생성
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);//pos.xpos = pos1.xpos - pos2.xpos; pos.ypos = pos1.ypos - pos2.ypos 와 같다.
	return pos;
}
Point operator*(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos * pos2.xpos, pos1.ypos * pos2.ypos);//새로운 포인터 객체 생성
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2){
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point &pos1, const Point &pos2){
	return !(pos1 == pos2);
}

int main() {
	Point pos1(10, 20);
	Point pos2(3, 4); //Point pos3 = pos1.operator+(pos2);
	Point pos3 = pos1 + pos2;
	Point pos4 = pos1 - pos2;
	Point pos5 = pos1 * pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	return 0;
}