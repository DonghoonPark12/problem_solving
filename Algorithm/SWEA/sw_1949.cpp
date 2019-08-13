#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int mh;
int m[8][8];
int vis[8][8];

int ans;
int cut;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[ny][nx] == true)
			continue;

		if (m[ny][nx] < m[y][x]) { //Ony lower than current height.
			vis[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			vis[ny][nx] = false;
		}
			
		else {
			if (m[ny][nx] - m[y][x] >= 0 && (!cut)) { //같거나, 높은 지역이라도, 1<=k<=5, 깎아서 낮아질 수 있다면
					for (int dep = 1; dep <= k; dep++) {
						if (m[ny][nx] - dep < m[y][x]) { //깎아서 낮아 졌다면
							int tmp = m[y][x];
							m[ny][nx] = m[y][x] - dep; cut = 1;

							vis[ny][nx] = true;
							dfs(ny, nx, cnt + 1);
							vis[ny][nx] = false;

							m[ny][nx] = tmp; cut = 0;
						}
					}
			}
		}
		
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	int t; cin >> t;
	cin >> n >> k;

	int tc = 1;
	while (t--) {
		//init
		mh = 0;
		ans = 0;
		memset(m, 0, sizeof(m));
		memset(vis, 0, sizeof(vis));
		cut = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				mh = max(mh, m[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] == mh) {
					vis[i][j] = true;
					dfs(i, j, 0);
					vis[i][j] = false;
				}
			}
		}
		
		cout << "#" << tc << " " << ans << '\n';
		tc++;
	}
	return 0;

}

//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int testcase;
//int n, k;
//int ans, highest;
//int map[8][8];
//int visited[8][8];
//
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//
//int cut;
//
//void dfs(int x, int y, int cnt) {
//	// 최대값 갱신
//	ans = max(ans, cnt);
//
//	for (int i = 0; i<4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx<0 || ny<0 || nx >= n || ny >= n || visited[nx][ny]) continue;
//
//
//		if (map[x][y] > map[nx][ny]) {
//			visited[nx][ny] = true;
//			dfs(nx, ny, cnt + 1);
//			visited[nx][ny] = false;
//		}
//		// 현재 지형보다 높거나 같은 지형을 만난 경우
//		else {
//			if (map[x][y] <= map[nx][ny] && !cut) {
//					// 지형을 1 ~ k 만큼 깎아내림
//					for (int depth = 1; depth <= k; depth++) {
//						int tmp = map[nx][ny];
//
//						// 새로 깎은 지형이 현재 지형보다 낮다면
//						if (map[nx][ny] - depth < map[x][y]) { //깎아서 낮아 져야지만 방문한다. 
//							visited[nx][ny] = true; cut = 1;
//
//							map[nx][ny] = map[nx][ny] - depth; //깎인 높이를 입력
//							dfs(nx, ny, cnt + 1);
//							map[nx][ny] = tmp;
//
//							visited[nx][ny] = false; cut = 0;
//						}
//					}
//				
//			}
//		}
//	}
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	// cin,cout 속도향상
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> testcase;
//	for (int t = 1; t <= testcase; t++) {
//		cin >> n >> k;
//
//		highest = 0;
//
//		for (int i = 0; i<n; i++) {
//			for (int j = 0; j<n; j++) {
//				cin >> map[i][j];
//				highest = max(highest, map[i][j]);
//			}
//		}
//
//		memset(visited, false, sizeof(visited));
//		ans = 0; cut = 0;
//
//		for (int i = 0; i<n; i++) {
//			for (int j = 0; j<n; j++) {
//				// 아직 방문하지 않은 가장 높은 등산로일 경우 탐색 시작
//				if (map[i][j] == highest) {
//					visited[i][j] = true;
//					dfs(i, j, 1);
//					visited[i][j] = false;
//				}
//			}
//		}
//
//		cout << "#" << t << " " << ans << "\n";
//	}
//
//	return 0;
//}

/*
int N, K;
int m[8][8];
vector<pair<int, int>> v;
int dy[] = { 0,+1,0,-1 };//우하좌상(시계방향)
int dx[] = { +1,0,-1,0 };
int vis[8][8];
int mh= 0, ans = 0;

void dfs(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		if (!vis[ny][nx] && m[y][x] > m[ny][nx]) {//visited는 되돌아감 방지, map은 내려가는 경사
			vis[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			vis[ny][nx] = false;
		}
	}
	mh = max(mh, cnt);//등산로의 최대 길이 갱신
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(m, 0, sizeof(m));
		v.clear();
		cin >> N >> K;
		int h = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> m[i][j];
				mh = max(mh, m[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (m[i][j] == mh)
					v.push_back({ i,j });
			}
		}

		int cnt = 1;
		ans = 0;

		while (true) {
			if (cnt == K + 1) {
				break;
			}
			for (int i = 0; i < N; i++) {//모든 점에 대해
				for (int j = 0; j < N; j++) {              //이건 너무 비효율이다. 무슨 모든 지점에 대해서 다 해보나...
					m[i][j] -= cnt;//1부터 K까지 감소      //경로를 탐색하나 현재 높이보다 크거나 같은 경우만 진행한다. 
					for (int i = 0; i < v.size(); i++) {//최고 봉우리에 대해 DFS
						mh = 0;
						vis[v[i].first][v[i].second] = true;

						dfs(v[i].first, v[i].second, 1);

						vis[v[i].first][v[i].second] = false;
						ans = max(mh, ans);//각 봉우리의 최대 길이 중 가장 긴 것
					}
					m[i][j] += cnt;
				}
			}
			cnt++;//감소되는 값 증가
		}

		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;//정상종료
}
*/