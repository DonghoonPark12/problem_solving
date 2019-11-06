#include <iostream>
#include <queue>
using namespace std;
int r, c, t;
/*
 (r, c)에 잇는 미세 먼지 네 방향으로 확산.(방향에 공기 청정기 있거나 캄니 없으면 확산 x)
 A/5만큼 확산(모든 칸에서 동시에)

 위쪽 공기청정기 바람(반시계 방향으로 순환)
 아래쪽 공기청정기 바람(시계 방향으로 순환)
 미세먼지 한칸씩 이동
*/
struct info {
	int y, x, value;
};

queue<info> q;

int map[50][50];
int y_h = -1, y_l; //공기 청정기 위치

void rotation() {
	for (int i = y_h - 2; i >= 0;    i--) map[i + 1][0] = map[i][0]; // ↓
	for (int i = 0;       i < c - 1; i++) map[0][i]     = map[0][i + 1]; // ←
	for (int i = 0;       i < y_h;   i++) map[i][c - 1] = map[i + 1][c - 1]; //↑
	for (int i = c - 2;   i >= 0;    i--) map[y_h][i + 1] = map[y_h][i];  // →
	map[y_h][1] = 0;
	for (int i = y_l + 1; i < r-1; i++) map[i][0] = map[i+1][0];     // ↑
	for (int i = 0; i < c - 1; i++) map[r-1][i] = map[r-1][i + 1];	 // ←
	for (int i = r - 2; i >= y_l; i--) map[i + 1][c-1] = map[i][c-1];// ↓
	for (int i = c - 2; i >= 0; i--) map[y_l][i + 1] = map[y_l][i];  // →
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
		int tmp = cv / 5; //★큐 특성상 동시에 먼지가 퍼질순 없고, 퍼진 값이 옆에 값을 영향을 줄 경우 map[cy][cx]로는 퍼져야 하는 양을 판별하면 안된다.
		                  //따라서 값을 value라는 변수에 따로 저장하여 최초 값에 변동이 없도록 한다. 
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