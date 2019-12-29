#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int s, e;
// 13549. 숨바꼭질 3
/*
bfs를 사용하기 위해서는 '모든 간선의 가중치가 동일해야 한다'는 전제 조건이 있다.
bfs문제 풀때를 생각해보라(토마토: 가중치가 동일하니 정점을 옮길 때 마다 1씩 동일하게 증가시켰다)
(만약에 익는 시간이 없는 무가중치라면 여기서도 큐의 우선순위에 넣어야 될것이다.)
(그리고 시간을 표현했던 dist배열은 dist[ny][nx] = dist[ny][nx]가 되어야 할 것이다.)

이 문제는 가중치가 0인(이동에 시간이 들지 않는) 간선이 있기 때문에 단순한 BFS를 쓸 수 없지만, 문제의 특성 때문에 방문 순서에 따라서도 BFS로 풀리는 것일 뿐.

<가중치가 0 인 간선이 있는 경우 풀이 법>
- 다익스트라 알고리즘
- 0-1BFS: 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 맨 앞에 넣는 방법.
- 가중치가 0인 간선(*2 일때)를 별도의 간선으로 생각하지 않고, 그 좌표의 2 거듭제곱 배인 좌표들을 모두 큐에 넣는 방법.
(https://www.acmicpc.net/board/view/38887)

<고찰>
약간의 충격을 줬던 문제. 단순 *2 cnt+1을 하지 않고 cnt를 해주어서 맞길래 그런 문제인가 보다 했는데,
가중치 없는 간선이 주어졌을 때, 어떻게 처리할 것인지를 묻는 문제이다.
그래프 가중치는 여기서 시간+1을 의미한다.
가중치가 들지 않는 다는 것은 항상 우선순위로 처리가 가능하기 때문에 '덱 push_front' 해준다.

그래프를 그려보면 일부 dfs --> 이후 bfs 가 진행되는 모습을 볼 수 있다.
*/

const int MAX = 1e6;
int dist[MAX + 1]; //1e6점에 대응하는 위치 값을 dist[1e6]에 저장하기 위해서는 MAX+1 크기로 선언해야 한다. 
bool vis[MAX + 1] = { false };

void bfs3_1() {
	memset(dist, -1, sizeof(dist));//가중치가 0인 간선이 있고, dist 배열을 쓰려면 -1로 초기화 해줘야 한다(불편, 이 문제만 그렇다.).
	deque<int> q;
	q.push_back(s);
	dist[s] = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop_front();
		if (c == e) {
			cout << dist[c];
			break;
		}
		for (int n : {c - 1, c + 1, 2 * c}) {
			if (n<0 || n>MAX || dist[n] >= 0) continue; //그리고 dist[n]도 0이어도 방문한것으로 표시하여 제외하여야 한다(불편).
			if (n == (2 * c)) {
				q.push_front(n);
				dist[n] = dist[c];
			}
			else {
				q.push_back(n);
				dist[n] = dist[c] + 1;
			}
		}
	}
}

void bfs3_2() { //가중치가 0인 간선(*2 일때)를 별도의 간선으로 생각하지 않고, 그 좌표의 2 거듭제곱 배인 좌표들을 모두 큐에 넣는 방법.
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		if (c == e) {
			cout << dist[c];
			break;
		}
		for (int n : {c - 1, c + 1, 2 * c}) {
			if (n<0 || n>MAX || dist[n] >= 0) continue; //원소에 매칭되는 거리를 배열에 넣는다.
			if (n == 2 * c) {
				int next = n;
				while (next <= MAX + 1 && dist[next] == -1) {
					q.push(next);
					dist[next] = dist[c];
					next *= 2;
				}
			}
			else {
				q.push(n);
				dist[n] = dist[c] + 1;
			}
		}
	}
}

void bfs3_3() {//<-------------- pick
	deque<pair<int, int>> q;
	q.push_back({ s, 0 });
	vis[s] = true;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cLoc = q.front().first;
			int cSec = q.front().second;
			q.pop_front();
			if (cLoc == e) { //if (c==e)  dist would be '0'
				cout << cSec;
				break;
			}
			if (cLoc * 2 <= MAX && !vis[cLoc * 2]) {
				q.push_front({ cLoc * 2, cSec });    vis[2 * cLoc] = true; //★순간 이동은 우선순위 부여
			}
			if (cLoc - 1 >= 0 && !vis[cLoc - 1]) {
				q.push_back({ cLoc - 1, cSec + 1 }); vis[cLoc - 1] = true;
			}
			if (cLoc + 1 <= MAX && !vis[cLoc + 1]) {
				q.push_back({ cLoc + 1, cSec + 1 }); vis[cLoc + 1] = true;
			}
		}
	}
}

int main() {
	cin >> s >> e;
	//dfs(s, 0);
	bfs3_3();
	return 0;
}