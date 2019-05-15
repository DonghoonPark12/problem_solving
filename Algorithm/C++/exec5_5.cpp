#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
	// 1)
/*	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl*/;

	// 2)
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;//복사 생성
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 합한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 합한 값 " << n << endl;
}