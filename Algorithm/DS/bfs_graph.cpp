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
	memset(visited, false, sizeof(visited));
	
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

/*
하지만 하노이의 탑과 같은 알고리즘이 등장하면 숨이 막히기 시작한다.
꼬리재귀(tail recursion)가 왜 효율적인지, 일반적인 재귀 알고리즘을 어떻게 꼬리재귀 알고리즘으로 변환할 수 있는지 등을
이야기하다보면 한계를 느낀다.이런 사람들은 개발자가 되어서 실전에 배치되어도
운영체제의 루프백(loopback) 주소라는 개념을 이해하지 못해서 애를 먹는다.재귀라는 알고리즘의 작동방식이 머릿속에서 그려지지 않는 탓이다.
출처: 누워서 읽는 프로그래밍
*/