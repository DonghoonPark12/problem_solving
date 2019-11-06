#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
int arr[100][100];
int dist[100][100];
//int vis[100][100];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
bool flag;
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
//�̷�ã�� ����
//��Ʈ��ŷ ������� Ǯ������, �ð��ʰ� �� ����.
//�ִ� �Ÿ��� ���� ���� bfs�� �� �����ϴ�. 
//"�ּ��� ���𰡸� ���ؾ� �ϴµ� �׷��� ��ü(!)�� Ž���ؾ� �ϴ� ��� bfs�� ���� �ȴ�"(https://www.acmicpc.net/board/view/9924)
//"bfs�� ��� ��θ� �湮���� �ʴ´�"(�����ϸ� �����ϸ� �Ǿ??)
//"bfs�� ���� ���̰� �� �ִܰŸ��� �ǹǷ� ��� ĭ�� �湮�ϱ⸸ �ϸ� �ȴ�"(https://www.acmicpc.net/board/view/15650)

//DFS�� �׷� '���� ������'�� Ȯ���� �� BFS���� �� �����Ѱ�?
//���� �������� Ȯ���� �� BFS���� �� ���� Ȯ���� �� ���� �� ����. 
//���� �����Ը� Ȯ���Ѵٸ� ���� ������ ��͸� ���� ��Ų��.
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			cout << dist[h - 1][w - 1];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny<0 || ny >h || nx<0 || nx>w) continue;
			if (!arr[ny][nx] || dist[ny][nx]) continue; //��(1)�� �ƴϰų�, �̹� �湮 ������(dist)

			dist[ny][nx] = dist[cy][cx] + 1;//���� ������ �Ѵ�. 
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &arr[i][j]);
			//dist[i][j] = INT_MAX;
		}
	}
	//1) dfs_dist Ǯ��, �ð� �ʰ�
	//dist[0][0] = 1;
	//dfs_dist(0, 0);
	//cout << dist[h - 1][w - 1]<< '\n';

	//2) dfs_backtracing Ǯ��, �ð� �ʰ�
	//dfs_backtracing(0, 0, 1);
	//cout << _min << '\n';

	//3) bfsǮ��
	bfs(0, 0);
	return 0;
}


//1) dfs_dist Ǯ��
//�̷� ����� Ǯ�̸� ���� ����. arr �Է��� ���� ��, dist���� �ִ� ���� ���� �־��ְ�
//���� ���� ������ ������ ����. 
//���ͽ�Ʈ���ΰ�??
//void dfs_dist(int y, int x) {
//	if ((y == h - 1) && (x == w - 1)) {
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny<0 || ny >h || nx<0 || nx>w || arr[ny][nx] == 0) continue;
//		if (dist[ny][nx] > dist[y][x] + 1) {
//			dist[ny][nx] = dist[y][x] + 1;
//			dfs_dist(ny, nx);
//		}
//	}
//}

//2) dfs_backtracing Ǯ��, �ð� �ʰ�
//int _min = 0x7fffffff;
//int cnt;
//void dfs_backtracing(int y, int x, int cnt) {
//	if ((y == h - 1) && (x == w - 1)) {
//		_min = min(_min, cnt);
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny<0 || ny >h || nx<0 || nx>w || arr[ny][nx] == 2) continue;
//		if (arr[ny][nx] == 1) {
//			arr[ny][nx] = 2;
//			dfs_backtracing(ny, nx, cnt + 1);
//			arr[ny][nx] = 1;
//		}
//	}	
//}