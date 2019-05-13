#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#include <set>
#include <map>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	
	map<string, int> d;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		d[name] += 1;
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		d[name] += 1;
	}

	int ans = 0;
	for (auto p : d) {
		if (p.second == 2)
			ans += 1;
	}
	cout << ans << '\n';

	for (auto p : d) {
		if (p.second == 2)
			cout << p.first << '\n';
	}
	return 0;
}