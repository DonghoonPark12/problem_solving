#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//���� ��ķ� ����
bool visited[1001]; //���� ��ȣ 1000���� ���� ���, 1000���� ������ ���� ��ķ� ǥ���ϱ� ���ؼ���
					//�ε��� 1001���� �ʿ��ϴ�.
int v, e, s; 
vector<vector<int>> adj_m(v + 1, vector<int>(v + 1));


void dfs(int s) {
	visited[s] = true;
	cout << s << " ";
	for (int i = 1; i <= v; i++) {					   //������ ������ ��ȣ ���� ��ŭ �����ϳ�, ���� ������ �ƴϴ� < adj_m.size() �ϸ� �ȴ�.
		if (visited[i] == false && adj_m[s][i] == 1) { //���� ����, �� ������ ������ �����ϴ�.
			dfs(i);//�ش� �������� �ǳʰ���.		   // adj_m�� ���� ������� <=v �� ���ش�.
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		for (int i = 1; i <= v; i++) { //���� ���� ��ŭ ����(�ε��� ����, 1���� �����Ѵ�. �ֳ��ϸ� ���� ��Ŀ����� ���� ��ȣ�� �״�� �̿��ϱ� ����.)                        
			if (visited[i] == false && adj_m[front][i] == 1) {
				q.push(i);         //�ش� �������� �̵� ������ �������� ��� �� ť�� �ִ´�.
				visited[i] = true; //�湮 �ߴٰ� ǥ���Ѵ�??
			}
		}
	}
}

int main() {
	cin >> v >> e >> s;
	//���� ��ȣ 1000���� ���� ���, 1000���� ������ ���� ��ķ� ǥ���ϱ� ���ؼ��� �ε��� 1001���� �ʿ��ϴ�.
	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		adj_m[v1][v2] = 1;
		adj_m[v2][v1] = 1;
	}
	dfs(s);
	memset(visited, false, sizeof(visited));
	cout << endl;
	bfs(s);
	return 0;
}


//1) �� ���������� -> m�� ���������� �θ� dfs���� m �ȳѱ� �� �ִ�.
//2) -> 2d vec ��ſ� 2d matrix �� �� �ִ�.
//3) -> ���� ����Ʈ �Ἥ ����� ��.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e, s;
//vector<int> adj_l(v); //v�� ũ�⸦ ���� ���͸� ����
//vector<int> adj_l[v]; //v���� ���͸� ���� �̶� ������ ����. ����� �ʿ��ϴ�. �̷� ������ ���� ����� ... �׷��� ���� �����غ��� �޸�/�ð� ���� �̵�.
bool visited[1001];
vector<int> adj_l[1001];

void dfs(int s) {
	visited[s] = true;
	cout << s << " ";
	for (int i = 0; i < adj_l[s].size(); i++) {
		if (visited[ adj_l[s][i] ] == false) {
			dfs( adj_l[s][i] );
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		for (int i = 0; i < adj_l[front].size(); i++) { //����� ����Ʈ�� ���� ��ŭ ����.(�ε��� ����) 
			if (visited[adj_l[front][i]] == false) {
				q.push(adj_l[front][i]);
				visited[adj_l[front][i]] = true;
			}
		}
	}
}

int main() {
	cin >> v >> e >> s;
	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		adj_l[v1].push_back(v2); //���� ����Ʈ�� ����
		adj_l[v2].push_back(v1);
	}
	for (int i = 1; i <= v; i++) {
		sort(adj_l[i].begin(), adj_l[i].end());
	}
	dfs(s);
	memset(visited, false, sizeof(visited));
	cout << endl;
	bfs(s);
	return 0;
}

/*----------------------------------------WTF--------------------------------------*/

//DFS�� BFS
//#include <iostream>
//#include <list>
//using namespace std;
//
//class Graph {
//	int V; //number of vertices;
//public:
//	list<int> *adj;
//	Graph(int v);
//	void add_edge(int v, int w);
//
//	void DFSUtils(int v, bool visited[]);
//	void DFS(int v);
//	void BFS(int v);
//};
//
//Graph::Graph(int V) {
//	this->V = V;
//	adj = new list<int>[V + 1];//����Ʈ�� ���ҷ� ������ �迭�� ����Ű�� ������
//}
//
//void Graph::add_edge(int v1, int v2) {
//	adj[v1].push_back(v2);
//}
//
//void Graph::DFSUtils(int v, bool visited[]) {
//	visited[v] = true;
//	cout << v << " ";
//	//adj[v].sort();//adj[v]�� sort�ؾ� �Ѵ�. 
//
//	list<int> ::iterator it;
//	for (it = adj[v].begin(); it != adj[v].end(); it++) {
//		if (!visited[*it])
//			DFSUtils(*it, visited);
//	}
//}
//
//void Graph::DFS(int v) {
//	bool *visited = new bool[V + 1];//���� ���� ��ŭ �迭 ����
//	for (int i = 1; i < V + 1; i++) //1~5���� ����
//		visited[i] = false;
//
//	for (int i = 1; i < V + 1; i++)//Proof disconnection vertex
//		if (visited[i] == false)//1~5���� ����
//			DFSUtils(v, visited);
//}
//
//void Graph::BFS(int s) {
//	bool *visited = new bool[V + 1];//������ �� ��ŭ �迭 ���� �Ҵ�
//	for (int i = 1; i < V + 1; i++)
//		visited[i] = false;
//
//	//Create a queue for BFS
//	queue<int> q;
//
//	// Mark the current node as visited and enqueue it
//	visited[s] = true;
//	q.push(s);
//
//	//'i' will be used to get all adjacent
//	list<int>::iterator it;
//
//	while (!q.empty()) {
//		s = q.front();
//		cout << s << " ";
//		q.pop();
//
//		//Get all the adjacent vertices of the dequeued vertex s.
//		//If adjacent has not been visited, then mark it visited and enqueue it.
//		for (it = adj[s].begin(); it != adj[s].end(); ++it)
//		{
//			if (!visited[*it])
//			{
//				visited[*it] = true;
//				q.push(*it);
//			}
//		}
//	}
//}
//
//int main() {
//	int n, m, start;
//	freopen("input.txt", "r", stdin);
//	cin >> n >> m >> start;
//	Graph g(n);
//	int v1, v2;
//	for (int i = 0; i < m; i++) {
//		cin >> v1 >> v2;
//		g.add_edge(v1, v2);
//		g.add_edge(v2, v1);
//	}
//	for (int i = 1; i < n + 1; i++) {
//		g.adj[i].sort();
//	}
//	g.DFS(start);
//	cout << "\n";
//	g.BFS(start);
//	return 0;
//}
