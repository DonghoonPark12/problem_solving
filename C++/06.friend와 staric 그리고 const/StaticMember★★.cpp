#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
	<용어 주의>
	(1) 정적(Static) 멤버 변수
	(2) 정적(Static) 멤버 함수
	(3) 상수(Constant) 멤버 변수 
	    - 사용법 : 한번 초기화 하면 그 값을 변경할 수 없으며 선언 시점에 초기화 한다. 
		           (혹여나 컴파일러가 상수멤버 변수를 선언 시점 초기화 지원하지 않는다면 아래의 [Tips]를 따르도록 한다.)
		- 문법 : const 타입 멤버변수이름;
		- 변경이 없어야 하는 멤버는 const로 선언 하는 것이 안정적.

	(4) 상수(Constant) 멤버 함수
		- 문법 : 함수 선언/원형 const;

	Static 변수는 객체별로 유지되는 변수가 아니라
	객체를 생성하건 생성하지 않건, 메모리 공간에 딱 하나만 할당이 되어서 공유되는 변수(모든 객체가 공유)
	객체 내에 존재하는 것은 아니다. 
	[Tips] 생성자에 초기화 해주는 것이 아니다. static 멤버변수의 초기화는 별도로 해준다. 

	Static 함수 또한 클래스의 모든 객체가 공유
	멤버변수 접근, 멤버함수 호출이 불가능

	const static 멤버 변수는 선언과 동시에 초기화가 가능하다. 

	★★ <Static 멤버 함수>에 관한 것은 9장 9_10번 문제 참고.
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
int SoSimple::simObjCnt = 0; // ★★정적 멤버 변수의 정의(선언이 아니다!!) 및 초기화. 반드시 해줘야 한다. 안 하면 컴파일 에러 생김

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
int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex(); //클래스에 ()를 하는 것은 단순 생성자 호출인가???
}