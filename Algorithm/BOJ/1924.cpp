/*
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다.
참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지,
4, 6, 9, 11월은 30일까지,
2월은 28일까지 있다.
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