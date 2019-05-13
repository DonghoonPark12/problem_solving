/*
ù° �ٿ� �� ĭ�� ���̿� �ΰ� x(1��x��12)�� y(1��y��31)�� �־�����.
����� 2007�⿡�� 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���,
4, 6, 9, 11���� 30�ϱ���,
2���� 28�ϱ��� �ִ�.
*/
#include <iostream>
#include <string>
using namespace std;

void main() {
	string arr[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int mon[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int x, y;
	int day = 0;
	cin >> x >> y;
	for (int i = 1; i<x; i++) {
		day += mon[i];
	}
	day += y;
	cout << arr[(day % 7 + 6)%7] << endl;
	return;
}