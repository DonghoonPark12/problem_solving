#include <iostream>
#include <queue>
using namespace std;
// 토마토(3차원ver)
int W, H, Z;
int box[100][100][100];

struct place {
	int z, y, x;
};
queue <place> q;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int bfs() {
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nz = cz + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= W || ny >= H || nz >= Z) continue;
			//if (box[nz][ny][nx] == 1 || box[nz][ny][nx] == -1) continue;
			//if (box[nz][ny][nx] == 0) {
			if (box[nz][ny][nz]) continue;    // Ripened(1 or above), empty(-1) by REBAS
				box[nz][ny][nx] = box[cz][cy][cx] + 1;
				q.push({ nz, ny, nx });
			//}
		}
	}
	int _max = -1;
	for (int z = 0; z < Z; z++) {
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (box[z][h][w] == 0) return -1;
				_max = _max < box[z][h][w] ? box[z][h][w] : _max;
			}
		}
	}
	return _max-1;
}

int main() {
	cin >> W >> H >> Z;
	int tmp;
	for (int z = 0; z < Z; z++) {
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cin >> tmp;	box[z][h][w] = tmp;
				if (tmp == 1) q.push({ z, h, w });
			}
		}
	}
	cout << bfs() << '\n';
	return 0;
}