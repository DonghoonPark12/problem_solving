#include <iostream>
#include <stack>
using namespace std;
double alpha[26];
/*
	후위 표기식 계산은 Stack을 이용한다. 
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
	stack<double> s; //1) double형 stack에 char형을 넣으니 문제가 됬었다. 
	int n, num; cin >> n;
	string str; cin >> str;
	int size = str.length();

	for (int i = 0; i < n; i++) //alpha[0] = 1, 2, 3, 4, alpha[4] = 5 넣어도 괜찮다. 
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