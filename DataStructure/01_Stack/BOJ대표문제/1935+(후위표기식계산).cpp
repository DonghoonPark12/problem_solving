#include <iostream>
#include <stack>
using namespace std;
double alpha[26];
/*
	���� ǥ��� ����� Stack�� �̿��Ѵ�. 
*/
double cal(double r, double l, char c) {
	double ret = 0;
	if (c == '+') ret = l + r;
	else if (c == '-') ret = l - r;
	else if (c == '*') ret = l * r;
	else if (c == '/') ret = l / r;
	return ret;
}
int main() {
	stack<double> s; //1) double�� stack�� char���� ������ ������ �����. 
	int n, num; cin >> n;
	string str; cin >> str;
	int size = str.length();

	for (int i = 0; i < n; i++) //alpha[0] = 1, 2, 3, 4, alpha[4] = 5 �־ ������. 
		cin >> alpha[i];

	for (int i = 0; i < size; i++) {
		char c = str[i];
		if (c == '+' || c == '*' || c == '-' || c == '/') {
			double r = s.top(); s.pop();
			double l = s.top(); s.pop();
			s.push(cal(r, l, c));
		}
		else {
			//s.push(c);
			s.push(alpha[c - 'A']);
		}
	}
	printf("%.2lf", s.top());
	//cout << s.top();
	return 0;
}