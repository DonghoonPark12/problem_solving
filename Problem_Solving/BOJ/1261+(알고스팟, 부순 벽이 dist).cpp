#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
/*
	�˰��� ����
	(1,1), (h, w)�� �̵��ϱ� ���� �μ���� �ϴ� �ּ� ���� ����
*/
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int arr[100][100];
int dist[100][100]; //bfs�� Ž���ϸ鼭 ���� ��� 1�� ���ϸ鼭 �μ� ���̴�. 
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

			//if (ny == h - 1 && nx == w - 1) {  //��
			//	printf("%d\n", dist[cy][cx]);
			//	return;
			//}
				
			if (arr[ny][nx] == 0) {
				//Empty room (0)
				dq.push_front({ ny, nx }); //priority, (13549.���ٲ��� + 2178.�̷�Ž�� ����)
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


//�ð� �ʰ�
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
//		if(arr[ny][nx] == 1 || vis[ny][nx]) continue; //���������� �ʴ� ������ ��� ���� ���� ���� �ϸ� �ȵȴ�. (����)
//		vis[ny][nx] = true;                           //�湮���ε� ���ǹ��� ���� ���Ѿ� �Ѵ�. �̷� ã�� �Ҷ� ��Ʈ��ŷ �ʿ��ϴ�. (����)
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