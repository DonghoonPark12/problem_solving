#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	stack<int> s; s.push(0);

	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(i);
		}

		while (!s.empty() && a[s.top()] < a[i]) {
			ans[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}

//int main() {
//	int n, in; cin >> n;
//	vector<int> v;
//	for (int i = 0; i < n; ++i) {
//		cin >> in; v.push_back(in);
//	}
//
//	int j;
//	for (int i = 0; i < n - 1; i++) {
//		for (j = i + 1; j < n; j++) {
//			if (v[i] < v[j]) { cout << v[j] << ' '; break; }
//		}
//		if (j == n) cout << -1 << ' ';
//	}
//	cout << -1;
//
//	return 0;
//}
