/* ���ø� ����� ���ʸ� Ÿ�� T*/
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char array[], int n)// �Լ� �ߺ� > ���ø� �Լ� : �ߺ��� �Լ��� �켱������ ���ε�
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