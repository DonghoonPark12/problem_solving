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
	Point& operator++() { //����Լ��� �����ε�
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point &ref);//�����Լ��� �����ε� 

	//Point operator-(const Point &ref) {//������� ��ȣ�� �ݴ�� �ϴ� ��ü ��ȯ
	//	Point pos(-ref.xpos, -ref.ypos);
	//	return pos;
	//}

	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}

	friend Point operator~(const Point &ref);//��������� �ݴ�� �ǵ��� �����غ���
};

Point& operator--(Point & ref)//��ü �ڱ� �ڽ��� ������ �� �ִ� '���� ��'��ȯ
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;//pos�� �����ڸ� �״�� ��ȯ
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