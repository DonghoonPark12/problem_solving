#include <iostream>
using namespace std;
int main() {
	
	//int a = 20; //a는 stack
	//int &ref = a; //ref는 heap?? 실행 되는 걸로 봐서는 stack

	int &ref = 20;//20이 heap에 저장되지 않는다. 그냥 컴파일 에러 난다. 
	int b = (int)ref;
	
	cout << ref << '\n';
	cout << &ref << '\n';
	//cout << &a << '\n';
}