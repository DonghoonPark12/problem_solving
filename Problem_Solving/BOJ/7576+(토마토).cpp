#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
/*
	���� ���̰� 1�� �׷������� �ִ� �Ÿ��� ���ϴ� ������ ����ϴ�?
	
*/
using namespace std;
int w, h;
int arr[1000][1000];
int time[1000][1000];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

bool possible() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

void bfs() {
	int cy, cx;
	while (!q.empty()) {
		cy = q.front().first;
		cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (arr[ny][nx] == -1 || ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}
	if (!possible()) {
		cout << -1;
	}
	else
		cout << arr[cy][cx]-1;
}
int main() {
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i, j });
		}
	}
	bfs();
	return 0;
}
// ����� ������ �����ϱ� ���ؼ��� queue�� �������� �����ؼ�, �迭 �Է½ÿ� �ٷ� �־��ش�.
// ����� ������ ��������, queue + bfs�� ���ÿ� ����ϸ� �ȴ�.
// ���̵��� ���� arr[ny][nx] = arr[cy][cx] +1 �ϸ� (���� Ȥ�� �ð�) ������ �ϰ� �ȴ�.
// �ڸ����� ���� �ð��� arr[cy][cx]�� �� ���̴�. 
// �ֳ��ϸ� ��������� ���̻� push���� ���� ���̸� �̶� ť�� ������ ����(cy, cx)�� ���� arr[cy][cx]��
// �ּ� ��¥�� �� ���̱� �����̴�.
/*
	return !printf("-1");��

	printf("-1");
	return 0;��� ���̴�. 
	����..������
*/
