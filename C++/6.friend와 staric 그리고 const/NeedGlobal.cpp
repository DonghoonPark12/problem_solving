#include <iostream>
using namespace std;

/*
1. ���������� ����� static�� �ǹ�
  - ����� ���� �������� ������ ����ϰڴٴ� �ǹ�

2. �Լ� ���� ����� static�� �ǹ�
  - �ѹ��� �ʱ�ȭ �ǰ�, ���������� ����Ǵ� Data ������ ����Ǿ� �Լ��� ���������� �Ҹ���� �ʴ´�.
*/

//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple {
private:
	static int simObjCnt; //��ü�� �����ϰ�, �������� �ʰ� �� �ϳ���  �Ҵ�Ǿ� �����ȴ�. ��� ���� �ƴϴ�. Static���� Ȥ�� Ŭ���� ����.
public:
	SoSimple() {
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;

//class SoComplex {
//private:
//	static int cmxObjCnt;
//public:
//	SoComplex() {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "��° SoComplex��ü" << endl;
//	}
//	SoComplex(SoComplex &copy) {
//		cmxObjCnt++;
//		cout << cmxObjCnt << "��° SoComplex��ü" << endl;
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
