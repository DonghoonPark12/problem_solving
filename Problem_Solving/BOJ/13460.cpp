//#include <iostream>
//using namespace std;
//
//int cry, crx, cby, cbx, gy, gx;
//int map[10][10];
//int move;
//int move_save;
//int flag; //if(R --> O) : 1, if(B --> O) : -1
//int d_past;
//
//int dfs(int cry, int crx, int move) {
//	if (flag) return 1;
//	else return -1;
//
//	if (move >= 10) return 0;
//
//	for (int d = 0; d < 4; d++) {
//		if (d == 0 && (d_past != 0 || d_past != 2)) { //왼쪽
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cbx--; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 0;
//			dfs(cry, crx, move + 1);
//		}
//		else if (d == 1 && (d_past != 1 || d_past != 3)) { //아래쪽
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cby++; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 1;
//			dfs(cry, crx, move + 1);
//		}
//		else if (d == 2 && (d_past !=2 && d_past != 0)) { //오른쪽
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cbx++; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 2;
//			dfs(cry, crx, move + 1);
//		}
//		else if(d==3 && (d_past != 3 && d_past != 1)) { //d ==3 //위쪽
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cby--; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 3;
//			dfs(cry, crx, move + 1);
//		}
//		else
//		{ }
//	}
//
//	if (move < 10)
//		return 0;
//	else {
//		flag = -1; return 0;
//	}
//}
//
//int main() {
//	int n, m;//세로, 가로
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m ; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 'R') { cry = i, crx = j; }
//			if (map[i][j] == 'B') { cby = i, cbx = j; }
//			if (map[i][j] == 'O') {  gy = i,  gx = j; }
//		}
//	}
//	dfs(cry, crx, 0);
//	if (move_save > 0)
//		cout << move_save << endl;
//	else
//		cout << -1 << endl;
//	return 0;
//}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
	int ry, rx, by, bx, count;
};

INFO start;
char map[10][11];

int bfs() {
	const int dy[] = { -1, 1, 0, 0 }; //위, 아래, 왼쪽, 오른쪽
	const int dx[] = { 0, 0, -1, 1 };

	int visited[10][10][10][10] = { 0, };
	queue<INFO> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1; //큐를 이용해서 구슬의 위치를 기억하고, 다음 상태로 구슬을 이동 시킨다.

	int ret = -1;
	while (!q.empty()) {
		INFO cur = q.front(); //현재 빨간 구슬, 파란 구슬 상태 큐에 집에 넣는다. 
		q.pop();
		if (cur.count > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ret = cur.count; //현재까지 카운트된 갯수 저장.
			break;
		}

		// 계속 기울여 가며 탐색
		for (int dir = 0; dir < 4; ++dir) { //한 방향으로 기울임
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {//벽이 아니고, 구멍이 아니라면
				next_ry += dy[dir], next_rx += dx[dir];//한 방향으로 계속 이동
			}
			if(map[next_ry][next_rx] == '#')
				next_ry -= dy[dir], next_rx -= dx[dir];//벽이라면 다시 돌아와 준다.

			while (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {//파란 구슬도 같이 이동해 준다.
				next_by += dy[dir], next_bx += dx[dir];
			}
			if(map[next_by][next_bx] == '#')
				next_by -= dy[dir], next_bx -= dx[dir];

			//문제는 두 구슬이 같은 장소에 있는 경우이다. 
			if (next_rx == next_bx && next_ry == next_by && map[next_ry][next_rx] != 'O') {
				int r_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx); //이때 빨간 구슬, 파란 구슬 이동한 거리를 계산한다.
				int b_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx); //어느 방향으로 부터 이동해왔는지 abx(y이동) + abs(x이동) 으로 계산하면 알 필요 없다.
				if (r_dist > b_dist)
					next_ry -= dy[dir], next_rx -= dx[dir];
				else
					next_by -= dy[dir], next_bx -= dx[dir];
			}

			//가장 중요한 부분.
			if (visited[next_ry][next_rx][next_by][next_bx] == 0) {//해당 지점이 방문이 안되있다면
				visited[next_ry][next_rx][next_by][next_bx] = 1; 
				INFO next;
				next.ry = next_ry; next.rx = next_rx;
				next.by = next_by; next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		} //4방향 for문
	}//queue while 문
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				start.ry = i, start.rx = j;
			if (map[i][j] == 'B')
				start.by = i, start.bx = j;
		}
	}	
	start.count = 0;
	
	int ret = bfs();
	cout << ret << endl;
	return 0;
}