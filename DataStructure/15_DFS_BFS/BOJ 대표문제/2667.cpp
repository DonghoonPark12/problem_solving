#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int arr[25][25];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int cnt;
vector<int> v;
void dfs(int y, int x) {
	arr[y][x] = 2;
	cnt++;
	int cy = y;
	int cx = x;
	for (int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == 2) continue;
		if(arr[ny][nx] == 1){
			dfs(ny, nx);
		}
	}
}
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = 2;
	cnt++;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (arr[ny][nx] == 1) {
				q.push({ ny, nx });
				arr[ny][nx] = 2;   //bfs는 넣을 때 변형 시켜 줘야 한다.
				cnt++;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d",&arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				cnt = 0;
				//dfs(i, j);
				bfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}

//using namespace std;
////유사문제 : 4963. 섬의 개수
//int w, h;
//int arr[50][50];
//const int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
//const int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
//int cnt;
//vector<int> v;
//
//void bfs(int y, int x) {
//	queue<pair<int, int>> q;
//	q.push({ y, x });
//	arr[y][x] = 2;
//	while (!q.empty()) {
//		int cy = q.front().first;
//		int cx = q.front().second;
//		q.pop();
//		for (int i = 0; i < 8; i++) {
//			int ny = cy + dy[i];
//			int nx = cx + dx[i];
//			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
//			if (arr[ny][nx] == 1) {
//				q.push({ ny, nx });
//				arr[ny][nx] = 2;   //bfs는 넣을 때 변형 시켜 줘야 한다.
//			}
//		}
//	}
//}
//
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	while (1) {
//		cin >> w >> h;
//		if (w == 0 && h == 0) break;
//		
//		memset(arr, 0, sizeof(arr));
//		cnt = 0;
//
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (arr[i][j] == 1) {
//					cnt ++;
//					//dfs(i, j);
//					bfs(i, j);
//				}
//			}
//		}
//		cout << cnt << '\n';
//	}
//	return 0;
//}
