#include <iostream>
using namespace std;

int &RefRetFuncOne(int &ref) {
	ref++;
	return ref;//num1�� �����ڸ� ��ȯ�Ͽ���
}

int main() {
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);//�̸� �ٽ� �����ڰ� �޾Ҵ�.
	
	num1++; num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}