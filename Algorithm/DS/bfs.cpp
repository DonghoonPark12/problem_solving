#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;// # of vertices(정점의 수)
	list<int> *adj;
public:
	Graph(int V); //생성자
	void addEdge(int v, int w); //Edge를 그래프에 넣는 함수
	void BFS(int v); //vertices의 순회
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V]; //정점의 갯수 만큼 리스트 생성. 인접 리스트들을 표현하기 위한 리스트들이다. 
							//list는 []연산자 사용못하는 걸로 알아서 배열 할당하듯이 (new int[#]) 할당이 안될 줄 알았는데, 이렇게 가능한가 보다. 
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];//정점의 수 만큼 배열 동적 할당
	for (int i = 0; i < V; i++)
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
	}
}

// Driver program to test methods of graph class 
int main()
{
	// Create a graph given in the above diagram 
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}