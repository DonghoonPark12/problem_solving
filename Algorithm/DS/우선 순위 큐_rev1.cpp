#include <iostream>
#include <cstdio>
#include <functional>
#include <queue> 
using namespace std;

/*
	<개요>
	priority_queue<자료형, 구현체, 비교연산자> 로 정의
	자료형은 int, double, 구조체, 클래스 등등..
	(구조체의 경우 비교연산 함수를 따로 정의해 주어야 한다.)
	구현체는 기본적으로 vector<자료형>, #include <vector> 할 필요 없다.
	less<자료형>은 내림차순
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

struct cmp2 {                                           // 참조한 바에 의하면 구조체를 만들어서
	bool operator()(Custom const &t, Custom const &u) { // 연산자를 다음과 같이 안에 정의해서 쓸수도 있다고 한다.
		return t.value < u.value;                       // 특이한 점은 operator< 오버로딩이 아닌 operator() 오버로딩일까.
	}													// 아래의 링크에 일부나마 해설이 있다.                                                   
};														// https://www.google.com/search?q=c%2B%2B+priority+queue+overload&oq=c%2B%2B+priority_queue+over&aqs=chrome.1.69i57j0l5.10559j1j8&sourceid=chrome&ie=UTF-8	

bool operator<(Custom t, Custom u) {  //이렇게 해줘도 된다.;;;;
	//return t.value < u.value;       //Same as default. 8, 6, 5, 3, 1 (내림 차순), "functional"의 less<int>와 역할이 동일.     Max heap.
	return t.value > u.value;         //1, 3, 5, 6, 8 ,                             "functional"의 greater<int> 와 역할이 동일. Min heap.    
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
	// (3) Custom 클래스 + 비교함수 예제1
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
	// (4) Custom 클래스 + 비교함수 예제2

	//http://3map.snu.ac.kr/gb/bbs/board.php?bo_table=advance2014&wr_id=3

	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (5) Dijkstra에서의 활용
	
	//https://hsp1116.tistory.com/42?category=547783 : 설명
	//https://dhpark-ghost.herokuapp.com/2018/06/12/c-daigseuteura-dijkstra-algorijeum/ : stl
	//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/ : stl 사용
	//https://makefortune2.tistory.com/259?category=695910 : 면접 문제 예시. MST, Prim, Kstuskal, A*, 벨만-포드
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (6) Minimum Spanning Tree(MST)에서의 활용

	//https://www.crocus.co.kr/733
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (7) Kruskal에서의 활용

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (8) Prim에서의 활용

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------------------*/
	// (9) Huffman에서의 활용 

	// https://dhpark-ghost.herokuapp.com/2018/06/12/c-keuruseukal-kruskal-algorijeum/
	/*------------------------------------------------------------------------------------------------*/

	// () Heap으로의 구현
	return 0;
}



