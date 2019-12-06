#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
/* 8진수 -> 2진수 */
int main() {
	vector<vector<int>> vv;
	vector<int> v;
	string str;
	int exp = 0;
	int _mod = 4;
	
	cin >> str;
	int _len = str.length();

	if (int(str[0] - '0') == 0) {
		cout << 0; return 0;
	}

	for (int i = _len - 1; i >= 0; i--) {
		int tmp = int(str[i] - '0');
		if (tmp != 0) {
			
			while (_mod != 0) {
				if ( tmp / _mod > 0) {
					v.push_back( tmp / _mod);
					tmp -= _mod;
				}
				else {
					v.push_back(0);
				}
				_mod /= 2;
			}
		}
		else {
			int n = 3;
			while (n--) 
				v.push_back(0);
		}
		vv.push_back(v); v.clear();
		_mod = 4;
	}
	if (!v.empty()) vv.push_back(v);

	_len = vv.size();
	bool flag = false;
	for (int i = _len - 1; i >= 0; i--) {
		int __len = vv[i].size();
		for (int j = 0; j < __len; j++) {
			if ( (i == _len - 1 && vv[i][j] == 0) && !flag ) continue;
			cout << vv[i][j]; flag = true;
		}
	}

	return 0;
}