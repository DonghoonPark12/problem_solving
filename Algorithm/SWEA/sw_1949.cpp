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
			if (m[ny][nx] - m[y][x] >= 0 && (!cut)) { //���ų�, ���� �����̶�, 1<=k<=5, ��Ƽ� ������ �� �ִٸ�
					for (int dep = 1; dep <= k; dep++) {
						if (m[ny][nx] - dep < m[y][x]) { //��Ƽ� ���� ���ٸ�
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
//	// �ִ밪 ����
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
//		// ���� �������� ���ų� ���� ������ ���� ���
//		else {
//			if (map[x][y] <= map[nx][ny] && !cut) {
//					// ������ 1 ~ k ��ŭ ��Ƴ���
//					for (int depth = 1; depth <= k; depth++) {
//						int tmp = map[nx][ny];
//
//						// ���� ���� ������ ���� �������� ���ٸ�
//						if (map[nx][ny] - depth < map[x][y]) { //��Ƽ� ���� �������� �湮�Ѵ�. 
//							visited[nx][ny] = true; cut = 1;
//
//							map[nx][ny] = map[nx][ny] - depth; //���� ���̸� �Է�
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
//	// cin,cout �ӵ����
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
//				// ���� �湮���� ���� ���� ���� ������ ��� Ž�� ����
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
int dy[] = { 0,+1,0,-1 };//�����»�(�ð����)
int dx[] = { +1,0,-1,0 };
int vis[8][8];
int mh= 0, ans = 0;

void dfs(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		if (!vis[ny][nx] && m[y][x] > m[ny][nx]) {//visited�� �ǵ��ư� ����, map�� �������� ���
			vis[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			vis[ny][nx] = false;
		}
	}
	mh = max(mh, cnt);//������ �ִ� ���� ����
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
			for (int i = 0; i < N; i++) {//��� ���� ����
				for (int j = 0; j < N; j++) {              //�̰� �ʹ� ��ȿ���̴�. ���� ��� ������ ���ؼ� �� �غ���...
					m[i][j] -= cnt;//1���� K���� ����      //��θ� Ž���ϳ� ���� ���̺��� ũ�ų� ���� ��츸 �����Ѵ�. 
					for (int i = 0; i < v.size(); i++) {//�ְ� ���츮�� ���� DFS
						mh = 0;
						vis[v[i].first][v[i].second] = true;

						dfs(v[i].first, v[i].second, 1);

						vis[v[i].first][v[i].second] = false;
						ans = max(mh, ans);//�� ���츮�� �ִ� ���� �� ���� �� ��
					}
					m[i][j] += cnt;
				}
			}
			cnt++;//���ҵǴ� �� ����
		}

		cout << "#" << tc << ' ' << ans << '\n';
	}
	return 0;//��������
}
*/