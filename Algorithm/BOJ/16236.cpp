//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n;
//int m[20][20];
//
//const int dx[4] = { 0, -1, 0, 1 }; //위, 왼쪽, 아래, 오른쪽
//const int dy[4] = { -1, 0, 1, 0};
//
//typedef struct _fish {
//	int y, x;
//	int size;
//	int dis2s;
//
//	bool operator <(const _fish &a) {
//		//return this->dis2s < a.dis2s;
//		if (this->dis2s == a.dis2s) {
//			if (this->y < a.y)
//				return true;
//			else if (this->y == a.y) {
//				if (this->x < a.x) return true;
//				else return  false;
//			}
//			else {
//				if (this->y < a.y) return true;
//				else return false;
//			}
//		}
//		else {
//			return this->dis2s < a.dis2s;
//		}
//	}
//
//}fish;
//
//typedef struct _sh{
//	int y, x;
//	int size;
//
//	//int time;
//	//int eat;
//}sh;
//
//int num_f;
//fish f[400];
////int dist[400];
//sh s;
//
//int dis;
//
//int eatable;
//
//int t;
//
//int cnt;
//
///*
//bool cmp(const fish &a, const fish &b) {
//	if (a.dis2s == b.dis2s) { 
//		if (b.y < a.y) { return true; }
//		else if (b.y == a.y) { //y 높이가 같으면
//			if (b.x < a.x) return true;
//			else return false;
//		}
//		else
//			false;//
//	}
//	else if (a.dis2s < b.dis2s)//
//		return true;
//	else
//		return false;
//}
//*/
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> m[i][j];
//			if (m[i][j] != 0 && m[i][j] != 9) { 
//				f[num_f].y = i;
//				f[num_f].x = j;
//				f[num_f].size = m[i][j];
//				num_f++;
//				if (m[i][j] < 2) { eatable++; }
//			}
//			if (m[i][j] == 9) {
//				s.y = i; s.x = j; s.size = 2;
//
//				//s.eat = 0; s.time = 0;
//				m[i][j] = 0;
//			}
//		}
//	}
//
//
//	if (eatable == 0 || (eatable == 1 && f[0].size >= s.size)) {
//		cout << "0";
//		return 0;
//	}
//	else if (eatable == 1 && f[0].size < s.size) {
//		dis = abs(s.x - f[0].x) + abs(s.y - f[0].y);
//		cout << dis;
//		return 0;
//	}
//
//
//	
//	while(eatable){
//		for (int i = 0; i < num_f; i++) { 
//			f[i].dis2s = abs(s.x - f[i].x) + abs(s.y - f[i].y);
//		}
//
//		sort(f, f + num_f);
//
//		//target을 정하고
//		int target = 0;
//		while (1) {
//			if (f[target].size > s.size) target++;
//			else break;
//		}
//
//		//4방향 탐색하면서 이동
//		while ((s.x != f[target].x) || (s.y != f[target].y)) {
//			int i;
//			for (i = 0; i < 4; i++) {
//				int nx = s.x + dx[i];
//				int ny = s.y + dy[i];
//
//				// 경계 벗어나거나, 이동한 곳에 몸무게가 같거나 큰 것이 존재하면
//				if (nx <0 || nx > n || ny < 0 || ny > n || m[ny][nx] > s.size)
//					continue;
//
//				// target과의 거리가 되려 멀어지나면 pass
//				if ((abs(nx - f[target].x) + abs(ny - f[target].y)) > (abs(s.x - f[target].x) + abs(s.y - f[target].y)))
//					continue;
//
//				break;
//			}
//
//			s.x = dx[i]; s.y = dy[i];
//			t++;
//		}
//
//		//물고기 먹음
//		num_f--;
//		s.y = 0; s.x = 0;
//		cnt++;
//		if (cnt == s.size) {
//			s.size++;
//			cnt = 0;
//
//			//eatable 업데이트
//			eatable = 0;
//			for (int i = 0; i < num_f; i++) {
//				if (s.size > f[i].size) eatable++;
//			}
//		}
//
//
//	}
//
//	cout << t;
//
//	return 0;
//}

//na982
/*
#include <iostream>
#include <queue>
using namespace std;

typedef struct _sh {
	int y, x,time;
}sh;

int n;
int m[20][20];

int s_size, cnt;
sh s;

const int dx[4] = { 0, -1, 0, 1 }; //위, 왼쪽, 아래, 오른쪽
const int dy[4] = { -1, 0, 1, 0 };


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				s.y = i, s.x = j, s.time = 0;
				s_size = 2, cnt = 0;
				m[i][j] = 0;
			}
		}
	}

	bool is_update = true;
	while (is_update) {
		is_update = false;
		
		bool visited[20][20] = { false, };
		queue<sh> q;
		visited[s.y][s.x] = true;
		q.push(s);

		sh target;
		target.y = 20, target.time = -1;
		while (!q.empty()) {
			sh cur = q.front(); q.pop();

			//아직 갱신이 되지 않고
			//가장 가까운 물고기를 잡음
			if (target.time != -1 && target.time < cur.time)
				break;

			if (m[cur.y][cur.x] < s_size && m[cur.y][cur.x] != 0) {
				is_update = true;
				if (target.y > cur.y || (target.y == cur.y && target.x > cur.x)) {
					target = cur;
				}
			}
			
			for (int dir = 0; dir < 4; dir++) {
				sh next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.x <0 || next.x >= n || next.y < 0 || next.y >= n)
					continue;

				if (visited[next.y][next.x] == false && s_size >= m[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		if (is_update) {
			s = target;
			++cnt;
			if (cnt == s_size) {
				++s_size;
				cnt = 0;
			}
			m[s.y][s.x] = 0;
		}
	}

	cout << s.time;
	return 0;
}
*/

	//물고기 먹을 수 있는지 여부?

		
	/*	
	bool is_update = true;
	while (is_update) {
		is_update = false;

		queue<sh> q;
		bool visited[20][20] = { false, };
		visited[s.y][s.x] = true;
		q.push(s);

		sh c;
		c.y = 20, c.time = -1;
		while (!q.empty()) {
			sh cur = q.front(); q.pop();

			if (c.time != -1 && c.time < cur.time) {
				break; //가장 가까운 물고기를 잡음
			}

			if (m[cur.y][cur.x] < s.size && m[cur.y][cur.x] != 0) {
				is_update = true;
				if (c.y > cur.y || (c.y == cur.y && c.x > cur.x)) {
					c = cur;
				}
			}

			for (int dir = 0; dir < 4; ++dir) {
				sh ne;
				ne.y = cur.y + dy[dir];
				ne.x = cur.x + dx[dir];
				ne.time = c.time + 1;

				if (ne.y < 0 || ne.y >= n || ne.x < 0 || ne.x >= n)
					continue;

				if (visited[ne.y][ne.x] == false && s.size >= m[ne.y][ne.x]) {
					visited[ne.y][ne.x] = true;
					q.push(ne);
				}
			}
		}

		if (is_update) {
			s = c;
			++s.eat;
			if (s.eat == s.size) {
				++s.size;
				s.eat = 0;
			}
			m[s.y][s.x] = 0;
		}

	}
	*/

#include <iostream>
//#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct shark {
	int d, x, y;//d는 상어로 부터의 거리
	//min_heap
	bool operator < (const shark &m) const {
		if (d == m.d) {
			if (x == m.x) return y > m.y; //x가 동일하면 m의 y값이 더 크면 false
			else return x > m.x;

		}
	}
};

int n, body, eat, ans;
int m[20][20];
bool visited[20][20];
priority_queue<shark> q;

const int dy[] = { 0, 0, -1, +1 };
const int dx[] = { -1, +1, 0, 0 };

void bfs() {
	while (!q.empty()) {
		int d = q.top().d, x = q.top().x, y = q.top().y;
		q.pop();
		if (m[y][x] != 0 && m[y][x] < body) {
			m[y][x] = 0; //eat fish
			eat++;

			// Body size + 1
			if (eat == body) {
				body++; eat = 0;
			}
			ans += d;
			// Initializing distance, visited check and queue.
			d = 0;
			memset(visited, false, sizeof(visited));
			while (!q.empty()) q.pop();
		}
		//explore using bfs
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx > n || y < 0 || ny > n || visited[ny][nx]) continue;
			if (m[y][x] != 0 && m[y][x] > body) continue;

			q.push({d+1, ny, nx});
			visited[ny][nx] = true;
		}
	}
}

void solve() {
	bfs();
	cout << ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				q.push({ 0, i, j });
				body = 2; m[i][j] = 0;
			}
		}
	}
	solve();
	return 0;
}
