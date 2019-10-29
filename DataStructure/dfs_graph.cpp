#include <iostream>
#include <list>
using namespace std;
/*
리스트를 사용해야 하는 경우와 주의할 점.
1. 저장할 데이터가 가변적이다. 
2. 중간 데이터 삽입, 삭제가 자주 일어난다.
3. (주의) 저장할 데이터가 많으면서 검색을 자주 한다면 리스트 보다는 map, set, hasp_map을 사용한다.
4. (주의) 데이터를 랜점하게 접근하는 경우가 많으면 리스트가 적합하지 않다.
   - 리스트는 순차 접근만 가능하다. iter를 통해서 접근한다. 
http://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS6976941148
*/
class Graph {
	int V;// # of vertices(정점의 수)
	
	list<int> *adj;// 인접 리스트를 원소로 가지는 배열을 가리키는 포인터 
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V); //생성자
	void addEdge(int v, int w); //Edge를 그래프에 넣는 함수
	void DFS(int v); //vertices의 순회
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V]; //정점의 갯수 만큼 리스트 생성. 인접 리스트들을 표현하기 위한 리스트들이다. 
							//list는 []연산자 사용못하는 걸로 알아서 배열 할당하듯이 (new int[#]) 할당이 안될 줄 알았는데, 이렇게 가능한가 보다. 
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); //Add w to v's list.
}

void Graph::DFSUtil(int v, bool visited[]) {//(1)시작 정점과 배열을 입력 받는다.
	visited[v] = true; //(2)해당 정점은 방문함을 표시하고.
	cout << v << " ";

	//Recur for all the vertices adjacent to this list
	list<int> ::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)//[0, 3]
		if (!visited[*it])//(3)정점의 값을 인덱스로 가진다. 해당 정점의 인접리스트가 방문되지 않았을 경우.
			DFSUtil(*it, visited);//(4)해당 정점을 시작점으로 해서 (visited배열을 넘겨 받으면서) 함수를 다시 호출.
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];//정점의 수 만큼 배열 동적 할당.
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//Call the recursive helper function to print DFS traversal starting from all vertices one by one.
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			DFSUtil(v, visited); //If visited[0] is true, recur DFSUtil(2, visited) ??
}

int main() {
	Graph g(4); //정점 4개 가진 그래프 생성.
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