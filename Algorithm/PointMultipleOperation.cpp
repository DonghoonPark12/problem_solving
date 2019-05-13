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
	Point operator*(int times) {
		Point pos(xpos*times, ypos*times);
		return pos;
	}
	friend Point operator*(int times, Point &ref);
};

Point operator*(int times, Point &ref) {
	Point pos(ref.xpos * times, ref.ypos * times);
	return pos;
}

//Point operator*(int times, Point &ref) {
//	return ref*times;
//}

int main() {
	Point pos(1, 2); //�̹� ������ ��ü
	Point cpy; //�̹� ������ ��ü

	cpy = pos * 3; //������ �ڷ����� �� ��ü�� ������� ���Կ����� �����ϴ�. �� ����� �ɹ� �� �ɹ��� ���簡 �Ͼ��.  
	cpy.ShowPosition(); //pos.operator*(3)

	//cpy = pos * 3 * 2;
	//cpy.ShowPosition();

	cpy = 3 * cpy; // ���»� operator*(int times, Point &ref) �� ȣ���ؾ� �Ѵ�. 
	cpy.ShowPosition(); //operator*(3, cpy)

	cpy = 2 * pos *3; // ( operator*(2, pos) )operator*(3)
	cpy.ShowPosition();
	return 0;
}
