#include <iostream>
using namespace std;

/*
1. 전역변수에 선언된 static의 의미
  - 선언된 파일 내에서만 참조를 허용하겠다는 의미

2. 함수 내에 선언된 static의 의미
  - 한번만 초기화 되고, 전역변수가 저장되는 Data 영역에 저장되어 함수를 빠져나가도 소멸되지 않는다.
*/

//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple {
private:
	static int simObjCnt; //객체를 생성하건, 생성하지 않건 딱 하나만  할당되어 공유된다. 멤버 변수 아니다. Static변수 혹은 클래스 변수.
public:
	SoSimple() {
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;

//class SoComplex {
//private:
//	static int cmxObjCnt;
//public:
//	SoComplex() {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "번째 SoComplex객체" << endl;
//	}
//	SoComplex(SoComplex &copy) {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "번째 SoComplex객체" << endl;
//	}
//};
//int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}
