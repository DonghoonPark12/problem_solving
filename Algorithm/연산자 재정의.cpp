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

bool operator > (Circle op1, Circle op2) // > 연산자 재정의
{
	return op1.getRadius() > op2.getRadius(); // op1과 op2의 radius를 비교한다.
}

int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza); //반환되는 것이 뭐??? y에 직접 입력 해도 되나??
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}