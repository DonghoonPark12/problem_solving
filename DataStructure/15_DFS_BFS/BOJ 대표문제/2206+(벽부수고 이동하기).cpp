#include <iostream>
#include <queue>
using namespace std;
//#define pair<int, int> p;
int h, w;
int arr[1000][1000];
int dist[1000][1000][2]; //���� �μ� �̷��� ��Ÿ���� �迭
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
/*
	�翬������, �̹��� ���� �������� Ǯ�� ����. (�μ���->�̵� ���� Ȯ��) : O(MN^2) <-- ��� ���� ���� �� �ִٰ� �����ϸ� (10^6)^2
*/
/*
	���� �μ��� �ʰų�(0), 1�� �νô� ���(1)�� ������.
	dist�� ���� 0�� �ƴϸ� �湮�� ���̴�.

	'���� �㹮 �̷�'���� Ž���ÿ� ����ؾ� �ϹǷ� 
	����� �޸� ���� ������ҷ� �������, SWEA�� '�������� ���α׷� ����'�� �����ϴ�.

	2206.���μ��� �̵��ϱ�-->SWEA.�������� ���α׷� ����-->
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
		ch = q.front().h;//���� �㹮 �̷��� �ִ��� üũ
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			cout << dist[cy][cx][ch]; return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (dist[ny][nx][ch]) continue; // �湮 ���� ������ �н�

			if (arr[ny][nx] == 0) {//��         
				q.push({ ny, nx, ch });
				dist[ny][nx][ch] = dist[cy][cx][ch] + 1; //���̵� �̷� ����
			}                                

			else if(arr[ny][nx] == 1 && ch == 0){         //�������� �㹰�� �̷� ���ٸ�
				q.push({ ny, nx, 1 });                    //��
				dist[ny][nx][1] = dist[cy][cx][ch] + 1;   //���̵� �̷� ����, '1'����
			}

			//���̸鼭, �㹮 �̷��� �ִٸ� ť(����� ��)�� ���� �ʴ´�.
		
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
//			if (a[ny][nx] == 1 && c == 0) { //���̰�, ���ν� �̷��� ���ٸ�
//				visited[ny][nx][c + 1] = 1; //���ν� �̷� �߰��ϰ� �湮 üũ
//				q.push({ { nx,ny },{ c + 1,cnt + 1 } });//�̵� �̷� ����
//			}
//			else if (a[ny][nx] == 0 && !visited[ny][nx][c]) { //���̰�, �湮���� ���ٸ�
//				visited[ny][nx][c] = 1;    //���ν� �̷��� �״�� ��������, �湮 üũ
//				q.push({ { nx,ny },{ c,cnt + 1 } });//�̵� �̷� ����
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