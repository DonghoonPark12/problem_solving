/* 템플릿(Generic) <-> 구체화 */
/*
*
* 템플릿을 가지고 제너릭 함수나, 제너릭 클래스를 만들고 활용하는 제너릭 프로그래밍
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
	cout << "dout반지름 = " << dout.getRadius() << ",";
	cout << "pizza반지름 = " << pizza.getRadius() << endl;

}