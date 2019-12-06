#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/* 2진수 -> 8진수 */

int main() {
	vector<int> v;
	string str;
	int exp = 0;
	cin >> str;
	int _sum = 0;
	int len = str.length();
	for (int i = len -1; i >=0 ; i--) {
		if(str[i] - '0' == 1) _sum += pow(2, exp);
		exp++;

		if (exp == 3) {
			v.push_back(_sum);
			_sum = 0; exp = 0;
		}
	}
	if (_sum != 0) v.push_back(_sum);
	if (v.empty()) {
		cout << 0; return 0;
	}

	len = v.size();
	for (int i = len - 1; i >= 0; i--) {
		cout << v[i];
	}
	return 0;
}