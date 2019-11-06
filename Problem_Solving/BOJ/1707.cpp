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
이분 그래프(Bipartite Graph)란 인접한 노드는 서로 다른 색의 노드로 구분되고, 그래프 내 모든 노드를 2가지 색으로 칠할 수 있는 그래프를 말한다.

1/-1 그룹으로 나눈다. 만략 다음 노드가 이미 방문한 노드라면, 현재 노드의 그룹 번호와 다음 노드의 그룹 번호가 같은지 확인한다.
같다면 인접 노드가 같은 그룹이므로 False 리턴한다.

dfs가 끝날 때 까지 false를 리턴하지 않았다면 이분 그래프이다.
*/

vector<int> node[20001];
int check[20001]; // Init : 0, -1 or 1.

bool dfs(int now, int group) {
	check[now] = group; //Groups are divided into 1 or -1.
	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i];
		if (check[next] == 0) {         //인접 노드가 방문되지 않았다면
			if (!dfs(next, -1*group)) { //인접한 노드에 -1을 부여한다.
				return false;           //false를 반환한다면 현재 함수에서도 false 반환
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
		for (int i = 0; i < e; i++) {//간선의 갯수 만큼
			cin >> v1 >> v2;
			node[v1].push_back(v2);
			node[v2].push_back(v1);
		}
		bool ans = true;
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {  //방문되지 않았다면
				if (!dfs(i, 1)) { //dfs조사하여 false면 break;
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
//	if (pick1.size() == v) return;//원소수가 정점의 수와 동일한 집합은 필요 없다.
//
//	if (pick1.size() != 0) { //공집합이나
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
//void check(int i) { //i번째 vv[i] 벡터에 담긴 접점끼리 서로 이어 지는지 조사, 하나라도 이어지면 possible = false;
//	//int f = vv[i].size();
//	//for (int s1 = 0; s1 < f-1; s1++) {
//	//	for (int s2 = s1+1; s2 < f; s2++) {
//	//		if (node[vv[i][s1]][vv[i][s2]] == 1) //(오류)<---간선이 존재 하지 않으면 검사 조차 에러뜬다!!!
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
//      //이차원 벡터 node 초기화도 필요하다.
//		possible = true;
//		memset(visited, false, sizeof(visited));
//		cin >> v >> e;
//		for (int i = 0; i < e; i++) {//간선의 갯수 만큼
//			cin >> v1 >> v2;
//			node[v1].push_back(v2);
//			node[v2].push_back(v1);
//		}
//		back_track(1);
//
//		for (int i = 0; i < vv.size(); i++) {
//			if (vv[i].size() == 1) continue;//노드가 하나면 인접할 정점 조차 없을 것이고
//			else check(i); //노드가 2개 이상일 때 인접 하지 않는지 조사한다. 하나라도 이어지면 
//
//			if (possible) { printf("YES");	break;	}
//		}
//		if (!possible){	printf("NO"); }
//	}
//	return 0;
//}


