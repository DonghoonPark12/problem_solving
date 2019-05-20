#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
	Static 변수는 객체별로 유지되는 변수가 아니라
	객체를 생성하건 생성하지 않건, 메모리 공간에 딱 하나만 할당이 되어서 공유되는 변수(모든 객체가 공유)
	객체 내에 존재하는 것은 아니다. 
	생성자에 초기화 해주는 것이 아니다. static 멤버변수의 초기화는 별도로 해준다. 

	Static 함수 또한 클래스의 모든 객체가 공유
	멤버변수 접근, 멤버함수 호출이 불가능

	const static 멤버 변수는 선언과 동시에 초기화가 가능하다. 
*/


class SoSimple {
	static int simObjCnt;
public:
	SoSimple()
	{	
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple객체"<< endl;
	}
};

class SoComplex {
	static int cmxObjCnt;  
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex객체" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex객체" << endl;
	}
};

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
}