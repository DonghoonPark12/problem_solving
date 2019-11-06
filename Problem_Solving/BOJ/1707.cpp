#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int v, e; 
//vector<int> pick1;
//vector<vector<int>> vv;
//
//vector<int> node[20000];
//bool visited[20001];
//bool possible;

/*
�̺� �׷���(Bipartite Graph)�� ������ ���� ���� �ٸ� ���� ���� ���еǰ�, �׷��� �� ��� ��带 2���� ������ ĥ�� �� �ִ� �׷����� ���Ѵ�.

1/-1 �׷����� ������. ���� ���� ��尡 �̹� �湮�� �����, ���� ����� �׷� ��ȣ�� ���� ����� �׷� ��ȣ�� ������ Ȯ���Ѵ�.
���ٸ� ���� ��尡 ���� �׷��̹Ƿ� False �����Ѵ�.

dfs�� ���� �� ���� false�� �������� �ʾҴٸ� �̺� �׷����̴�.
*/

vector<int> node[20001];
int check[20001]; // Init : 0, -1 or 1.

bool dfs(int now, int group) {
	check[now] = group; //Groups are divided into 1 or -1.
	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i];
		if (check[next] == 0) {         //���� ��尡 �湮���� �ʾҴٸ�
			if (!dfs(next, -1*group)) { //������ ��忡 -1�� �ο��Ѵ�.
				return false;           //false�� ��ȯ�Ѵٸ� ���� �Լ������� false ��ȯ
			}
		}
		else if (check[now] == check[next]) {
			return false;
		}
	}
	return true;
}

int main() {
	int t; cin >> t;
	int v1, v2;
	while (t--) {
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			node[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < e; i++) {//������ ���� ��ŭ
			cin >> v1 >> v2;
			node[v1].push_back(v2);
			node[v2].push_back(v1);
		}
		bool ans = true;
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {  //�湮���� �ʾҴٸ�
				if (!dfs(i, 1)) { //dfs�����Ͽ� false�� break;
					ans = false;
					break;
				}
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}

//void back_track(int pos) {
//	if (pick1.size() == v) return;//���Ҽ��� ������ ���� ������ ������ �ʿ� ����.
//
//	if (pick1.size() != 0) { //�������̳�
//		vv.push_back(pick1);
//	}
//
//	for (int i = pos; i <= v; i++) {
//		if (!visited[i]) {
//			pick1.push_back(i);
//			visited[i] = true;
//			back_track(i);
//			pick1.pop_back();
//			visited[i] = false;
//		}
//	}
//}
//
//void check(int i) { //i��° vv[i] ���Ϳ� ��� �������� ���� �̾� ������ ����, �ϳ��� �̾����� possible = false;
//	//int f = vv[i].size();
//	//for (int s1 = 0; s1 < f-1; s1++) {
//	//	for (int s2 = s1+1; s2 < f; s2++) {
//	//		if (node[vv[i][s1]][vv[i][s2]] == 1) //(����)<---������ ���� ���� ������ �˻� ���� �������!!!
//	//			possible = false;
//	//	}
//	//	if (!possible) break; //speed finish
//	//}
//
//}
//
//int main() {
//	int t; cin >> t;
//	int v1, v2;
//	while (t--) {
//      //������ ���� node �ʱ�ȭ�� �ʿ��ϴ�.
//		possible = true;
//		memset(visited, false, sizeof(visited));
//		cin >> v >> e;
//		for (int i = 0; i < e; i++) {//������ ���� ��ŭ
//			cin >> v1 >> v2;
//			node[v1].push_back(v2);
//			node[v2].push_back(v1);
//		}
//		back_track(1);
//
//		for (int i = 0; i < vv.size(); i++) {
//			if (vv[i].size() == 1) continue;//��尡 �ϳ��� ������ ���� ���� ���� ���̰�
//			else check(i); //��尡 2�� �̻��� �� ���� ���� �ʴ��� �����Ѵ�. �ϳ��� �̾����� 
//
//			if (possible) { printf("YES");	break;	}
//		}
//		if (!possible){	printf("NO"); }
//	}
//	return 0;
//}


