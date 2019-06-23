//DFS와 BFS
#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V; //number of vertices;
public:
	list<int> *adj;
	Graph(int v);
	void add_edge(int v, int w);

	void DFSUtils(int v, bool visited[]);
	void DFS(int v);
	void BFS(int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V+1];//리스트를 원소로 가지는 배열을 가리키는 포인터
}

void Graph::add_edge(int v1, int v2) {
	adj[v1].push_back(v2);
}

void Graph::DFSUtils(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	//adj[v].sort();//adj[v]를 sort해야 한다. 

	list<int> ::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++) {
		if (!visited[*it])
			DFSUtils(*it, visited);
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[V+1];//정점 갯수 만큼 배열 생성
	for (int i = 1; i < V+1; i++) //1~5까지 조사
		visited[i] = false;

	for (int i = 1; i < V+1; i++)//Proof disconnection vertex
		if (visited[i] == false)//1~5까지 조사
			DFSUtils(v, visited);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V+1];//정점의 수 만큼 배열 동적 할당
	for (int i = 1; i < V+1; i++)
		visited[i] = false;

	//Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	q.push(s);

	//'i' will be used to get all adjacent
	list<int>::iterator it;

	while (!q.empty()) {
		s = q.front();
		cout << s << " ";
		q.pop();

		//Get all the adjacent vertices of the dequeued vertex s.
		//If adjacent has not been visited, then mark it visited and enqueue it.
		for (it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
}

int main() {
	int n, m, start;
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> start;
	Graph g(n);
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		g.add_edge(v1, v2);
		g.add_edge(v2, v1);
	}
	for (int i = 1; i < n + 1; i++) {
		g.adj[i].sort();
	}
	g.DFS(start);
	cout << "\n";
	g.BFS(start);
	return 0;
}


#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool visited[1001];
void dfs(int s, vector<vector<int>>m) {
	visited[s] = true;
	cout << s << " ";
	for (int i = 1; i<m.size(); i++) {
		if (visited[i] == false && m[s][i] == 1) {
			dfs(i, m);
		}
	}
}
int main()
{
	int v, e, s;
	freopen("input.txt", "r", stdin);
	cin >> v >> e >> s;
	vector<vector<int>>matrix(v+1, vector<int>(v+1));
	int v1, v2;
	for (int i = 0; i <e; i++) {
		cin >> v1 >> v2;
		matrix[v1][v2]=1;
		matrix[v2][v1]=1; 
	}
	dfs(s, matrix);
	memset(visited, false, sizeof(visited));
	cout << endl;

	queue<int>q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		for (int i = 1; i<v+1; i++) {
			if (visited[i] == false && matrix[front][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return 0;
}