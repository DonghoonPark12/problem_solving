#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int t, n;
int map[501][501];
int d[501][501];
//int chk[501 * 501][2];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int _max;
int _cnt;
//int _lvl;

//플라이 하이 시간 초과

void dfs(int x, int y) {
	d[x][y] = 1;//flip
	_cnt += 1;
	if (_max < _cnt) {
		_max = _cnt;
		
	}

	//for (int i = 0; i < 4; i++) {
	//	int ax = x + dx[i]; //아, 위, 오, 왼
	//	int ay = y + dy[i];

	//	if (map[ax][ay] == 0 || d[ax][ay] != 0 || map[ax][ay]<=map[x][y]) continue; //범위를 벗어나거나, 이미 뒤집었다면 패스
	//	else if (map[ax][ay] > map[x][y]) {
	//		dfs(ax, ay);
	//		d[ax][ay] = 0;//flip back 
	//		_cnt -= 1;
	//		//d[x][y] = max(d[x][y], d[ax][ay] + 1);
	//	}
	//	else {}
	//}
	if     ((map[x + 1][y] > map[x][y]) && (map[x + 1][y] != 0) && (d[x + 1][y] == 0)) { //아
		dfs(x + 1, y);
		d[x+1][y] = 0;//flip back 
		_cnt -= 1;
	}
	if ((map[x - 1][y] > map[x][y]) && (map[x - 1][y] != 0) && (d[x - 1][y] == 0)) { //위
		dfs(x - 1, y);
		d[x - 1][y] = 0;//flip back 
		_cnt -= 1;
	}
	if ((map[x][y + 1] > map[x][y]) && (map[x][y + 1] != 0) && (d[x][y + 1] == 0)) { //오
		dfs(x, y + 1);
		d[x][y+1] = 0;//flip back 
		_cnt -= 1;
	}
	if ((map[x][y - 1] > map[x][y]) && (map[x][y - 1] != 0) && (d[x][y - 1] == 0)) { //왼
		dfs(x, y - 1);
		d[x][y-1] = 0;//flip back 
		_cnt -= 1;
	}
	else {}

	d[x][y] = 0;
	return ;
}

//typedef struct _node {
//	int x, y, lvl;
//	_node(int _x, int _y, int _lvl)
//		:x(_x), y(_y), lvl(_lvl)
//	{}
//}node;
//queue<node> q;
//void bfs(int x, int y, int _lvl) {
//	d[x][y] = 1;
//	q.push(node(x, y, _lvl));
//	int cx = q.front().x;
//	int cy = q.front().y;
//	_lvl = q.front().lvl;
//	//_lvl += 1;
//	if (_max < _lvl) {
//		_max = _lvl;
//	}
//
//	//for (int i = 0; i < 4; i++) {
//	//	int ax = x + dx[i]; //아, 위, 오, 왼
//	//	int ay = y + dy[i];
//	//	if (map[ax][ay] > map[x][y] && map[ax][ay] != 0 && d[ax][ay] == 0) {//조건을 만족하며, 경계가 아니고, 방문되지 않았으면
//	//		q.push(node(ax, ay));
//	//	}
//	//}
//
//	//q.pop();
//	while (!q.empty()) {
//		for (int i = 0; i < 4; i++) {
//			int ax = cx + dx[i]; //아, 위, 오, 왼
//			int ay = cy + dy[i];
//			if (map[ax][ay] > map[x][y] && map[ax][ay] != 0 && d[ax][ay] == 0) {//조건을 만족하며, 경계가 아니고, 방문되지 않았으면
//				q.push(node(ax, ay, _lvl+1));
//			}
//		}
//		q.pop();
//		cx = q.front().x;
//		cy = q.front().y;
//		q.pop();
//		bfs(cx, cy, _lvl);
//		//_lvl -= 1;
//	}
//}


int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				d[i][j] = 0;
				//chk[map[i][j]][0] = i; chk[map[i][j]][1] = j;
			}
		}
		
		_max = 0;//_max is counted in all 2D Matrix
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				 _cnt = 0;//_cnt is counted in one point
				dfs(i, j);
			}
		}
		cout << "#" << tc << " "  << _max << "\n";
		//get_result(tc);

	}
	return 0;
}