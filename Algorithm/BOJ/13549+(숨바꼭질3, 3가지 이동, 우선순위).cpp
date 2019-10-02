#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int s, e;
// 13549. ���ٲ��� 3
/*
bfs�� ����ϱ� ���ؼ��� '��� ������ ����ġ�� �����ؾ� �Ѵ�'�� ���� ������ �ִ�.
bfs���� Ǯ���� �����غ���(�丶��: ����ġ�� �����ϴ� ������ �ű� �� ���� 1�� �����ϰ� �������״�)
(���࿡ �ʹ� �ð��� ���� ������ġ��� ���⼭�� ť�� �켱������ �־�� �ɰ��̴�.)
(�׸��� �ð��� ǥ���ߴ� dist�迭�� dist[ny][nx] = dist[ny][nx]�� �Ǿ�� �� ���̴�.)

�� ������ ����ġ�� 0��(�̵��� �ð��� ���� �ʴ�) ������ �ֱ� ������ �ܼ��� BFS�� �� �� ������, ������ Ư�� ������ �湮 ������ ���󼭵� BFS�� Ǯ���� ���� ��.

<����ġ�� 0 �� ������ �ִ� ��� Ǯ�� ��>
- ���ͽ�Ʈ�� �˰���
- 0-1BFS: ����ġ�� 0�� ������ ����� ������ ť�� �� �ڰ� �ƴ� �� �տ� �ִ� ���.
- ����ġ�� 0�� ����(*2 �϶�)�� ������ �������� �������� �ʰ�, �� ��ǥ�� 2 �ŵ����� ���� ��ǥ���� ��� ť�� �ִ� ���.
(https://www.acmicpc.net/board/view/38887)

<����>
�ణ�� ����� ��� ����. �ܼ� *2 cnt+1�� ���� �ʰ� cnt�� ���־ �±淡 �׷� �����ΰ� ���� �ߴµ�,
����ġ ���� ������ �־����� ��, ��� ó���� �������� ���� �����̴�.
�׷��� ����ġ�� ���⼭ �ð�+1�� �ǹ��Ѵ�.
����ġ�� ���� �ʴ� �ٴ� ���� �׻� �켱������ ó���� �����ϱ� ������ '�� push_front' ���ش�.

�׷����� �׷����� �Ϻ� dfs --> ���� bfs �� ����Ǵ� ����� �� �� �ִ�.
*/

const int MAX = 1e6;
int dist[MAX + 1]; //1e6���� �����ϴ� ��ġ ���� dist[1e6]�� �����ϱ� ���ؼ��� MAX+1 ũ��� �����ؾ� �Ѵ�. 
bool vis[MAX + 1] = { false };

void bfs3_1() {
	memset(dist, -1, sizeof(dist));//����ġ�� 0�� ������ �ְ�, dist �迭�� ������ -1�� �ʱ�ȭ ����� �Ѵ�(����, �� ������ �׷���.).
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
			if (n<0 || n>MAX || dist[n] >= 0) continue; //�׸��� dist[n]�� 0�̾ �湮�Ѱ����� ǥ���Ͽ� �����Ͽ��� �Ѵ�(����).
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

void bfs3_2() { //����ġ�� 0�� ����(*2 �϶�)�� ������ �������� �������� �ʰ�, �� ��ǥ�� 2 �ŵ����� ���� ��ǥ���� ��� ť�� �ִ� ���.
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
			if (n<0 || n>MAX || dist[n] >= 0) continue; //���ҿ� ��Ī�Ǵ� �Ÿ��� �迭�� �ִ´�.
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
				q.push_front({ cLoc * 2, cSec });    vis[2 * cLoc] = true; //�ڼ��� �̵��� �켱���� �ο�
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