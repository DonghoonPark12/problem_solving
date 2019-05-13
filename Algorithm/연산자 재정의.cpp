#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) {this->radius = radius;}
	int getRadius() { return radius; }
};

template<typename T>
T bigger(T a, T b){
	if (a > b) return a;
	else return b;
}

bool operator > (Circle op1, Circle op2) // > ������ ������
{
	return op1.getRadius() > op2.getRadius(); // op1�� op2�� radius�� ���Ѵ�.
}

int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20�� 50�� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza); //��ȯ�Ǵ� ���� ��??? y�� ���� �Է� �ص� �ǳ�??
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
}