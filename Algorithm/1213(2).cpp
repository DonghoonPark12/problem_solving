#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		int t; cin >> t;

		string str, f;
		cin >> f; cin >> str;
		int cnt = 0, start = 0, idx;
		while ((idx = str.find(f, start)) != -1) {
			start = idx + 1;
			cnt++;
		}
		cout << "#" << t << " " << cnt << "\n";
	}
	return 0;
}