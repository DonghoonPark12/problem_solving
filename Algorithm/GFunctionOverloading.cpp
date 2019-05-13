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
	friend Point operator+(const Point &pos1, const Point &pos2);//�����Լ� ������� �����ε�
	friend Point operator-(const Point &pos1, const Point &pos2);//�����Լ� ������� �����ε�
	friend Point operator*(const Point &pos1, const Point &pos2);//�����Լ� ������� �����ε�
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};
/*
* +�����ڸ� �����Լ��� ���·� �����ε� �Ͽ���. Point Ŭ������ �� �Լ��� ���ؼ� friend ������ �Ͽ����Ƿ�,
* �Լ� �������� Point Ŭ������ private ����� ������ �����ϴ�. 
* Point Point::operator+( ... )  �ƴѰ�?? 
*/
Point operator+(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);//���ο� ������ ��ü ����
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);//pos.xpos = pos1.xpos - pos2.xpos; pos.ypos = pos1.ypos - pos2.ypos �� ����.
	return pos;
}
Point operator*(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos * pos2.xpos, pos1.ypos * pos2.ypos);//���ο� ������ ��ü ����
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