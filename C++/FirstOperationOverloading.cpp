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
	Point operator+(const Point &ref){
		Point pos(xpos + ref.xpos , ypos + ref.ypos);//새로운 포인터 객체 생성
		return pos;
	}
	Point operator-(const Point &ref){
		Point pos(xpos - ref.xpos , ypos - ref.ypos);//새로운 포인터 객체 생성
		return pos;
	}
	Point operator*(const Point &ref){
		Point pos(xpos * ref.xpos , ypos * ref.ypos);//새로운 포인터 객체 생성
		return pos;
	}
	Point& operator+=(const Point &ref){
		xpos += ref.xpos; 
		ypos += ref.ypos;
		return *this;//pos1의 참조자를 반환
	}
	Point& operator-=(const Point &ref){
		xpos -= ref.xpos; 
		ypos -= ref.ypos;
		return *this;
	}
};

int main() {
	Point pos1(10, 20);
	Point pos2(3, 4);
	Point pos3 = pos1 + pos2;
	Point pos4 = pos1 - pos2;
	Point pos5 = pos1 * pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();

	(pos1 += pos2).ShowPosition();
	(pos1 -= pos2).ShowPosition();
	return 0;
}