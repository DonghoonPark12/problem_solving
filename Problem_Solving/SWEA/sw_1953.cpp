//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//struct node {
//	int y, x, time;
//	node(int _y, int _x, int _time)
//		:y(_y), x(_x), time(_time)
//	{};
//};
////vector<vector<int>> arr(50, vector<int>(50));
//int arr[51][51];
//bool visited[51][51];
//queue<node> q;
//int p;
//int N, M, R, C, L;
//
//void bfs(int r, int c) {//세로 위치R, 가로 위치C
//	q.push(node(r, c, 1));
//	visited[r][c] = true;
//	
//	while (!q.empty()) {
//		int r = q.front().y;
//		int c = q.front().x;
//		int t = q.front().time;
//		q.pop();
//
//		if (t == L)
//			continue;
//
//		if (arr[r][c] == 1) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1));  visited[r][c + 1] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1));  visited[r + 1][c] = true; }
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//		}
//		else if (arr[r][c] == 2) { // |
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1)); visited[r + 1][c] = true; }
//		}
//		else if (arr[r][c] == 3) { // -
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1));  visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 4) {
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1)); visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 5) {
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1)); visited[r + 1][c] = true; }
//			if (arr[r][c + 1] != 0 && visited[r][c + 1] != 1) { q.push(node(r, c + 1, t + 1)); visited[r][c + 1] = true; }
//		}
//		else if (arr[r][c] == 6) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r + 1][c] != 0 && visited[r + 1][c] != 1) { q.push(node(r + 1, c, t + 1));  visited[r + 1][c] = true; }
//		}
//		else if (arr[r][c] == 7) {
//			if (arr[r][c - 1] != 0 && visited[r][c - 1] != 1) { q.push(node(r, c - 1, t + 1)); visited[r][c - 1] = true; }
//			if (arr[r - 1][c] != 0 && visited[r - 1][c] != 1) { q.push(node(r - 1, c, t + 1)); visited[r - 1][c] = true; }
//		}
//		else {}
//	}
//
//}
//
//int get_result() {
//	int sum = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (visited[i][j])
//				sum++;
//		}
//	}
//	return sum ;
//}
//
//void init() {
//	memset(arr, 0, sizeof(arr));
//	memset(visited, false, sizeof(visited));
//}
//int main(void)
//{
//	int T, test_case;
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		init();
//		cin >> N >> M >> R >> C >> L;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				cin>>arr[i][j];//c, r
//			}
//		}
//		//bfs(R, C);
//
//		while (!q.empty()) q.pop();
//		printf("#%d ", test_case + 1);
//		printf("%d\n", get_result());
//	}
//
//	return 0;
//
//}


//DFS 방식
#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;

int map[50][50];
int visited[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//int pipe[8][4] = {  // 우, 하 ,좌 ,상 
//	{ 0,0,0,0 },  //0
//	{ 1,1,1,1 },  //1
//	{ 0,1,0,1 },  //2
//	{ 1,0,1,0 },  //3 
//	{ 1,0,0,1 },  //4
//	{ 1,1,0,0 },  //5
//	{ 0,1,1,0 },  //6
//	{ 0,0,1,1 }   //7
//};

int pipe[8][4] = { //상, 하, 좌, 우
	{ 0,0,0,0 },
	{ 1,1,1,1 },
	{ 1,1,0,0 },
	{ 0,0,1,1 },
	{ 1,0,0,1 }, //4 
	{ 0,1,0,1 },
	{ 0,1,1,0 },
	{ 1,0,1,0 }
};

int T, N, M, R, C, L;
int result;

void DFS(int x, int y, int time) {
	if (time == L) {
		return;
	}
	int dest;

	for (int i = 0; i < 4; i++) { //0, 1, 2, 3 --> 1, 0, 3, 2
		int ax = x + dx[i];
		int ay = y + dy[i];

		if      (i == 0) dest = 1;
		else if (i == 1) dest = 0;
		else if (i == 2) dest = 3;
		else             dest = 2;

		if (ax >= 0 && ay >= 0 && ax < N && ay < M) {
			if (pipe[map[x][y]][i] == 1 && pipe[map[ax][ay]][dest] == 1) {

				if (!visited[ax][ay] || visited[ax][ay] > visited[x][y] + 1) {

					visited[ax][ay] = time + 1;
					DFS(ax, ay, time + 1);
				}
			}
		}
	}
}

int main() {
	int T, R, C;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));

		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		visited[R][C] = 1;
		DFS(R, C, 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j]) {
					cnt++;
				}
			}
		}
		cout << "#" << tc << " " << cnt << endl;
	}
}


//BFS 방식
//#include <cstdio>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int t, n, m, sx, sy, l, x, y, ax, ay, _time, cnt;
//int map[50][50];
//bool visited[50][50];
//int dx[] = { 1,-1,0,0 };//하, 상, 우, 좌
//int dy[] = { 0,0,1,-1 };
//
//typedef struct _Node {
//	int x;
//	int y;
//	int t;
//	_Node(int _x, int _y, int _t)
//		: x(_x), y(_y), t(_t)
//	{ }
//}Node;
//
//void init() {
//	memset(visited, false, sizeof(visited));
//	memset(map, 0, sizeof(map));
//}
//
//int getResult() {
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (visited[i][j]) {
//				cnt++;
//			}
//		}
//	}
//	return cnt;
//}
//
//void bfs(int a, int b) {
//	queue<Node> q;
//	q.push(Node(a, b, 1));
//	visited[a][b] = true;
//
//	while (!q.empty()) {
//		x = q.front().x;
//		y = q.front().y;
//		_time = q.front().t;
//		q.pop();
//
//		if (_time == l) {
//			continue;
//		}
//
//		for (int i = 0; i < 4; i++) {
//			ax = x + dx[i];
//			ay = y + dy[i];
//			if (ax >= 0 && ay >= 0 && ax < n && ay < m) {
//			if (!visited[ax][ay]) {                                          // 이동하려는 새로운 map위치 ax, ay
//					if (map[x][y] == 2) {if (i == 2 || i == 3) continue; }       //│ 경우 우, 좌 이동 불가
//					else if (map[x][y] == 3) { if (i == 0 || i == 1) continue; } //─ 경우 하, 상 이동 불가
//					else if (map[x][y] == 4) { if (i == 0 || i == 3) continue; } //└ 경우 하, 좌 이동 불가
//					else if (map[x][y] == 5) { if (i == 1 || i == 3) continue; } //┌ 경우 상, 좌 이동 불가
//					else if (map[x][y] == 6) { if (i == 1 || i == 2) continue; } // ┐경우 상, 우 이동 불가
//					else if (map[x][y] == 7) { if (i == 0 || i == 2) continue; } // ┘경우 하, 우 이동 불가
//
//					if (i == 0) {												 //하 일 경우, 
//						if (map[ax][ay] == 1 || map[ax][ay] == 2 || map[ax][ay] == 4 || map[ax][ay] == 7) { //┼,│,└ , ┘만 통과 가능.   
//							q.push(Node(ax, ay, _time + 1)); visited[ax][ay] = true;
//						}
//					}
//					else if (i == 1) {											 //상
//						if (map[ax][ay] == 1 || map[ax][ay] == 2 || map[ax][ay] == 5 || map[ax][ay] == 6) { //┼,│,┌ ,┐ 만 통과 가능.
//							q.push(Node(ax, ay, _time + 1)); visited[ax][ay] = true;
//						}
//					}
//					else if (i == 2) {											 //우
//						if (map[ax][ay] == 1 || map[ax][ay] == 3 || map[ax][ay] == 6 || map[ax][ay] == 7) {//┼,─, ┐, ┘ 만 통과 가능.   
//							q.push(Node(ax, ay, _time + 1)); visited[ax][ay] = true;
//						}
//					}
//					else {														 //좌
//						if (map[ax][ay] == 1 || map[ax][ay] == 3 || map[ax][ay] == 4 || map[ax][ay] == 5) {//┼,─,└,┌   만 통과 가능.  
//							q.push(Node(ax, ay, _time + 1)); visited[ax][ay] = true;
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &t);
//	for (int tc = 1; tc <= t; tc++) {
//		init();
//
//		scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &l);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				scanf("%d", &map[i][j]);
//			}
//		}
//
//		bfs(sx, sy);
//
//		printf("#%d %d\n", tc, getResult());
//	}
//	return 0;
//}
