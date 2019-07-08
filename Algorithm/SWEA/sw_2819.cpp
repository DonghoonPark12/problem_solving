//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> arr(4, vector<int>(4));
//int main() {
//	int tc; int T;
//	cin >> T;
//	for (tc = 1; tc <= T; tc++) {
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 4; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//
//	}
//}

//#include <stdio.h>
//int C[10000000];
//int n = 4, A[5][5];
//int px[4] = { 1, -1, 0, 0 };
//int py[4] = { 0, 0, 1, -1 };
//void f(int x, int y, int z, int k) {
//	if (z == 7) {
//		C[k] = 1;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		if (1 <= x + px[i] && x + px[i] <= n && 1 <= y + py[i] && y + py[i] <= n)
//			f(x + px[i], y + py[i], z + 1, k * 10 + A[x + px[i]][y + py[i]]);
//	}
//}
//int main() {
//	int T; for (scanf("%d", &T); T--;) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				scanf("%d", &A[i][j]);
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				f(i, j, 1, A[i][j]);
//		}
//
//		int ans = 0;
//		for (int i = 0; i < 10000000; i++) {
//			ans += C[i];
//			C[i] = 0;
//		}
//		static int tc = 0;
//		printf("#%d %d\n", ++tc, ans);
//	}
//}

//격자판의 숫자 이어 붙이기
#include <iostream>
#include <set>
using namespace std;
char arr[4][4];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
set<string> s;

void init_input() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	s.clear();
}

void dfs(int y, int x, int cnt, string str) {
	if (y >= 4 || x >= 4 || y < 0 || x < 0) return;
	if (cnt == 7) {
		s.insert(str);
		return;
	}

	str += arr[y][x];

	for (int i = 0; i < 4; i++) {
		dfs(y + dy[i], x + dx[i], cnt + 1, str);
	}
}

int main() {
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int t = 0; t < T; t++) {
		init_input();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string str;
				dfs(i, j, 0, str);
			}
		}

		cout << "#" << (t + 1) << " " << s.size() << endl;
	}
}