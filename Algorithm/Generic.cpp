/* ���ø�(Generic) <-> ��üȭ */
/*
*
* ���ø��� ������ ���ʸ� �Լ���, ���ʸ� Ŭ������ ����� Ȱ���ϴ� ���ʸ� ���α׷���
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4, b = 5;
	myswap(a, b);
	cout << "a=" << a << "," << "b=" << b << endl;

	double c = 0.3, d = 12.5;
	myswap(a, b);
	cout << "a=" << a << "," << "b=" << b << endl;

	Circle dout(5), pizza(20);
	myswap(dout, pizza);
	cout << "dout������ = " << dout.getRadius() << ",";
	cout << "pizza������ = " << pizza.getRadius() << endl;

}