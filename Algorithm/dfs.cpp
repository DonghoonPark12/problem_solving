#include <iostream>
#include <list>
using namespace std;
/*
����Ʈ�� ����ؾ� �ϴ� ���� ������ ��.
1. ������ �����Ͱ� �������̴�. 
2. �߰� ������ ����, ������ ���� �Ͼ��.
3. (����) ������ �����Ͱ� �����鼭 �˻��� ���� �Ѵٸ� ����Ʈ ���ٴ� map, set, hasp_map�� ����Ѵ�.
4. (����) �����͸� �����ϰ� �����ϴ� ��찡 ������ ����Ʈ�� �������� �ʴ�.
   - ����Ʈ�� ���� ���ٸ� �����ϴ�. iter�� ���ؼ� �����Ѵ�. 
http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS6976941148
*/
class Graph {
	int V;// # of vertices(������ ��)
	
	list<int> *adj;// ���� ����Ʈ�� ���ҷ� ������ �迭�� ����Ű�� ������ 
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V); //������
	void addEdge(int v, int w); //Edge�� �׷����� �ִ� �Լ�
	void DFS(int v); //vertices�� ��ȸ
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V]; //������ ���� ��ŭ ����Ʈ ����. ���� ����Ʈ���� ǥ���ϱ� ���� ����Ʈ���̴�. 
							//list�� []������ �����ϴ� �ɷ� �˾Ƽ� �迭 �Ҵ��ϵ��� (new int[#]) �Ҵ��� �ȵ� �� �˾Ҵµ�, �̷��� �����Ѱ� ����. 
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); //Add w to v's list.
}

void Graph::DFSUtil(int v, bool visited[]) {//(1)���� ������ �迭�� �Է� �޴´�.
	visited[v] = true; //(2)�ش� ������ �湮���� ǥ���ϰ�.
	cout << v << " ";

	//Recur for all the vertices adjacent to this list
	list<int> ::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)//[0, 3]
		if (!visited[*it])//(3)������ ���� �ε����� ������. �ش� ������ ��������Ʈ�� �湮���� �ʾ��� ���.
			DFSUtil(*it, visited);//(4)�ش� ������ ���������� �ؼ� (visited�迭�� �Ѱ� �����鼭) �Լ��� �ٽ� ȣ��.
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];//������ �� ��ŭ �迭 ���� �Ҵ�.
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//Call the recursive helper function to print DFS traversal starting from all vertices one by one.
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			DFSUtil(v, visited); //If visited[0] is true, recur DFSUtil(2, visited) ??
}

int main() {
	Graph g(4); //���� 4�� ���� �׷��� ����.
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}