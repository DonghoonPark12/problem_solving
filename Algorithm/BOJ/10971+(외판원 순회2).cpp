#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int  w[10][10];
bool vis[10];
int _min;
int start_city;
void dfs(int s, int cnt, int wsum) {
	if (cnt >= n) {
		if (w[s][start_city] != 0) {
			_min = min(_min, wsum + w[s][start_city]);
		}
		return;
	}
	for (int i = 0; i<n; i++) {
		if (vis[i] == false && w[s][i] != 0) {//s와 같은 i는 거른다. 왜냐하면 i->i는 비용이 없기 때문.
			vis[i] = true;
			dfs(i, cnt + 1, wsum + w[s][i]);
			vis[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> w[i][j];
		}
	}
	_min = 0x7fffffff;

	for (int s = 0; s<n; s++) {
		vis[s] = true;
		start_city = s;
		dfs(s, 1, 0);
		vis[s] = false;
	}
	cout << _min << '\n';

	//vector<int> d(n);
	//for (int i = 0; i < n; i++)
	//	d[i] = i;

	//do {
	//	bool ok = true;
	//	int sum = 0;
	//	for (int i = 0; i < n - 1; i++) {
	//		if (w[d[i]][d[i + 1]] == 0) ok = false;
	//		else sum += w[d[i]][d[i + 1]];
	//	}
	//	if (ok && w[d[n - 1]][d[0]] != 0) {
	//		sum += w[d[n - 1]][d[0]];
	//		if (_min > sum) _min = sum;
	//	}
	//} while (next_permutation(d.begin()+1, d.end()));
	//cout << _min;
	return 0;
}


//이하 백준 답
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int w[20][20];
//int main() {
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<n; j++) {
//			scanf("%d", &w[i][j]);
//		}
//	}
//
//	vector<int> d(n);
//	for (int i = 0; i<n; i++) {
//		d[i] = i;
//	}
//
//	int ans = 2147483647;
//
//	do {
//		bool ok = true;
//		int sum = 0;
//		for (int i = 0; i<n - 1; i++) {
//			if (w[d[i]][d[i + 1]] == 0) {
//				ok = false;
//			}
//			else {
//				sum += w[d[i]][d[i + 1]];
//			}
//		}
//		if (ok && w[d[n - 1]][d[0]] != 0) {
//			sum += w[d[n - 1]][d[0]];
//			if (ans > sum) ans = sum;
//		}
//	} while (next_permutation(d.begin(), d.end()));
//
//	printf("%d\n", ans);
//	return 0;
//}