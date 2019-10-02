//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;

/*------------------------------------------------------------------------------------------------------*/
//typedef struct _data
//{
//	int x;
//	int y;
//	int sec;
//	bool water;
//} info;
//
//int r, c;
//char map[50][50];
//bool visit[50][50];
//int sx, sy;
//int endx, endy;
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//vector<pair<int, int> > w;
//
////고슴도치 S
////동굴 D
////X는 벽
////*는 물
//
//void bfs(){
//	queue<info> q;
//	for (int i = 0; i < w.size(); i++) 
//		q.push(info{ w[i].first, w[i].second, 0, 1 });//물의 위치, 시간, 물의 여부를 큐에 넣는다. 
//	q.push(info{ sx, sy, 0, 0 });
//
//	while (!q.empty())
//	{
//		info pop_data = q.front();
//		q.pop();
//
//		int x = pop_data.x;
//		int y = pop_data.y;
//		int t = pop_data.sec;
//		bool water = pop_data.water;
//
//		if (water == 0 && endx == x && endy == y) { //목적지 도착
//			cout << t; return;
//		}
//
//		if (!water && visit[x][y] == 1) continue;            //물이 없고, 
//		else if (!water && visit[x][y] == 0) visit[x][y] = 1;//물이 없고, 방문되지 않았으면
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
//			if (map[nx][ny] == 'X' || map[nx][ny] == '*') continue; //돌이거나 물이면 통과
//			if (water && map[nx][ny] == 'D') continue; //물이 있고, 비버 구멍이면
//			if (water) map[nx][ny] = '*';
//			q.push(info{ nx, ny, t + 1, water });
//		}
//	}
//	cout<<"KAKTUS";
//}
//
//int main()
//{
//	scanf("%d %d\n", &r, &c);
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			scanf("%1c", &map[i][j]);
//			if (map[i][j] == 'S') { sx = i; sy = j; }
//			else if (map[i][j] == 'D') { endx = i; endy = j; }
//			else if (map[i][j] == '*') {
//				w.push_back({ i, j });
//			}
//		}
//		getchar();
//	}
//	bfs();
//
//	return 0;
//}
// https://donggod.tistory.com/19
/*------------------------------------------------------------------------------------------------------*/

//int h, w;
//char map[50][50];
//int dist[50][50];
//const int dx[4] = { -1, 1, 0, 0 };
//const int dy[4] = { 0, 0, -1, 1 };
//queue<pair<int, int>> biber;
//queue<pair<int, int>> water;
//
//void bfs_water() {
//	while (!biber.empty() && !water.empty()) {
//		int wy = water.front().first;
//		int wx = water.front().second;
//		int by = biber.front().first;
//		int bx = biber.front().second;
//
//		if (map[by][bx] == 'D') {
//			cout << dist[by][bx];
//			return;
//		}
//
//		map[wy][wx] = '*';//물이 참
//		water.pop();
//		for (int i = 0; i < 4; i++) {
//			int nwy = wy + dy[i];
//			int nwx = wx + dx[i];
//			if (nwy < 0 || nwy >= h || nwx < 0 || nwx >= w || map[nwy][nwx] == '*') continue; //이미 물이 차있는 곳도 제외
//			if (map[nwy][nwx] == 'D') continue;
//			water.push({ nwy, nwx });
//			map[nwy][nwx] = 'o'; //물이찰 예정
//		}
//
//		map[by][bx] = 's';
//		biber.pop();
//		for (int i = 0; i < 4; i++) {
//			int nby = by + dy[i];
//			int nbx = bx + dx[i];
//			if (nby < 0 || nby >= h || nbx < 0 || nbx >= w || dist[nby][nbx] != -1) continue;
//			if (map[nby][nbx] == 'o' || map[nby][nbx] == '*'||map[nby][nbx] == 'X') continue; //물이 찰 예정인 곳은 피한다.
//			biber.push({ nby, nbx });
//			dist[nby][nbx] = dist[by][bx] + 1;
//		}
//	}
//
//	cout << "KAKTUS";
//}

/*------------------------------------------------------------------------------------------------------*/
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int r, c;
//const int HEDGE = 0;
//const int WATER = 1;
//
//char Map[50][50];
//bool visit[50][50][2];
//
//// 상하좌우
//int dy[] = { -1,1,0,0 };
//int dx[] = { 0,0,-1,1 };
//
//queue <pair<int, int>> q[2];
//
//void moveWater() {
//	int qsize = q[WATER].size();
//	while (qsize--) {
//		int y = q[WATER].front().first;
//		int x = q[WATER].front().second;
//		q[WATER].pop();
//
//		for (int d = 0; d < 4; d++) {
//			int ny = y + dy[d];
//			int nx = x + dx[d];
//
//			// boundary
//			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
//			// visit or beeber's cave or stone
//			if (visit[ny][nx][WATER] || Map[ny][nx] == 'D' || Map[ny][nx] == 'X') continue;
//
//			visit[ny][nx][WATER] = true;
//			Map[ny][nx] = '*';
//			q[WATER].push({ ny,nx });
//		}
//	}
//}
//
//bool moveHedge() {
//	int qsize = q[HEDGE].size();
//	while (qsize--) {
//		int y = q[HEDGE].front().first;
//		int x = q[HEDGE].front().second;
//		q[HEDGE].pop();
//
//		// found
//		if (Map[y][x] == 'D') { return true; }
//
//		for (int d = 0; d < 4; d++) {
//			int ny = y + dy[d];
//			int nx = x + dx[d];
//
//			// boundary
//			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
//			// visit or water or stone
//			if (visit[ny][nx][HEDGE] || Map[ny][nx] == '*' || Map[ny][nx] == 'X' ) continue;
//
//			visit[ny][nx][HEDGE] = true;
//			q[HEDGE].push({ ny,nx });
//		}
//	}
//	return false;
//}
//
//void simulate() {
//	int time = -1;
//	while (true) {
//		moveWater();
//		bool escape = moveHedge();
//		time++;
//		// success
//		if (escape) { cout << time << '\n'; break; }
//
//		// fail
//		if (q[HEDGE].empty()) { cout << "KAKTUS" << '\n'; break; }
//	}
//}
//
//int main() {
//	cin >> r >> c;
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			cin >> Map[i][j];
//			// hedge
//			if (Map[i][j] == 'S') {
//				visit[i][j][HEDGE] = true;
//				q[HEDGE].push({ i,j });
//			}
//			else if (Map[i][j] == '*') {
//				visit[i][j][WATER] = true;
//				q[WATER].push({ i,j });
//			}
//		}
//	}
//	simulate();
//	return 0;
//}
//https://www.acmicpc.net/board/view/35373
/*------------------------------------------------------------------------------------------------------*/

//https://rebas.kr/661
//https://penglog.tistory.com/77
