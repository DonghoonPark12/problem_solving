#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, in; cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> in; v.push_back(in);
	}

	int j;
	for (int i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] < v[j]) { cout << v[j] << ' '; break; }
		}
		if (j == n) cout << -1 << ' ';
	}
	cout << -1;

	return 0;
}