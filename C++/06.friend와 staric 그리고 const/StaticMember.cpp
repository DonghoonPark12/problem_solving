#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
	Static ������ ��ü���� �����Ǵ� ������ �ƴ϶�
	��ü�� �����ϰ� �������� �ʰ�, �޸� ������ �� �ϳ��� �Ҵ��� �Ǿ �����Ǵ� ����(��� ��ü�� ����)
	��ü ���� �����ϴ� ���� �ƴϴ�. 
	�����ڿ� �ʱ�ȭ ���ִ� ���� �ƴϴ�. static ��������� �ʱ�ȭ�� ������ ���ش�. 

	Static �Լ� ���� Ŭ������ ��� ��ü�� ����
	������� ����, ����Լ� ȣ���� �Ұ���

	const static ��� ������ ����� ���ÿ� �ʱ�ȭ�� �����ϴ�. 
*/


class SoSimple {
	static int simObjCnt;
public:
	SoSimple()
	{	
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple��ü"<< endl;
	}
};

class SoComplex {
	static int cmxObjCnt;  
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex��ü" << endl;
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex��ü" << endl;
	}
};

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
}