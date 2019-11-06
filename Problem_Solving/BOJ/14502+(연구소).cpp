#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*
	�� ����� --> ����

	���� ���� ũ�� �ִ� ���� ���ϴ� ���α׷� �ۼ��Ͻÿ�.
*/
int h, w;
int map[8][8];
//vector<pair<int, int>> sp;//space
//vector<int> pick;
//vector<pair<int, int>> pick;

queue<pair<int, int>> flood;
queue<pair<int, int>> flood_backup;
int backup[8][8];
int safe; //0�� ��.
int _min = 0x7fffffff;
int cnt;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
void bfs() {
	while (!flood.empty()) {
		int cy = flood.front().first;
		int cx = flood.front().second;
		flood.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] == 1 || map[ny][nx] == 2) continue;
			map[ny][nx] = 2;
			flood.push({ ny, nx });
			cnt++;
		}
	}
}
//void dfs(int pos) {
void dfs(int count, int yp, int xp) {
	//if (pick.size() == 3) {
	if (count == 3) {
		//safebackup = safe;
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << '\n';
		//}
		cnt = 0;
		memcpy(backup, map, sizeof(backup));
		flood = flood_backup;
		bfs(); //ħ�� �Ǵ� ������ ��������. ħ�� �Ǵ� ������ ���� ���� ��� --> safe - min��
		memcpy(map, backup, sizeof(map));
		_min = min(_min, cnt);
		return;
	}
	//for (int i = pos; i < sp.size(); i++) {
	//	int wy = sp[i].first, wx = sp[i].second;
	//	pick.push_back(i);
	//	map[wy][wx] = 2;
	//	dfs(i + 1);
	//	pick.pop_back();
	//	map[wy][wx] = 0;
	//}
	for (int y = yp; y < h; y++) {
		for (int x = xp; x < w; x++) {
			if (map[y][x] == 0) {
				//pick.push_back({ y, x });
				map[y][x] = 1;
				dfs(count + 1, y, x);
				map[y][x] = 0;
			}
		}
		xp = 0;
	}
	
}
/*
	����� : 
	1. sp�� ���Ϳ� �� �ְ�(�� ��� ��ġ), 2���� ���Ϳ��� ������ �ϴ� ��� ����(���� �ð��� �����ϴ�)
	2. pick.push_back({ y, x }); ���� �ʰ�, count�� ������ m�� ���ϴ� ��� ����.
*/
int main() {
	cin >> h >> w;
	int value;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> value;
			map[i][j] = value;
			//if (value == 0) { sp.push_back({ i, j }); safe++; }
			if (value == 0) { safe++; }
			if (value == 2) { flood_backup.push({ i, j }); }
		}
	}
	dfs(0, 0, 0);
	cout<<safe - _min - 3;
	return 0;
}
