#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int s, e; 

/*
	3가지 동작이 있고, 한번의 동작에 1초가 걸리며, 목적(지)에 도달하기 위한 최소 시간을 출력하는 문제이다.
*/
const int MAX = 1e6;
int dist[MAX+1]; //1e6점에 대응하는 위치 값을 dist[1e6]에 저장하기 위해서는 MAX+1 크기로 선언해야 한다. 
bool vis[MAX + 1] = { false };

//void bfs1() {
//	queue<int> q;
//	q.push(s);
//	dist[s] = 0;
//	while (!q.empty()) {
//		int c = q.front(); q.pop();
//		if (c == e) {
//			cout << dist[c];
//			break;
//		}
//		for (int n : {c - 1, c + 1, 2 * c}) {
//			if (n<0 || n>MAX || dist[n]) continue; //원소에 매칭되는 거리를 배열에 넣는다.
//			q.push(n);
//			dist[n] = dist[c] + 1;//2178.미로탐색, 7576.토마토와 같이 bfs 최단거리/시간을 구할 때 2D배열 인접한 곳에 +1을 해주었는데
//								  //본 문제와 같이 배열의 구간이 정해져 있는 경우, 수에 대응하는 배열 값을 깊이로 가져갈 수 있다.
//								  //인접하여 값이 저장되지 않는다. 
//		}
//	}
//}

//void bfs2() {
//	queue<int> q;
//	q.push(s);
//	while (!q.empty()) {
//		int c = q.front(); q.pop();
//		if (c == e) { //if (c==e)  dist would be '0'
//			cout << dist[c];
//			break;
//		}
//		if (c - 1 >= 0 && !dist[c - 1]) {
//			q.push(c - 1); dist[c - 1] = dist[c] + 1;
//		}
//		if (c + 1 <= MAX && !dist[c + 1]) {
//			q.push(c + 1); dist[c + 1] = dist[c] + 1;
//		}
//		if (c * 2 <= MAX && !dist[c * 2]) {
//			q.push(c * 2); dist[c * 2] = dist[c] + 1;
//		}
//	}
//}

//void bfs3() {
//	queue<int> q;
//	q.push(s);
//	int depth = 0;
//	while (!q.empty()) {
//		int size = q.size();
//		for (int i = 0; i < size; i++) {
//			int c = q.front(); q.pop();
//			if (c == e) { //if (c==e)  dist would be '0'
//				cout << depth;
//				break;
//			}
//			if (c - 1 >= 0 && !vis[c-1]) {
//				q.push(c - 1); vis[c - 1] = true;
//			}
//			if (c + 1 <= MAX && !vis[c+1]) {
//				q.push(c + 1); vis[c + 1] = true;
//			}
//			if (c * 2 <= MAX && !vis[c*2]) {
//				q.push(c * 2); vis[2 * c] = true;
//			}
//		}
//		depth++;
//	}
//}

void bfs4() { //<-------------- pick
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	vis[s] = true;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cLoc = q.front().first;
			int cSec = q.front().second;
			q.pop();
			if (cLoc == e) { //if (c==e)  dist would be '0'
				cout << cSec;
				break;
			}
			if (cLoc - 1 >= 0 && !vis[cLoc - 1]) {
				q.push({ cLoc - 1, cSec + 1 }); vis[cLoc - 1] = true;
			}
			if (cLoc + 1 <= MAX && !vis[cLoc + 1]) {
				q.push({ cLoc+ 1, cSec + 1 }); vis[cLoc + 1] = true;
			}
			if (cLoc * 2 <= MAX && !vis[cLoc * 2]) {
				q.push({ cLoc * 2, cSec + 1}); vis[2 * cLoc] = true;
			}
		}
	}
}

int main() {
	cin >> s >> e;
	//dfs(s, 0);
	bfs4();
	return 0;
}

// 다익스트라 풀이는 나중에 보자
//숨바꼭질:  https://jason9319.tistory.com/151
//숨바꼭질3: https://jason9319.tistory.com/80

/*---------------------------------------------------------------------------------------------------------------*/
/*
	숨바꼭질 dfs로 풀이 시도 하였던 코드
*/
//int _time;
//int _min = 0x7ffffff;
//int arr[100001];
//
//void dfs(int pos, int _time) {
//	if (pos > e || pos <0) return;
//	if (pos == e) {
//		_min = min(_time, _min);
//		return;
//	}
//	if (arr[pos] != 1) {
//		//arr[pos] = 1;
//
//		dfs(pos + 1, _time + 1);
//		dfs(pos * 2, _time + 1);
//		dfs(pos - 1, _time + 1);
//		
//		//arr[pos] = 0;
//	}
//}

//int depth;
//void bfs() { //error
//	queue<pair<int, int>> q;
//	q.push({ s, depth });
//	while (!q.empty()) {
//		int c = q.front().first;
//		if (c == e) {
//			cout << q.front().second;
//			break;
//		}
//		q.pop();
//		depth++;
//		for (int n : {c - 1, c + 1, 2 * c}) {
//			q.push({ n, depth});
//		}
//	}
//}

