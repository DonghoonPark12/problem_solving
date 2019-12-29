#include <iostream>
using namespace std;

#include "Stack.h"

int main() {
	//Stack<double> doubleStack(5);
	//double doublevalue = 1.1;

	//while (doubleStack.push(doublevalue)) {
	//	cout << doublevalue << ' ';
	//	doublevalue += 1.1;
	//}
	//cout << '\n';
	////cout << "\n Stack is Full. " << doublevalue << '\n';

	//while (doubleStack.pop(doublevalue)) {
	//	cout << doublevalue << ' ';
	//}
	//cout << '\n';
	////cout << "\nStack is Empty. " << '\n';

	//Stack<int> intStack;
	//int intValue = 1;

	//while (intStack.push(intValue)) {
	//	cout << intValue << ' ';
	//	intValue += 1;
	//}
	//cout << '\n';
	//while (intStack.pop(intValue)) {
	//	cout << intValue << ' ';
	//}

	Stack<double> st1(5);
	double doublevalue = 1.1;
	while (st1.push(doublevalue)) {
		cout << doublevalue << ' ';
		doublevalue += 1.1;
	}
	cout << '\n';
	Stack<double> st2 = st1;
	while (st2.pop(doublevalue)) {
		cout << doublevalue << ' ';
	}
	cout << '\n';
	return 0;
 }
