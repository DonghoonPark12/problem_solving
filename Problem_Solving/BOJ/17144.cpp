#include <iostream>
#include <queue>
using namespace std;
int r, c, t;
/*
 (r, c)�� �մ� �̼� ���� �� �������� Ȯ��.(���⿡ ���� û���� �ְų� į�� ������ Ȯ�� x)
 A/5��ŭ Ȯ��(��� ĭ���� ���ÿ�)

 ���� ����û���� �ٶ�(�ݽð� �������� ��ȯ)
 �Ʒ��� ����û���� �ٶ�(�ð� �������� ��ȯ)
 �̼����� ��ĭ�� �̵�
*/
struct info {
	int y, x, value;
};

queue<info> q;

int map[50][50];
int y_h = -1, y_l; //���� û���� ��ġ

void rotation() {
	for (int i = y_h - 2; i >= 0;    i--) map[i + 1][0] = map[i][0]; // ��
	for (int i = 0;       i < c - 1; i++) map[0][i]     = map[0][i + 1]; // ��
	for (int i = 0;       i < y_h;   i++) map[i][c - 1] = map[i + 1][c - 1]; //��
	for (int i = c - 2;   i >= 0;    i--) map[y_h][i + 1] = map[y_h][i];  // ��
	map[y_h][1] = 0;
	for (int i = y_l + 1; i < r-1; i++) map[i][0] = map[i+1][0];     // ��
	for (int i = 0; i < c - 1; i++) map[r-1][i] = map[r-1][i + 1];	 // ��
	for (int i = r - 2; i >= y_l; i--) map[i + 1][c-1] = map[i][c-1];// ��
	for (int i = c - 2; i >= 0; i--) map[y_l][i + 1] = map[y_l][i];  // ��
	map[y_l][1] = 0;
}

int check() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0)
				sum += map[i][j];
		}
	}
	return sum;
}
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
void bfs() {
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cv = q.front().value;
		q.pop();
		int tmp = cv / 5; //��ť Ư���� ���ÿ� ������ ������ ����, ���� ���� ���� ���� ������ �� ��� map[cy][cx]�δ� ������ �ϴ� ���� �Ǻ��ϸ� �ȵȴ�.
		                  //���� ���� value��� ������ ���� �����Ͽ� ���� ���� ������ ������ �Ѵ�. 
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx] == -1) continue;
			
			map[ny][nx] += tmp;
			map[cy][cx] -= tmp;
		}

	}
}
int main() {
	cin >> r >>c>> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (y_h == -1) y_h = i;
				else y_l = i;
			}
		}
	}
	while (t--) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					q.push({ i, j, map[i][j] });
				}
			}
		}

		bfs();
		rotation();
	}
	cout << check();
	return 0;
}