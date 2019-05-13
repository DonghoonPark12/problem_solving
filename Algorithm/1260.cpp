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
	adj = new list<int>[V+1];//����Ʈ�� ���ҷ� ������ �迭�� ����Ű�� ������
}

void Graph::add_edge(int v1, int v2) {
	adj[v1].push_back(v2);
}

void Graph::DFSUtils(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	//adj[v].sort();//adj[v]�� sort�ؾ� �Ѵ�. 

	list<int> ::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++) {
		if (!visited[*it])
			DFSUtils(*it, visited);
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[V+1];//���� ���� ��ŭ �迭 ����
	for (int i = 1; i < V+1; i++) //1~5���� ����
		visited[i] = false;

	for (int i = 1; i < V+1; i++)//Proof disconnection vertex
		if (visited[i] == false)//1~5���� ����
			DFSUtils(v, visited);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V+1];//������ �� ��ŭ �迭 ���� �Ҵ�
	for (int i = 1; i < V+1; i++)
		visited[i] = false;

	//Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	//'i' will be used to get all adjacent
	list<int>::iterator it;

	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		//Get all the adjacent vertices of the dequeued vertex s.
		//If adjacent has not been visited, then mark it visited and enqueue it.
		for (it = adj[s].begin(); it != adj[s].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
		//sort �ؾ� �Ѵ�.
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