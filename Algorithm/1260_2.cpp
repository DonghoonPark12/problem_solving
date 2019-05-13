#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool visited[1001];
void dfs(int s, vector<vector<int>>m) {
	visited[s] = true;
	cout << s + 1 << " ";
	for (int i = 0; i<m.size(); i++) {
		if (visited[i] == false && m[s][i] == 1) {
			dfs(i, m);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int v, e, s;
	cin >> v >> e >> s;
	vector<int> rows(v);//¹è¿­
	for (int i = 0; i<v; i++) rows[i] = 0;

	vector<vector<int>> matrix;
	for (int i = 0; i<v; i++) {
		matrix.push_back(rows);
	}
	int v1, v2;
	for (int i = 0; i <e; i++) {
		cin >> v1 >> v2;
		matrix[v1 - 1][v2 - 1] = 1;
		// matrix[v2-1][v1-1]=1; 
	}
	dfs(s - 1, matrix);
	for (int i = 0; i<v; i++) {
		if (visited[i] == false) dfs(i, matrix);
	}
	for (int i = 0; i<v; i++) {
		visited[i] = false;
	}

	cout << endl;
	queue<int>q;
	q.push(s - 1);
	visited[s - 1] = true;
	while (!q.empty()) {
		int front = q.front();
		cout << front + 1 << " ";
		q.pop();
		for (int i = 0; i<v; i++) {
			if (visited[i] == false && matrix[front][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
	return 0;
}