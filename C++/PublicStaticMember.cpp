#include <iostream>
using namespace std;

class SoSimple {
public:
	static int simObjCnt;
public:
	SoSimple() {
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main() {
	cout << SoSimple::simObjCnt << "��° soSimple ��ü" << endl; //Ŭ������ �̸��� �̿��ؼ� �����ϴ� ���� ����. 
	SoSimple sim1;
	SoSimple sim2;

	cout << sim1.simObjCnt << "��° soSimple ��ü" << endl; //��������� �����ϴ� �Ͱ� ���� ������ �ҷ� ����Ų��. 
	cout << sim2.simObjCnt << "��° soSimple ��ü" << endl;
	return 0;
}
