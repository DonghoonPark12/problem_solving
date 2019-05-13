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
	Point pos(1, 2); //이미 생성된 객체
	Point cpy; //이미 생성된 객체

	cpy = pos * 3; //동일한 자료형의 두 객체를 대상으로 대입연산이 가능하다. 그 결과로 맴버 대 맴버의 복사가 일어난다.  
	cpy.ShowPosition(); //pos.operator*(3)

	//cpy = pos * 3 * 2;
	//cpy.ShowPosition();

	cpy = 3 * cpy; // 형태상 operator*(int times, Point &ref) 를 호출해야 한다. 
	cpy.ShowPosition(); //operator*(3, cpy)

	cpy = 2 * pos *3; // ( operator*(2, pos) )operator*(3)
	cpy.ShowPosition();
	return 0;
}
