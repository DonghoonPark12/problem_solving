#include <iostream>
#include <vector>
#include <string>
using namespace std;
//바이러스
int com, n;
vector<int> adjl[101];
bool visited[101];
int cnt;

void dfs(int st) {
	visited[st] = true;
	for (int i = 0; i < adjl[st].size(); i++) {
		int next = adjl[st][i];
		if (visited[next] != true) {
			dfs(next);
			cnt++;
		}
	}
}

int main() {
	cin >> com >> n; 
	int v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> v1 >> v2;
		adjl[v1].push_back(v2);
		adjl[v2].push_back(v1);
	}
	//memset(visited, false, sizeof(visited));
	dfs(1);
	cout << cnt;
	return 0;
}
