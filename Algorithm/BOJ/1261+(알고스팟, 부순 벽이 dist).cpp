#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
/*
	알고스팟 문제
	(1,1), (h, w)로 이동하기 위해 부수어야 하는 최소 벽의 갯수
*/
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int arr[100][100];
int dist[100][100]; //bfs로 탐색하면서 벽일 경우 1을 더하면서 부술 것이다. 
int w, h;

void bfs() {
	deque<pair<int, int>> dq;
	dq.push_back({ 0, 0 });
	arr[0][0] = -1;
	while (!dq.empty()) {
		int cy = dq.front().first;
		int cx = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue; 
			if (arr[ny][nx] == -1) continue;

			//if (ny == h - 1 && nx == w - 1) {  //일
			//	printf("%d\n", dist[cy][cx]);
			//	return;
			//}
				
			if (arr[ny][nx] == 0) {
				//Empty room (0)
				dq.push_front({ ny, nx }); //priority, (13549.숨바꼭질 + 2178.미로탐색 문제)
				dist[ny][nx] = dist[cy][cx];
			}
			else {
				//Wall
				dq.push_back({ ny, nx });
				dist[ny][nx] = dist[cy][cx] + 1;
			}
			arr[ny][nx] = -1; //visited
		}
	}
	printf("%d\n", dist[h-1][w-1]);
	//return dist[h - 1][w - 1];
}
int main() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	bfs();
	return 0;
}


//시간 초과
//vector<pair<int,int>> num;
//vector<pair<int, int>> pick;
//int wall;
//int m;
//bool possible;
//
//void dfs(int y, int x) {
//	if (possible) return;
//
//	if (y == h - 1 && x == w - 1) {
//		possible = true; return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue; 
//		if(arr[ny][nx] == 1 || vis[ny][nx]) continue; //존재하지도 않는 영역을 경계 값과 같이 조사 하면 안된다. (주의)
//		vis[ny][nx] = true;                           //방문여부도 조건문에 포함 시켜야 한다. 미로 찾기 할때 백트레킹 필요하다. (주의)
//		dfs(ny, nx);
//		vis[ny][nx] = false;
//	}
//}
//
//void dfs_wall(int pos) {
//	if (possible) return;
//
//	if (pick.size() == m) {
//		dfs(0, 0);
//		return;
//	}
//	for (int i = pos; i < wall; i++) {
//		int wy = num[i].first; int wx = num[i].second;
//		pick.push_back(num[i]);
//		arr[wy][wx] = 0;
//		
//		dfs_wall(i + 1);
//
//		pick.pop_back();
//		arr[wy][wx] = 1;
//	}
//}