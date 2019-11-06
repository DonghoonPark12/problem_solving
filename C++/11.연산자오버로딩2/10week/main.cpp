#include <iostream>
using namespace std;

#include "Array.h"

int main() {
	Array integers1(7);
	Array integers2;

	cout << "Size of Array integers1 is" 
		<< integers1.getsize() 
		<< "\nArray after initialization:\n" << integers1;

	cout << "Size of Array integers2 is" 
		<< integers2.getsize() <<
		"\nArray after initialization:\n" << integers2;

	cout << "\nEnter 17 integers:" << '\n';
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Array contain:\n"
		<< "integers1:\n" << integers1
		<< "integers2:\n" << integers2;

	cout << "\nEvaluating : integers1 != integers2" << '\n';
	if (integers1 != integers2)
		cout << "integers1 and integers2 are not equal" << '\n';

	Array integers3(integers1);

	cout << "\nSize of Array integer3 is "
		<< integers3.getsize()
		<<"\nArray after initialization:\n"<<integers3;

	cout << "Assigning integer2 to integer1" << endl;
	integers1 = integers2;

	cout << "integers1:\n" << integers1
		<< "integers2:\n" << integers2;

	cout << "Evaluating: intergers1 == integers2" << endl;
	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal" << endl;

	cout << "\nintegers1[5] is " << integers1[5]; //int& Array::operator[](int subscript)

	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	cout << "Attempt to assign 1000 to integers1[15]" << endl;
	integers1[15] = 1000;
	return 0;
}