#include <iostream>
using namespace std;

class SoSimple{
private:
	int num;
public:
	SoSimple(int n): num(n)
	{ }
	SoSimple &AddNum(int n) {
		num += n;
		return *this;
	}
	void SimpleFunc() {
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const { //const 선언 유무도 함수 오버로딩 조건에 해당한다. 
		cout << "Const SimpleFunc: " << num << endl;
	}
};

void YouFunc(const SoSimple &obj) { //Const 참조자에 의한 객체전달(안전하고, 성능도 좋다).
	obj.SimpleFunc();
}

int main() {
	SoSimple obj1(2);        
	const SoSimple obj2(7); //일반 객체와 const객체를 각각 생성

	obj1.SimpleFunc();
	obj2.SimpleFunc(); //상수(const)객체는 const 멤버함수 만을 호출할 수 있다.

	YouFunc(obj1); //const 멤버함수 호출
	YouFunc(obj2); //const 멤버함수 호출

	return 0;
}