//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//#define MAX_SIZE 50
//int n, m;
//int map[MAX_SIZE][MAX_SIZE];
//int backup[MAX_SIZE][MAX_SIZE];
//int dist[MAX_SIZE][MAX_SIZE];
//
//vector<pair<int, int>> birus;
//vector<pair<int, int>> pick;
//queue<pair<int, int>> q;
////vector<pair<int, int>> pick;
///*
//	조합 + 토마토 문제
//	+ 활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.
//*/
//int ans = -1;
//int _min = 0x7ffffff;
//int num_b;
//const int dx[4] = { -1, 1, 0, 0 };
//const int dy[4] = { 0, 0, -1, 1 };
//int check() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == 0)
//				return 0;
//		}
//	}
//	return 1; //빈칸이 존재하지 않는 경우
//}
//int bfs() {
//	int cy, cx;
//	while (!q.empty()) {
//		cy = q.front().first;
//		cx = q.front().second;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = cy + dy[i];
//			int nx = cx + dx[i];
//			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
//			
//			
//			if (map[ny][nx] == '*') {
//				map[ny][nx] = 2;
//				dist[ny][nx] += dist[cy][cx] + 1;
//				q.push({ ny, nx });
//			}
//			if (map[ny][nx] == 0) {
//				// map[ny][nx] !=1 은 바이러스 or 빈공간 모두 가능.
//				// 비활성화 바이러스가 활성화 바이러스를 만나면 활성화가 되면서
//				// 시간은 증가를 이어나간다.
//				map[ny][nx] = 2; 
//				dist[ny][nx] += dist[cy][cx] + 1;
//				q.push({ ny, nx });
//			}
//		}
//	}
//
//	if (check()) 
//		return dist[cy][cx];//연구소에 모두 바이러스가 퍼진 경우
//	else
//		return -1; //모든 빈칸에 바이러스를 퍼트릴 수 없는 경우
//}
//
//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		memcpy(backup, map, sizeof(backup));
//
//		for (int i = 0; i < pick.size(); i++) {
//			map[pick[i].first][pick[i].second] = 2;
//			q.push(pick[i]);
//		}
//		memset(dist, 0, sizeof(dist));
//
//		int value = bfs();
//		if (value != -1) {
//			_min = min(_min, value);
//		}
//
//		memcpy(map, backup, sizeof(map));
//		return;
//	}
//
//	for (int i = pos; i < birus.size(); i++) {
//		int y = birus[i].first, x = birus[i].second;
//		pick.push_back({ y, x });
//		dfs(i + 1);
//		pick.pop_back();
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int value;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> value;
//			map[i][j] = value;
//			if (value == 2) { birus.push_back({ i, j }); map[i][j] = '*';}
//		}
//	}
//	dfs(0);
//	if (_min > 2500)
//		cout << -1;
//	else
//		cout << _min;
//	return 0;
//}

/*--------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct virus {
	int x, y;
};

int map[50][50], dist[50][50];
int n, m, k, ans = 1e9;
bool select[10];
vector<virus> v;
queue<virus> q;
const int dx[] = { -1, 0 , 1, 0 }, dy[] = { 0, 1, 0, -1 };

void bfs() {
	int infect = 0, times = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i<4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] != 1 && dist[nx][ny] == -1) { //!
				dist[nx][ny] = dist[x][y] + 1;            //!
				if (map[nx][ny] == 0) {                   //!
					infect += 1;
					times = dist[nx][ny];
				}
				q.push({ nx, ny });
			}
		}
	}
	if (infect == k && ans > times) ans = times;          //!
}

void solve(int idx, int cnt, int d) {
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i<d; i++) {
			if (select[i]) {
				q.push({ v[i].x, v[i].y });//!
				dist[v[i].x][v[i].y] = 0; //!
			}
		}
		bfs();
		return;
	}
	for (int i = idx; i<d; i++) {
		if (!select[i]) {
			select[i] = true;
			solve(i + 1, cnt + 1, d);
			select[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &map[i][j]);
			if (a[i][j] == 2) v.push_back({ i, j });
			if (a[i][j] == 0) k += 1; //!
		}
	}
	solve(0, 0, v.size());
	printf("%d\n", ans == 1e9 ? -1 : ans);
	return 0;
}