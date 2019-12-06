#include <iostream>
using namespace std;
/*
	함수 포인터는 함수의 주소를 저장하는 변수
	예시)
*/

void Print(int n) {
	cout << "Interger: " << n << '\n';
}

int main() {
	void (*pf)(int);
	pf = Print;

	Print(10); //1. 함수 호출
	pf(10); //2. 포인터를 이용한 함수 호출
	(*pf)(10);

	cout << '\n';
	cout << Print << '\n' << pf << '\n' << *pf << '\n';

	return 0;
}


