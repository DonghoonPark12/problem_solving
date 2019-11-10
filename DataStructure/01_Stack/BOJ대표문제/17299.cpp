#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int freq[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}

	stack<int> s; s.push(0);

	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(i);
		}

		while (!s.empty() && freq[a[s.top()]] < freq[a[i]]) {
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

//int arr[1000001];
//int freq[1000001];
//int main() {
//	int n, in; cin >> n;
//	vector<pair<int, int> > p;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i]; freq[arr[i]]++;
//	}//1 1 2 3 2 1
//
//	for (int i = 0; i < n; ++i) {
//		p.push_back({ arr[i], freq[arr[i]]});
//	}
//
//	int j;
//	for (int i = 0; i < n - 1; i++) {
//		for (j = i + 1; j < n; j++) {
//			if (p[i].second < p[j].second) { cout << p[j].first << ' '; break; } //frequency¸¦ ºñ±³
//		}
//		if (j == n) cout << -1 << ' ';
//	}
//	cout << -1;
//
//	return 0;
//}