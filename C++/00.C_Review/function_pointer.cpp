#include <iostream>
using namespace std;
/*
	�Լ� �����ʹ� �Լ��� �ּҸ� �����ϴ� ����
	����)
*/

void Print(int n) {
	cout << "Interger: " << n << '\n';
}

int main() {
	void (*pf)(int);
	pf = Print;

	Print(10); //1. �Լ� ȣ��
	pf(10); //2. �����͸� �̿��� �Լ� ȣ��
	(*pf)(10);

	cout << '\n';
	cout << Print << '\n' << pf << '\n' << *pf << '\n';

	return 0;
}


