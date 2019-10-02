#include <iostream>
using namespace std;

int &RefRetFuncOne(int &ref) {
	ref++;
	return ref;//num1의 참조자를 반환하였고
}

int main() {
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);//이를 다시 참조자가 받았다.
	
	num1++; num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}