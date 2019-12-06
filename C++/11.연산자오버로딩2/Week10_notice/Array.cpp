#include <iostream>
using namespace std;

#include <iomanip>
#include <cstdlib>

#include "Array.h"

Array::Array(int arraysize) {
	size = (arraysize > 0 ? arraysize : 10);
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

Array::Array(const Array& arrayToCopy) 
	:size(arrayToCopy.size)
{
	ptr = new int[size];
	for (int i = 0; i<size; i++) {
		ptr[i] = arrayToCopy.ptr[i];
	}
}

Array::~Array() {
	delete[] ptr;
}

int Array::getsize() const {
	return size;
}

// ��ȯ���� const�� �ִ� ���� �������� �ϱ�?
// ���ϰ��� �ٲܼ� ���� �ϱ� �����̴�(?)
// const return avoids: (a1 = a2) = a3 
const Array &Array::operator=(const Array &right) {
	if (&right != this) { //avoid self-assignment
		if (size != right.size) { // for arrays of different sizes, deallocate original
			delete[]ptr; //release space
			size = right.size;
			ptr = new int[size];
		}

		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i];
		}
	}
	return *this;
}

bool Array::operator==(const Array& right) const {
	if (size != right.size) return false;

	for (int i = 0; i < size; i++) {
		if (ptr[i] != right.ptr[i])
			return false;
	}

	return true;
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue. (������ ��ȯ�� '���� ������ lvaue'�� �����Ѵ�)
int& Array::operator[](int subscript) {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<" out of range" << '\n';
		exit(1);
	}
	return ptr[subscript];
}

//ȣ�� ���� �ʴ� �����ε�� �Լ��ε�??
// overloaded subscript operator fro const Arrays;
// const reference return creates an rvalue;
//int Array::operator[](int subscript) const {
//	if (subscript < 0 || subscript >= size) {
//		cerr << "\nError: Subscript " << subscript <<" out of range" << '\n';
//		exit(1);
//	}
//	return ptr[subscript];
//}

istream& operator>>(istream& input, Array &a) {
	for (int i = 0; i < a.size; i++)
		input >> a.ptr[i];
	return input;
}

ostream& operator<<(ostream& output, const Array& a) {
	int i;
	for (i = 0; i < a.size; i++) {
		output << setw(12) << a.ptr[i];
		if ((i + 1) % 4 == 0)
			output << '\n';
	}

	if (i % 4 != 0)
		output << '\n';

	return output;
}
