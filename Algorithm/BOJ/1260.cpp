#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//인접 행렬로 구현
bool visited[1001]; //정점 번호 1000번이 있을 경우, 1000번의 간선을 인접 행렬로 표현하기 위해서는
					//인덱스 1001까지 필요하다.
int v, e, s; 
vector<vector<int>> adj_m(v + 1, vector<int>(v + 1));


void dfs(int s) {
	visited[s] = true;
	cout << s << " ";
	for (int i = 1; i <= v; i++) {					   //원래는 정점의 번호 갯수 만큼 조사하나, 전역 변수가 아니니 < adj_m.size() 하면 된다.
		if (visited[i] == false && adj_m[s][i] == 1) { //행의 갯수, 즉 정점의 갯수와 동일하다.
			dfs(i);//해당 정점으로 건너간다.		   // adj_m이 전역 변수라면 <=v 로 해준다.
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
		for (int i = 1; i <= v; i++) { //정점 갯수 만큼 조사(인덱스 조심, 1부터 시작한다. 왜냐하면 인접 행렬에서는 정점 번호를 그대로 이용하기 때문.)                        
			if (visited[i] == false && adj_m[front][i] == 1) {
				q.push(i);         //해당 정점에서 이동 가능한 정점들을 모두 다 큐에 넣는다.
				visited[i] = true; //방문 했다고 표시한다??
			}
		}
	}
}

int main() {
	cin >> v >> e >> s;
	//정점 번호 1000번이 있을 경우, 1000번의 간선을 인접 행렬로 표현하기 위해서는 인덱스 1001까지 필요하다.
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


//1) 더 정교해지기 -> m을 전역변수로 두면 dfs에서 m 안넘길 수 있다.
//2) -> 2d vec 대신에 2d matrix 쓸 수 있다.
//3) -> 인접 리스트 써서 장단을 비교.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e, s;
//vector<int> adj_l(v); //v의 크기를 가진 벡터를 선언
//vector<int> adj_l[v]; //v개의 벡터를 선언 이때 에러가 난다. 상수가 필요하다. 이런 이유로 인접 행렬은 ... 그런데 막상 수행해보니 메모리/시간 에서 이득.
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
		for (int i = 0; i < adj_l[front].size(); i++) { //연결된 리스트이 갯수 만큼 조사.(인덱스 조심) 
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
		adj_l[v1].push_back(v2); //인접 리스트로 구현
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

//DFS와 BFS
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
//	adj = new list<int>[V + 1];//리스트를 원소로 가지는 배열을 가리키는 포인터
//}
//
//void Graph::add_edge(int v1, int v2) {
//	adj[v1].push_back(v2);
//}
//
//void Graph::DFSUtils(int v, bool visited[]) {
//	visited[v] = true;
//	cout << v << " ";
//	//adj[v].sort();//adj[v]를 sort해야 한다. 
//
//	list<int> ::iterator it;
//	for (it = adj[v].begin(); it != adj[v].end(); it++) {
//		if (!visited[*it])
//			DFSUtils(*it, visited);
//	}
//}
//
//void Graph::DFS(int v) {
//	bool *visited = new bool[V + 1];//정점 갯수 만큼 배열 생성
//	for (int i = 1; i < V + 1; i++) //1~5까지 조사
//		visited[i] = false;
//
//	for (int i = 1; i < V + 1; i++)//Proof disconnection vertex
//		if (visited[i] == false)//1~5까지 조사
//			DFSUtils(v, visited);
//}
//
//void Graph::BFS(int s) {
//	bool *visited = new bool[V + 1];//정점의 수 만큼 배열 동적 할당
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
