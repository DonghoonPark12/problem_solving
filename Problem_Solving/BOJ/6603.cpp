#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> k;
vector<int> pick;
void dfs(int cnt) {
	if (pick.size() == 6) {
		for (int i = 0; i < pick.size(); i++) {
			cout << pick[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = cnt; i < k.size(); ++i) { //0, 1, 2
		pick.push_back(k[i]);//0 , 1, 2
		dfs(i + 1);//dfs(1), dfs(2), dfs(3)
		pick.pop_back();
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		int t;
		k.clear();
		for (int i = 0; i < n; i++) {
			cin >> t;
			k.push_back(t);
		}
		dfs(0);
		cout << "\n";
	}
	return 0;
}

//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//void solve(int n) {
//	int c[n] = { 0, };
//	for (int i = 0; i<6; i++) c[i] = 1;
//	int a[n];
//	for (int i = 0; i<n; i++) scanf("%d", &a[i]);
//	do {
//		for (int i = 0; i<n; i++) {
//			if (c[i]) printf("%d ", a[i]);
//		}
//		printf("\n");
//	} while (prev_permutation(c, c + n));
//	printf("\n");
//}
//
//int main() {
//	int n;
//	while (true) {
//		scanf("%d", &n);
//		if (n == 0) break;
//		solve(n);
//	}
//	return 0;
//}
