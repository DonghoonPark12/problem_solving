#define	_CRT_SECURE_NO_WARNINGS
#include <string>

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX(){return x;}
	int getY(){return y;}
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class ColorPoint : Point {
	char *color;
	//string name;
public:
	//ColorPoint()
	//	:Point(0, 0)
	//{
	//	//strcpy(color, "BLACK");
	//	setColor("BLACK");//클래스 내에 위치한 멤버함수(을 생성자 호출 시점에도 호출 가능하다)
	//}
	ColorPoint(int x=0, int y=0, char *mycolor="BLACK")//1) 이게 되는 구나. char포인터에 문자열 초기화가 바로 가능하다. 
		:Point(x, y)
	{
		//color = new char(sizeof(mycolor));
		//strcpy(color, mycolor);
		this->color = mycolor; //2) 위의 두 줄 처럼 동적 할당 안하고 주소 넘겨줄 수 있다. 
		//this->name = mycolor;
	}
	void setPoint(int a, int b) {
		this->move(a, b);
	}
	void setColor(char *col) {
		this->color = col;
	}
	void show() {
		printf("%s색으로 (%d,%d)에 위치한 점입니다\n", color, getX(), getY());
	}
};

int main() {
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5, "Red");
	cp.show();
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}