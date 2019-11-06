#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];
int freq[1000001];
int main() {
	int n, in; cin >> n;
	vector<pair<int, int> > p;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; freq[arr[i]]++;
	}//1 1 2 3 2 1

	for (int i = 0; i < n; ++i) {
		p.push_back({ arr[i], freq[arr[i]]});
	}

	int j;
	for (int i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (p[i].second < p[j].second) { cout << p[j].first << ' '; break; } //frequency¸¦ ºñ±³
		}
		if (j == n) cout << -1 << ' ';
	}
	cout << -1;

	return 0;
}