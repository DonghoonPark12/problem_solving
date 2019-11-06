#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[8][8];
vector<pair<int, int>> cctv;

int freespace;

int n, m; 

int _min;

const int x[4] = { 1, 0, -1, 0 };//우, 하, 좌, 상 
const int y[4] = { 0, 1,  0, -1 };

void map_copy(int desc[8][8], int src[8][8]) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			desc[y][x] = src[y][x];
		}
	}
}

void draw_sharp(int i, int d) {
	int t = map[cctv[i].first][cctv[i].second]; //cctv type
	//cout << t << endl;
	if (t == 1) {
		int ny = cctv[i].first + y[d];
		int nx = cctv[i].second + x[d];
		while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx]!= 6) {
			map[ny][nx] = 11;
			//backup.push_back({ny, nx});
			ny += y[d]; nx += x[d];
		}
	}
	else if (t == 2) {
		for (int s = 0; s <= 2; s += 2) {
			int ny = cctv[i].first + y[(d+s)%4];
			int nx = cctv[i].second + x[(d+s)%4];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6) {
				map[ny][nx] = 12;
				//backup.push_back({ ny, nx });
				ny += y[(d + s) % 4]; nx += x[(d + s) % 4];
			}
		}
	}
	else if (t == 3) {
		for (int s = 0; s <= 1; s += 1) {
			int ny = cctv[i].first + y[(d+s)%4];
			int nx = cctv[i].second + x[(d+s)%4];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6) {
				map[ny][nx] = 13;
				//backup.push_back({ ny, nx });
				ny += y[(d + s) % 4]; nx += x[(d + s) % 4];
			}
		}
	}
	else if (t == 4) {
		for (int s = 0; s <= 2; s += 1) {
			int ny = cctv[i].first + y[(d+s)%4];
			int nx = cctv[i].second + x[(d+s)%4];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6) {
				map[ny][nx] = 14;
				//backup.push_back({ ny, nx });
				ny += y[(d + s) % 4]; nx += x[(d + s) % 4];
			}
		}
	}
	else if(t==5){ //t == 5
		for (int s = 0; s <= 3; s += 1) {
			int ny = cctv[i].first + y[(d+s)%4];
			int nx = cctv[i].second + x[(d+s)%4];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != 6) {
				map[ny][nx] = 15;
				//backup.push_back({ ny, nx });
				ny += y[(d + s) % 4]; nx += x[(d + s) % 4];
			}
		}
	}
	else
	{	}
}

int count_freespace() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

//void clean_sharp(vector<pair<int, int>> &backup) {
//	for (int i = 0; i < backup.size(); i++) {
//		map[backup[i].first][backup[i].second] = 0;
//	}
//}
int cnt;
void dfs(int num) {
	if (num == cctv.size()) {
		int tmp = count_freespace();
		if (tmp < _min) {
			_min = tmp;
			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < m; j++) {
			//		cout << map[i][j] << " ";
			//	}
			//	cout << "\n";
			//}
			//cout << "\n";
			//cout << _min<<" "<<cnt << endl;
			
		}
		//_min = min(_min, count_freespace());//we need to find the smallest '0' number situation.
		cnt++;
		//cout << cnt << endl;
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		return;
	}
	int backup[8][8];
	for (int i = num; i < cctv.size(); i++) {
		for (int d = 0; d < 4; d++) {
			//vector<pair<int, int>> backup;
			//cout << backup.size();
			map_copy(backup, map);
			if (map[cctv[i].first][cctv[i].second] == 2 && (d==2||d==3))
					continue;

			if (map[cctv[i].first][cctv[i].second] == 5 && (d==1||d==2||d==3))
					continue;
			
			draw_sharp(i, d);//#을 표시

			//for (int t = 0; t < backup.size(); t++) {
			//	cout << backup[t].first << " " << backup[t].second << '\n';
			//}

			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < m; j++) {
			//		cout << map[i][j] << " ";
			//	}
			//	cout << endl;
			//}
			dfs(i + 1);
			map_copy(map, backup);
			//clean_sharp(backup);//#을 제거
			//backup.clear();
		}
	}
}

/*int cctv_size;
int _min2;
typedef struct _cctv {
	int type, y, x;
}CCTV;

CCTV cctvs[8];

const int rot_size[] = { 0, 4, 2, 4, 4, 1 };*/ //회전 가능한 방향의 크기를 미리 정의(tip)



//void update(int dir, CCTV cctv) {
//	dir = dir % 4;
//
//	if (dir == 0) { //우
//		for (int x = cctv.x + 1; x < m; x++) {
//			if (map[cctv.y][x] == 6) break;
//			map[cctv.y][x] = 7;
//		}
//	}
//	if (dir == 1) { //하
//		for (int y = cctv.y - 1; y >= 0; y--) {
//			if (map[y][cctv.x] == 6) break;
//			map[y][cctv.x] = 7;
//		}
//	}
//	if (dir == 2) { //좌
//		for (int x = cctv.x - 1; x >= 0; x--) {
//			if (map[cctv.y][x] == 6) break;
//			map[cctv.y][x] = 7;
//		}
//	}
//	if (dir == 3) { //상
//		for (int y = cctv.y + 1; y < n; y++) {
//			if (map[y][cctv.x] == 6) break;
//			map[y][cctv.x] = 7;
//		}
//	}
//}
 
//void dfs2(int cctv_idx) {
//	if (cctv_idx == cctv_size) {
//		// empyt place count
//		_min2 = min(_min2, count_freespace());
//		return;
//	}
//	
//	int backup[8][8];
//	int type = cctvs[cctv_idx].type;
//	for (int dir = 0; dir < rot_size[type]; dir++) {//type 마다 dir의 범위가 다르다.
//		//map backup                                //미리 이렇게 배열에 넣고, for문 넣으면 편하다.
//		map_copy(backup, map);
//		//map update
//		if (type == 1) {
//			update(dir, cctvs[cctv_idx]);
//		}
//		else if (type == 2) {
//			update(dir, cctvs[cctv_idx]);
//			update(dir+2, cctvs[cctv_idx]);
//		}
//		else if (type == 3) {
//			update(dir, cctvs[cctv_idx]);
//			update(dir + 1, cctvs[cctv_idx]);
//		}
//		else if (type == 4) {
//			update(dir, cctvs[cctv_idx]);
//			update(dir + 1, cctvs[cctv_idx]);
//			update(dir + 2, cctvs[cctv_idx]);
//		}
//		else{ // (type == 5) {
//			update(dir, cctvs[cctv_idx]);
//			update(dir + 1, cctvs[cctv_idx]);
//			update(dir + 2, cctvs[cctv_idx]);
//			update(dir + 3, cctvs[cctv_idx]);
//		}
//		dfs2(cctv_idx + 1);
//
//		//map drawback
//		map_copy(map, backup);
//	}
//}

int main() {
	cin >> n >> m;
	//freespace = n*m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j]!=6) {
				//freespace -= 1; //because there are wall or cctv;
				//if (map[i][j] != 6) {
					cctv.push_back({ i,j });
				//}
			}

			//if (map[i][j] != 0 && map[i][j] != 6) {
			//	cctvs[cctv_size].y = i;
			//	cctvs[cctv_size].x = j;
			//	cctvs[cctv_size].type = map[i][j];
			//	cctv_size++;
			//}

		}
	}
	//for (int t = 0; t < cctv.size(); t++) {
	//	cout << cctv[t].first << " " << cctv[t].second << '\n';
	//}
	_min = 0x7fffffff;

	dfs(0);

	//_min2 = 65;
	//dfs2(0);

	cout << _min;
	return 0;
}


