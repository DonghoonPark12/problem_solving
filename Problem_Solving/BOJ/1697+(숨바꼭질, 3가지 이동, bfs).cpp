#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int s, e; 

/*
	3���� ������ �ְ�, �ѹ��� ���ۿ� 1�ʰ� �ɸ���, ����(��)�� �����ϱ� ���� �ּ� �ð��� ����ϴ� �����̴�.
*/
const int MAX = 1e6;
int dist[MAX+1]; //1e6���� �����ϴ� ��ġ ���� dist[1e6]�� �����ϱ� ���ؼ��� MAX+1 ũ��� �����ؾ� �Ѵ�. 
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
//			if (n<0 || n>MAX || dist[n]) continue; //���ҿ� ��Ī�Ǵ� �Ÿ��� �迭�� �ִ´�.
//			q.push(n);
//			dist[n] = dist[c] + 1;//2178.�̷�Ž��, 7576.�丶��� ���� bfs �ִܰŸ�/�ð��� ���� �� 2D�迭 ������ ���� +1�� ���־��µ�
//								  //�� ������ ���� �迭�� ������ ������ �ִ� ���, ���� �����ϴ� �迭 ���� ���̷� ������ �� �ִ�.
//								  //�����Ͽ� ���� ������� �ʴ´�. 
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

// ���ͽ�Ʈ�� Ǯ�̴� ���߿� ����
//���ٲ���:  https://jason9319.tistory.com/151
//���ٲ���3: https://jason9319.tistory.com/80

/*---------------------------------------------------------------------------------------------------------------*/
/*
	���ٲ��� dfs�� Ǯ�� �õ� �Ͽ��� �ڵ�
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

