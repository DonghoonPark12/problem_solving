#include <iostream>

int main() {
	const int num = 12;

	const int *ptr = &num;//const 변수는 포인터로 가리킬 때 const 붙여줘야 한다. 
	const int *(&pref) = ptr; //const로 선언된 포인터 변수를 참조하는 참조자를 선언 할 때에도 const를 붙여줘야 한다.

	std::cout << *ptr << std::endl;
	std::cout << *(pref) << std::endl; //포인터 변수의 다른 이름
}