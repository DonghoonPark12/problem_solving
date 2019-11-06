#include <iostream>
//�κ� û�ұ�
using namespace std;
//clean = 2
int map[50][50];
int dx[4] = { -1, 0, 1, 0 }; //��, ��, ��, ��
int dy[4] = { 0, -1, 0 ,1 };
int n, m; 
int r, c, d;

bool is_boundary(int x, int y) {
	if (x >= 0 && x < m && y>=0 && y < n)
		return true;
	else
		return false;
}

void clean(int r, int c, int d) {
	map[r][c] = 2;
	
	for (int i = 0; i < 4; i++) {
		if (map[c+dy[d]][r + dx[d]] == 0 && is_boundary(r+dx[d], c+dy[d])) {// possible clean left
			//rotate left
			int ny = r + dy[d];
			int nx = c + dx[d];
			if (d == 0) d = 3;
			else d -= 1;

			clean(ny, nx, d);
		}
		else {
			if (d == 0) d = 3;
			else d -= 1;
		}
	}

	if (map[r + dy[(d + 3) % 4]][c + dx[(d + 3) % 4]] == 0) {
		clean(r + dy[(d + 3) % 4], c + dx[(d + 3) % 4], d);
	}
	else
		return;
	
}

int check_clean() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2)
				ans++;
		}
	}
	return ans;
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
		}
	}

	clean(r, c, d);

	int ans = check_clean();
	cout << ans << endl;
	return 0;
}

//#include <stdio.h>
//#include <queue>
//using namespace std;
//
//struct robot {
//	int y, x, dir;
//};
//
//int n, m;
//int map[50][50];
//robot robo;
//
//const int dy[4] = { -1, 0, 1, 0 }; //��, ��, ��, ��
//const int dx[4] = { 0, 1, 0 ,-1 };
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d %d", &n, &m);
//	scanf("%d %d %d", &robo.y, &robo.x, &robo.dir);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%d", &map[i][j]);
//		}
//	}
//
//	queue<robot> q;
//	q.push(robo);
//	int ret = 0;
//	while (!q.empty()) {
//		robot cur = q.front(); q.pop();
//		if (map[cur.y][cur.x] == 0) {
//			map[cur.y][cur.x] = 2;
//			ret++;
//		}
//
//		for (int i = 0; i < 4; i++) {//4���� Ž��
//			robot next;
//			next.dir = (cur.dir + 3 - i) % 4; //���� ���� ȸ��
//			next.y = cur.y + dy[next.dir];
//			next.x = cur.x + dx[next.dir];
//
//			//���� ���� �̵��� �Ұ��� �ϰų�, ���̰ų�, �湮 �ߴ� ����
//			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] != 0)
//				continue;
//
//			q.push(next); // û�Ұ� �����ϸ� �� �������� �̵��ؾ� �ϱ� ������ push�� �ϰ� break;
//			break;
//		}
//
//		if (q.empty()) { //��� �������� �̵� �� �� ���ٸ�.
//			robot next;
//			next.dir = cur.dir; //������ ���� ��ü
//			next.y = cur.y + dy[(next.dir + 2) % 4]; //�ڷ� ����
//			next.x = cur.x + dx[(next.dir + 2) % 4];
//
//			// �ڷ� �����ص� �̵��� �Ұ��� �ϰ�, ���̸�
//			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1) {
//				break; //while ���� ����
//			}
//			q.push(next);
//		}
//	}
//	printf("%d\n", ret);
//	return 0;
//}
