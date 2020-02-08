#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
	<��� ����>
	(1) ����(Static) ��� ����
	(2) ����(Static) ��� �Լ�
	(3) ���(Constant) ��� ���� 
	    - ���� : �ѹ� �ʱ�ȭ �ϸ� �� ���� ������ �� ������ ���� ������ �ʱ�ȭ �Ѵ�. 
		           (Ȥ���� �����Ϸ��� ������ ������ ���� ���� �ʱ�ȭ �������� �ʴ´ٸ� �Ʒ��� [Tips]�� �������� �Ѵ�.)
		- ���� : const Ÿ�� ��������̸�;
		- ������ ����� �ϴ� ����� const�� ���� �ϴ� ���� ������.

	(4) ���(Constant) ��� �Լ�
		- ���� : �Լ� ����/���� const;

	Static ������ ��ü���� �����Ǵ� ������ �ƴ϶�
	��ü�� �����ϰ� �������� �ʰ�, �޸� ������ �� �ϳ��� �Ҵ��� �Ǿ �����Ǵ� ����(��� ��ü�� ����)
	��ü ���� �����ϴ� ���� �ƴϴ�. 
	[Tips] �����ڿ� �ʱ�ȭ ���ִ� ���� �ƴϴ�. static ��������� �ʱ�ȭ�� ������ ���ش�. 

	Static �Լ� ���� Ŭ������ ��� ��ü�� ����
	������� ����, ����Լ� ȣ���� �Ұ���

	const static ��� ������ ����� ���ÿ� �ʱ�ȭ�� �����ϴ�. 

	�ڡ� <Static ��� �Լ�>�� ���� ���� 9�� 9_10�� ���� ����.
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
int SoSimple::simObjCnt = 0; // �ڡ����� ��� ������ ����(������ �ƴϴ�!!) �� �ʱ�ȭ. �ݵ�� ����� �Ѵ�. �� �ϸ� ������ ���� ����

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
int SoComplex::cmxObjCnt = 0;

int main() {
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex(); //Ŭ������ ()�� �ϴ� ���� �ܼ� ������ ȣ���ΰ�???
}