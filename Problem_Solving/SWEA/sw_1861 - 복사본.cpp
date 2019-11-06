#include <iostream>
#include <cstdio>
#include <cmath>
int T, N, a, test, chk[1000001][2], p, max, l, lp;
int main() {
	int i, j;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test = 1; test <= T; test++) {
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &a);
				chk[a][0] = i; chk[a][1] = j;
			}
		}
		//max = p = l = lp = 1;
		max = l = 1;
		for (i = 2; i <= N*N; i++) {
			//x위치가 같으면서 && (y위치는 1이 차이가 나면)
			if (chk[i][0] == chk[i - 1][0] && abs(chk[i][1] - chk[i - 1][1]) == 1) {
				l++;
				if (l>max) {
					max = l;
					//p = lp;
				}
			}
			//y위치가 같으면서 && x위치는 1이 차이가 나면
			else if (chk[i][1] == chk[i - 1][1] && abs(chk[i][0] - chk[i - 1][0] == 1)) {
				l++;
				if (l>max) {
					max = l;
					//p = lp;
				}
			}
			else {
				l = 1;
				//lp = i;
			}
		}
		printf("#%d %d\n", test,max);
	}
	return 0;
}

//#include <iostream>
//#include <stdio.h>
//#define MAX_N 1000
//#define DIR 4
//#define X 0
//#define Y 1
//using namespace std;
//int N;
//int map[2][MAX_N*MAX_N + 1];
//int abs(int a, int b) {
//	if (a>b) { return (a - b); }
//	return (b - a);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	int T;
//	scanf("%d", &T);
//	for (int tc = 1; tc <= T; tc++) {
//		scanf("%d", &N);
//		for (int i = 1; i<N+1; i++) {
//			for (int j = 1; j<N+1; j++) {
//				int num;
//				scanf("%d", &num);
//				map[X][num] = i;
//				map[Y][num] = j;
//			}
//		}
//		int ans = 1;
//		int cnt = 1;
//		int x = map[X][1];
//		int y = map[Y][1];
//		int len = 1, sp = 1;
//		for (int i = 2; i <= (N*N); i++) {
//			int xx = map[X][i];
//			int yy = map[Y][i];
//			if ((abs(x, xx) + abs(y, yy)) == 1) {
//				len++;
//				if (len>cnt) { 
//					cnt = len; ans = sp; 
//				}
//			}
//			else {
//				len = 1;
//				sp = i;
//				if ((N*N - i)<cnt) { break; } // What is the meaning of this line??
//			}
//			x = map[X][i];
//			y = map[Y][i];
//		}
//		printf("#%d %d %d\n", tc, ans, cnt);
//	}
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int t, n;
//int map[1002][1002];
//int d[1002][1002];
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//void dfs(int x, int y) {
//	d[x][y] = 1;
//
//	for (int i = 0; i < 4; i++) {
//		int ax = x + dx[i]; //아, 위, 오, 왼
//		int ay = y + dy[i];
//
//		if (map[ax][ay] == 0) continue;
//
//		if (map[ax][ay] == map[x][y] + 1) {
//
//			if (d[ax][ay] == 0)
//				dfs(ax, ay);
//
//			d[x][y] = max(d[x][y], d[ax][ay] + 1);
//		}
//	}
//}
//
//void get_result(int tc) {
//	int cnt = 0;
//	int num = 987654321;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (cnt < d[i][j]) {
//				cnt = d[i][j];
//				num = map[i][j];
//			}
//			else if (cnt == d[i][j]) {
//				num = min(num, map[i][j]);
//			}
//		}
//	}
//
//	cout << "#" << tc << " " << num << " " << cnt << "\n";
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	cin >> t;
//	for (int tc = 1; tc <= t; tc++) {
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				cin >> map[i][j];
//				d[i][j] = 0;
//			}
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (d[i][j] == 0) dfs(i, j);
//			}
//		}
//		get_result(tc);
//
//	}
//	return 0;
//}


//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int x[4] = {-1,1,0,0};
//int y[4] = { 0,0,1,-1 };
//
//int n;
//int max;
//int arr[1001][1001];
//
//int search(int j, int i, int cnt) {
//	if (max < cnt) max = cnt;
//	for (int k = 0; k < 4; k++) {
//		//cout << j + y[k] << ' ' << i + x[k]  << endl;//왼, 오, 아, 위
//		if (( (j + y[k] >= 0 && j + y[k] < n) && (i + x[k] >= 0 && i + x[k] < n)  )) {
//
//			if ((arr[j + y[k]][i + x[k]] - arr[j][i]) == 1) {
//				cout << arr[j + y[k]][i + x[k]] << arr[j][i] << endl;
//				search(j + y[k], i + x[k], cnt + 1);
//			}
//		}
//	}
//	return max;
//}
////int is_range(int k)
//int main(void)
//{
//	int T, test_case;
//
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int Answer = 0;
//		cin >> n;
//		memset(arr, 0, sizeof(arr));
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//		int value = 0;
//		for (int j = 0; j < n; j++) {
//			for (int i = 0; i < n; i++) {
//				max = 0; 
//				max = search(j, i, 1);
//				if (max > Answer) {
//					value = arr[j][i];
//					Answer = max;
//				}
//			}
//		}
//		printf("#%d ", test_case + 1);
//		printf("%d %d\n", value, Answer);
//	}
//
//	return 0;
//
//}