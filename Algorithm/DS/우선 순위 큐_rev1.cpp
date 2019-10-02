#include <iostream>
#include <cstdio>
#include <functional>
#include <queue> 
using namespace std;

/*
	<����>
	priority_queue<�ڷ���, ����ü, �񱳿�����> �� ����
	�ڷ����� int, double, ����ü, Ŭ���� ���..
	(����ü�� ��� �񱳿��� �Լ��� ���� ������ �־�� �Ѵ�.)
	����ü�� �⺻������ vector<�ڷ���>, #include <vector> �� �ʿ� ����.
	less<�ڷ���>�� ��������
*/

/*------------------------------------------------------------------------------------------------*/
template<typename T>
void print_queue(T &q) {
	while (!q.empty()) {
		cout << q.top() << " "; q.pop();
	}
	cout << '\n';
}

struct Custom {
	int x;
	int y;
	int value;
	Custom(int value)
		: x(0), y(0), value(value)
	{ }
};

struct cmp2 {                                           // ������ �ٿ� ���ϸ� ����ü�� ����
	bool operator()(Custom const &t, Custom const &u) { // �����ڸ� ������ ���� �ȿ� �����ؼ� ������ �ִٰ� �Ѵ�.
		return t.value < u.value;                       // Ư���� ���� operator< �����ε��� �ƴ� operator() �����ε��ϱ�.
	}													// �Ʒ��� ��ũ�� �Ϻγ��� �ؼ��� �ִ�.                                                   
};														// https://www.google.com/search?q=c%2B%2B+priority+queue+overload&oq=c%2B%2B+priority_queue+over&aqs=chrome.1.69i57j0l5.10559j1j8&sourceid=chrome&ie=UTF-8	

bool operator<(Custom t, Custom u) {  //�̷��� ���൵ �ȴ�.;;;;
	//return t.value < u.value;       //Same as default. 8, 6, 5, 3, 1 (���� ����), "functional"�� less<int>�� ������ ����.     Max heap.
	return t.value > u.value;         //1, 3, 5, 6, 8 ,                             "functional"�� greater<int> �� ������ ����. Min heap.    
}

//https://koosaga.com/9
//https://twpower.github.io/93-how-to-use-priority_queue-in-cpp
/*------------------------------------------------------------------------------------------------*/

int main()
{
	/*------------------------------------------------------------------------------------------------*/
	// (1) Basic STL usage
	//priority_queue<int> pq;
	//pq.push(3);
	//pq.push(1);
	//pq.push(4);
	//pq.push(1);
	//pq.push(5);
	//pq.push(9);

	//while (!pq.empty())
	//{
	//	printf("%d ", pq.top());
	//	pq.pop();
	//}
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (2) Using 'Ranged-based for' and 'lambda'

	//priority_queue<int> q1; //default: Max Heap
	//for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
	//	q1.push(n);
	//print_queue(q1);        //9 8 7 6 5 4 3 2 1
	////cout<<q1.top()<<'\n';//9, Error because q1 is empty.


	//priority_queue<int, vector<int>, greater<int>> q2; //Min Heap, need #include <functional>
	//for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
	//	q2.push(n);
	//print_queue(q2);
	////cout<<q2.top()<<'\n';//1, Error because q2 is empty.

	//// Using lambda to campare elements
	//auto cmp = [](int left, int right) {
	//	return (left ^ 1) < (right ^ 1);
	//};

	//priority_queue<int, vector<int>, decltype(cmp)>q3(cmp);
	//for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
	//	q3.push(n);
	//print_queue(q3);
	//https://en.cppreference.com/w/cpp/container/priority_queue
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (3) Custom Ŭ���� + ���Լ� ����1
	//priority_queue<Custom, vector<Custom>, cmp2> q4;

	//priority_queue<Custom, vector<Custom>> q4;
	//for (Custom n : {Custom(1), Custom(8), Custom(5), Custom(6), Custom(3)})
	//	q4.push(n);
	//while (!q4.empty()) {
	//	cout << q4.top().value << " "; q4.pop();
	//}
	//https://twpower.github.io/93-how-to-use-priority_queue-in-cp
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (4) Custom Ŭ���� + ���Լ� ����2

	//http://3map.snu.ac.kr/gb/bbs/board.php?bo_table=advance2014&wr_id=3

	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (5) Dijkstra������ Ȱ��
	
	//https://hsp1116.tistory.com/42?category=547783 : ����
	//https://dhpark-ghost.herokuapp.com/2018/06/12/c-daigseuteura-dijkstra-algorijeum/ : stl
	//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/ : stl ���
	//https://makefortune2.tistory.com/259?category=695910 : ���� ���� ����. MST, Prim, Kstuskal, A*, ����-����
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (6) Minimum Spanning Tree(MST)������ Ȱ��

	//https://www.crocus.co.kr/733
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (7) Kruskal������ Ȱ��

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (8) Prim������ Ȱ��

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (9) Huffman������ Ȱ�� 

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	// () Heap������ ����
	return 0;
}



