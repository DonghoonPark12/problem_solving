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
	//	setColor("BLACK");//Ŭ���� ���� ��ġ�� ����Լ�(�� ������ ȣ�� �������� ȣ�� �����ϴ�)
	//}
	ColorPoint(int x=0, int y=0, char *mycolor="BLACK")//1) �̰� �Ǵ� ����. char�����Ϳ� ���ڿ� �ʱ�ȭ�� �ٷ� �����ϴ�. 
		:Point(x, y)
	{
		//color = new char(sizeof(mycolor));
		//strcpy(color, mycolor);
		this->color = mycolor; //2) ���� �� �� ó�� ���� �Ҵ� ���ϰ� �ּ� �Ѱ��� �� �ִ�. 
		//this->name = mycolor;
	}
	void setPoint(int a, int b) {
		this->move(a, b);
	}
	void setColor(char *col) {
		this->color = col;
	}
	void show() {
		printf("%s������ (%d,%d)�� ��ġ�� ���Դϴ�\n", color, getX(), getY());
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