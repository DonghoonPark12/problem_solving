#include <iostream>
using namespace std;

class AAA {
private:
	int num1 =0;
public:												  // (C++의 C에 비해 약간의 속도 저하의 원인)
	virtual void Func1() { cout << "Func1" << '\n'; } //한개 이상의 가상함수를 포함하는 클래스에 대해서는 컴파일러가 '가상함수 테이블(V-Table)'을 생성. 
	virtual void Func2() { cout << "Func2" << '\n'; } //★ 객체 생성과 동시에 테이블이 생성되는것이 아니고, 객체 생성과 상관 없이 메모리 공간에 할당.
};

class BBB : public AAA {
private:
	int num2 =0;
public:
	virtual void Func1() { cout << "BBB::Func1" << '\n'; } //하지만, 오버라이딩된 가상함수의 주소정보는 유도클래스의 가상함수 테이블에 존재하지 않는다. 
	void Func3() { cout << "Func3" << '\n'; }              //따라서 오버라이딩된 가상함수를 호출하면 무조건! 가장 마지막에 오버라이딩한 유도클래스 멤버함수가 호출되는 것이다.
};

int main() {
	AAA* aptr = new AAA(); //클래스 포인터 생성
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();

	return 0;

}