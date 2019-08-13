//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//using namespace std;
//
//const int dx[4] = { -1, 1, 0, 0 };
//const int dy[4] = { 0, 0, -1, 1 };
//
//typedef struct XY {
//	int y, x;
//}xy;
//
//vector<xy> virus; 
//vector<xy> clearp;
//
//vector<vector<int>> map(8, vector<int>(8));
//vector<vector<int>> map_old(8, vector<int>(8));
//
//int n, m;
//int Max; //안전 영역의 최대 크기 갱신 변수
//int cnt;
//
//queue<xy> q;
//
//int get_area() {
//	int ret = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 0) ret++;
//		}
//	}
//	return ret;
//}
//
//void BFS() {
//	int size;
//
//	while (!q.empty()) {
//		size = q.size();//?
//		for (int i = 0; i < size; i++) {
//			int nx = q.front().x;
//			int ny = q.front().y;
//			q.pop();
//
//			for (int j = 0; j < 4; j++) {
//				int nx2 = nx + dx[j];
//				int ny2 = ny + dy[j];
//
//				if (nx2 < 0 || ny2 < 0 || n <= nx2 || m <= ny2) continue;
//				if (map[ny2][nx2] == 1 || map[ny2][nx2]) continue;
//
//				map[ny2][nx2] = 2;
//				q.push({ ny2, nx2 });
//			}
//		}
//
//	}
//}
//
//void dfs(int idx, int num) {
//	if (num == 3) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				map_old[i][j] = map[i][j];
//			}
//		}
//
//		for (int i = 0; i < virus.size(); i++) {
//			q.push({ virus[i].y, virus[i].x });
//		}
//
//		BFS();
//		cnt = get_area();
//		Max = max(Max, cnt);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				map[i][j] = map_old[i][j];
//			}
//		}
//		return;
//	}
//
//	for (int i = 0; i < clearp.size(); i++) {
//		int cx = clearp[i].x;
//		int cy = clearp[i].y;
//
//		map[cy][cx] = 1;
//		dfs(i, num + 1);
//		map[cy][cx] = 0;
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 2)
//				virus.push_back({ i,j });
//			if (map[i][j] == 0)
//				clearp.push_back({ i,j });
//		}
//	}
//
//	Max = 0;
//
//	for (int i = 0; i < clearp.size(); i++) {
//		int cx = clearp[i].x;
//		int cy = clearp[i].y;
//
//		map[cy][cx] = 1; //한 지점에 벽을 세우고.
//		dfs(i, 1);
//		map[cy][cx] = 0;
//	}
//	cout << Max;
//	return 0;
//}
//

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m, safe = -3, virus_num = 1e9;
int map[8][8];
bool c[8][8];

typedef struct XY {
	int y, x;
}xy;

vector<xy> virus;

const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

int dfs(int x, int y) {
	int res = 1;
	c[x][y] = true;
	for (int i = 0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (c[nx][ny] || map[nx][ny]) continue;
		res += dfs(nx, ny);
	}
	return res;
}

void solve(int wall, int x, int y) {
	if (wall == 3) {
		int cnt = 0;
		memset(c, 0, sizeof(c));
		for (auto k : virus) {
			cnt += dfs(k.first, k.second);
		}
		if (virus_num > cnt) virus_num = cnt;
		return;
	}

	for (int i = x; i<n; i++) {
		int k = i == x ? y : 0; //?

		for (int j = k; j<m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solve(wall + 1, i, j + 1); //j+1??
				map[i][j] = 0;
			}
		}

	}

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 1) safe++;
			if (map[i][j] == 2)	virus.push_back({ i,j });
		}
	}
	solve(0, 0, 0);
	printf("%d\n", safe - virus_num);
	return 0;
}


