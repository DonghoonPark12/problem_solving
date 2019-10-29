/* 템플릿 선언과 제너릭 타입 T*/
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char array[], int n)// 함수 중복 > 템플릿 함수 : 중복된 함수가 우선적으로 바인딩
{
	for (int i = 0; i < n; i++)
		cout << (int)array[i] << '\t';
	cout << endl;
}

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1, 2, 3, 4, 5 };
	print(c, 5);
	return 0;
}