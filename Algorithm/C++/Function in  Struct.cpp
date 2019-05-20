#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y);
	void AddPoint(const Point &pos);//구조체 참조자. 읽어 들인 구조체의 내부 변수를 바꾸지는 않는다. 
	void ShowPosition();

};


int main() {
	Point pos1 = { 12,4 }; //구조체 생성(클래스 생성)
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10); //구조체 내의 함수 호출(매서드 호출)
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();

	return 0;
}

void Point::MovePos(int x, int y) {
	xpos = xpos + x;
	ypos = ypos + y;
}

void Point::ShowPosition() {
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}

void Point::AddPoint(const Point &str) {
	xpos += str.xpos;
	ypos += str.ypos;
}