#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y);
	void AddPoint(const Point &pos);//����ü ������. �о� ���� ����ü�� ���� ������ �ٲ����� �ʴ´�. 
	void ShowPosition();

};


int main() {
	Point pos1 = { 12,4 }; //����ü ����(Ŭ���� ����)
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10); //����ü ���� �Լ� ȣ��(�ż��� ȣ��)
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