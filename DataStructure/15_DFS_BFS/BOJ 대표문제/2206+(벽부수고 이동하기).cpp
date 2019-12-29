#include <iostream>
#include <queue>
using namespace std;
//#define pair<int, int> p;
int h, w;
int arr[1000][1000];
int dist[1000][1000][2]; //벽을 부순 이력을 나타내는 배열
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
/*
	당연하지만, 이문제 또한 조합으로 풀수 없다. (부수고->이동 가능 확인) : O(MN^2) <-- 모든 곳에 벽이 다 있다고 생각하면 (10^6)^2
*/
/*
	벽을 부수지 않거나(0), 1개 부시는 경우(1)로 나뉜다.
	dist가 값이 0이 아니면 방문한 곳이다.

	'벽을 허문 이력'까지 탐색시에 고려해야 하므로 
	방향과 메모리 까지 정점요소로 만들었던, SWEA의 '혁진이의 프로그램 검증'과 유사하다.

	2206.벽부수고 이동하기-->SWEA.혁진이의 프로그램 검증-->
*/
struct map {
	int y, x, h;
};
void bfs() {
	queue<map> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	int cy, cx, ch;
	while (!q.empty()) {
		cy = q.front().y;
		cx = q.front().x;
		ch = q.front().h;//벽을 허문 이력이 있는지 체크
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			cout << dist[cy][cx][ch]; return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (dist[ny][nx][ch]) continue; // 방문 한적 있으면 패스

			if (arr[ny][nx] == 0) {//방         
				q.push({ ny, nx, ch });
				dist[ny][nx][ch] = dist[cy][cx][ch] + 1; //★이동 이력 증가
			}                                

			else if(arr[ny][nx] == 1 && ch == 0){         //벽이지만 허물은 이력 없다면
				q.push({ ny, nx, 1 });                    //★
				dist[ny][nx][1] = dist[cy][cx][ch] + 1;   //★이동 이력 증가, '1'주의
			}

			//벽이면서, 허문 이력이 있다면 큐(경우의 수)에 넣지 않는다.
		
		}
	}
	cout << "-1";
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			//cin >> arr[i][j];
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs();
	return 0;
}

//#include <iostream>
//#include <queue>
//using namespace std;
//int n, m;
//int a[1001][1001];
//int visited[1001][1001][2];
//int xpos[4] = { 1,-1,0,0 };
//int ypos[4] = { 0,0,-1,1 };
//queue<pair<pair<int, int>, pair<int, int>>> q;
//int result = -1;
//
//void bfs() {
//	q.push({ { 0,0 },{ 0,1 } });
//	visited[0][0][0] = 1;
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int c = q.front().second.first; //?
//		int	cnt = q.front().second.second;
//		q.pop();
//
//		if (x == m - 1 && y == n - 1) {
//			result = cnt;
//			printf("%d", result);
//			return;
//		}
//
//		for (int i = 0; i<4; i++) {
//			int	nx = x + xpos[i];
//			int	ny = y + ypos[i];
//			if (nx<0 || nx >= m || ny<0 || ny >= n)continue;
//			if (a[ny][nx] == 1 && c == 0) { //벽이고, 깨부신 이력이 없다면
//				visited[ny][nx][c + 1] = 1; //깨부신 이력 추가하고 방문 체크
//				q.push({ { nx,ny },{ c + 1,cnt + 1 } });//이동 이력 증가
//			}
//			else if (a[ny][nx] == 0 && !visited[ny][nx][c]) { //방이고, 방문한적 없다면
//				visited[ny][nx][c] = 1;    //깨부신 이력은 그대로 가져가고, 방문 체크
//				q.push({ { nx,ny },{ c,cnt + 1 } });//이동 이력 증가
//
//			}
//
//
//		}
//	}
//	printf("%d", result);
//}
//int main(void) {
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i<n; i++) {
//		for (int j = 0; j<m; j++) {
//			scanf("%1d", &a[i][j]);
//		}
//	}
//	bfs();
//	return 0;
//}