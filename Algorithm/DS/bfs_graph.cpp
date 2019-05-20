#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;// # of vertices(������ ��)
	list<int> *adj;
public:
	Graph(int V); //������
	void addEdge(int v, int w); //Edge�� �׷����� �ִ� �Լ�
	void BFS(int v); //vertices�� ��ȸ
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V]; //������ ���� ��ŭ ����Ʈ ����. ���� ����Ʈ���� ǥ���ϱ� ���� ����Ʈ���̴�. 
							//list�� []������ �����ϴ� �ɷ� �˾Ƽ� �迭 �Ҵ��ϵ��� (new int[#]) �Ҵ��� �ȵ� �� �˾Ҵµ�, �̷��� �����Ѱ� ����. 
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v��s list. 
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];//������ �� ��ŭ �迭 ���� �Ҵ�
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
������ �ϳ����� ž�� ���� �˰����� �����ϸ� ���� ������ �����Ѵ�.
�������(tail recursion)�� �� ȿ��������, �Ϲ����� ��� �˰����� ��� ������� �˰������� ��ȯ�� �� �ִ��� ����
�̾߱��ϴٺ��� �Ѱ踦 ������.�̷� ������� �����ڰ� �Ǿ ������ ��ġ�Ǿ
�ü���� ������(loopback) �ּҶ�� ������ �������� ���ؼ� �ָ� �Դ´�.��Ͷ�� �˰����� �۵������ �Ӹ��ӿ��� �׷����� �ʴ� ſ�̴�.
��ó: ������ �д� ���α׷���
*/