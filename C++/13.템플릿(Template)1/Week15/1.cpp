#include <iostream>
using namespace std;

template<typename T>
void printArray(const T* array, int count) {
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";
	}
	cout << '\n';
}

int main() {
	const int ACount = 5;
	const int BCount = 7;
	const int CCount = 6;

	int a[ACount] = { 1, 2, 3, 4, 5 };
	double b[BCount] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char c[CCount] = { "HELLO" };
	
	printArray(a, ACount);
	printArray(b, BCount);
	printArray(c, CCount);

	return 0;
}