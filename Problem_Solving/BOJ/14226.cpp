/*
	이모티콘 문제.
	3개의 동작이 존재하며, 한번의 동작에 1초가 걸리며, 목적(지)에 도달하기 위한 최소 시간을 구하는 문제이다.

	2178.미로탐색-->1679.숨바꼭질-->14226.이모티콘-->13549.숨바꼭질3
	-->1261.알고스팟--> 13460. 구슬탈출2 로 난이도를 높여가며 풀 수 있다. 

	: 단순 2차원 배열에서 4가지 이동 방향의 bfs + dist[ny][nx]
	: 3가지 이동 방식의 bfs + dist[MAX]로 시간 저장.
	: 3가지 이동 방식의 bfs + dist[][]로 상태에 따른 시간 저장.
    : 가중치가 0인 간선이 존재할때 bfs + dist[c]

	: 단순 2차원 배열에서 4가지 이동 방향. 하지만 벽을 부수는 것이 가중치(1), 방의 이동은 가중치(0) : 미로탐색 + 숨바꼭질3 문제.
	: 4가지 이동 방식의 bfs + dist[][][][][]로 상태에 따른 시간 저장.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int dist[2*MAX][2*MAX];//모니터의 이모티콘 수, 클립보드의 이모티콘 수
int depth;
int s;
//void bfs() {
//	queue<pair<int, int>> q;
//	q.push({ 1,0 });
//	dist[1][0] = 1;
//	while (!q.empty()) {
//		
//		int size = q.size();
//		for (int i = 0; i < size; i++) {
//			int cm = q.front().first;
//			int cc = q.front().second;
//			q.pop();
//
//			if (cm == s) {
//				cout << depth;
//				return;
//			}
//			if (dist[cm][cm] != 1) {
//				q.push({ cm, cm });
//				dist[cm][cm] = 1;
//			}
//			if (cc != 0 && cm + cc <= s && dist[cm + cc][cc] != 1) { //모니터에 붙여넣기 할때, s 보다 커질 이유는 없다. 1000으로 해도된다.
//				q.push({ cm + cc, cc });                             //2*s 하는 경우보다 수행시간 절반 아낄 수 있다. 
//				dist[cm + cc][cc] = 1;
//			}
//			if (cm-1>=1 && dist[cm - 1][cc] != 1) { //s보다 작아지게 뺄 이유는 없다(x) --> >=s로 하면 틀림으로 뜨며 >=1로 해야 맞음으로 뜬다.
//				q.push({ cm - 1, cc });
//				dist[cm - 1][cc] = 1;
//			}
//		}
//		depth++;
//	}
//
//}

void bfs2() {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	int cm, cc;
	while (!q.empty()) {
		cm = q.front().first;
		cc = q.front().second;
		q.pop();
		if (cm == s) {
			cout << dist[cm][cc];
			return;
		}
		// --------------------------------------------- //
		//int nm[] = { cm, cm + cc, cm - 1 };
		//int nc[] = { cm,      cc,     cc };
		//for (int i = 0; i < 3; i++) {
		//	if (nm[i] < 0 || nm[i] > s) continue;
		//	if (dist[nm[i]][nc[i]]) continue;

		//	q.push({ nm[i], nc[i] });
		//	dist[nm[i]][nc[i]] = dist[cm][cc] + 1;
		//}
		// 고수의 스킬
		// --------------------------------------------- //

		if (!dist[cm][cm]) {
			q.push({ cm, cm });
			dist[cm][cm] = dist[cm][cc] + 1;
		}

		if (cm + cc <= s && !dist[cm+cc][cc]) {
			q.push({ cm + cc, cc });
			dist[cm + cc][cc] = dist[cm][cc] + 1;
		}
		
		if (cm - 1 >= 0 && !dist[cm-1][cc]) {
			q.push({ cm - 1, cc });
			dist[cm - 1][cc] = dist[cm][cc] + 1;
		}
	}
}
int main() {
	cin >> s;
	bfs2();
	//cout<<bfs2();

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------ */

//int _min = 0x7fffffff;

// 맞는 풀이 하지만, 시간초과
//bool operator==(vector<int> l, vector<int> r) {
//	if (l.size() == r.size()) {
//		for (int i = 0; i < l.size(); i++) {
//			if (l[i] != r[i])
//				return false;
//		}
//		return true;
//	}
//	return false;
//}
//
//void sit(vector<int> m, vector<int> c, int t) {
//	if (t > _min) return;
//	if (m.size() > n) return;
//	if (m.size() == n) {
//		_min = min(_min, t); return;
//	}
//	vector<int> tmp;
//
//	if (m != c) { //같으면 덮어쓰기 할 이유가 없다.
//		tmp = c; //copies all the elements from 'c' into the left.
//		sit(m, m, t + 1);//모니터에 있는 이모티콘을 클립보드에 덮어쓰기
//		c = tmp;
//	}
//
//	if (!c.empty()) { //클립보드가 비어 있지 않은 경우에만 붙여넣기
//		tmp = m;
//		m.insert(m.end(), c.begin(), c.end());//(https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector)
//		sit(m, c, t + 1);
//		m = tmp;
//	}
//
//	if (!m.empty()) {
//		int tm = m.back();
//		m.pop_back();
//		sit(m, c, t + 1);
//		m.push_back(tm);
//	}
//}
//int main() {
//	cin >> n;
//	vector<int> v;
//	vector<int> c;
//	v.push_back(1);
//	sit(v, c, 0);
//	cout << _min;
//	return 0;
//}
