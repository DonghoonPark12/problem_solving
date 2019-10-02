#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
	//ABCDE

	//틀린 이해
	dfs로 (0,1,2,3)에서 출발하여 (1,2,3,4)로 갈수 있는지 파악해야 되는 문제.
	0에서 출발하여 1로 갈 수 있는지, 
	1에서 출발하여 2로 갈 수 있는지,
	2에서 출발하여 3로 갈 수 있는지,
	3에서 출발하여 4로 갈 수 있는지 확인하자.

	//문제에서 원하는 것
	어느 정점에서 출발해도 상관 없으니 방문하지 않은 정점을 이어서 길이가 5가 될 수 있는지 묻는 문제.
	벡트레킹 방식으로 미로 찾기로 해서 길이 5이상 들어 갈 수 있는지 확인한다.

	그래프 dfs : visited 확인은 for문은 앞(for문 밖에).
	그래프 벡트래킹 : visited 확인 for문 앞/뒤.
*/
vector<int> node[2000];
bool visited[2000];
int n, m;
int possible;
void dfs(int s, int cnt) {
	if (cnt == 4) {
		possible = 1;
		return;
	}
	visited[s] = true;            //그래프에서 dfs는 for문 밖 앞/뒤에 visited 확인을 한다. 배열의 백트레킹은 for문 안에 visited 표시를 한다.(1181번 부분 수열의 합 참고)
	for (int i = 0; i < node[s].size(); i++) {
		int next = node[s][i];    //다음 간선, 행으로는 배열 처럼 접근할 수 있다.
		if (!visited[next]) {     //방문되지 않았다면
			dfs(next, cnt+1);
			if (possible) return; //이부분이 시간을 많이 절약해준다.
		}
	}
	visited[s] = false;
}
int main() {
	cin >> n >> m;
	
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		node[v1].push_back(v2);
		node[v2].push_back(v1);
	}

	for (int i = 0; i < n; i++) { //모든 정점으로 부터 시작해서 길이가 5인
		//memset(visited, false, sizeof(visited));//벡트레킹 방식에서는 visited 초기화 해줄 필요 없다. 
		dfs(i, 0);
		if (possible) break;
	}
	cout << possible;
	return 0;
}