/*
* priority_queue<자료형, 구현체, 비교연산자> 로 정의
* 자료형은 int, double, 구조체, 클래스 등등..
* (구조체의 경우 비교연산 함수를 따로 정의해 주어야 한다.)
* 구현체는 기본적으로 vector<자료형>
* less<자료형>은 내림차순
*/

#include <cstdio>
#include <queue>
using namespace std;

//priority_queue<int, vector<int>, less<int> > pq;
//
//struct str {
//	int start;
//	int end;
//	int value;
//};
//
//bool operator<(str t, str u) {
//	return t.value < u.value;
//}

priority_queue<int> pq;

int main()
{
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);

	while (!pq.empty())
	{
		printf("%d ", pq.top());
		pq.pop();
	}
}


/*
#include <cstdio>
#include <queue>
using namespace std;

struct a{
	int start;
	int end;
	int value;
};

struct cmp{
	bool operator()(a t, a u){
	return t.value < u.value;
	}
};

priority_queue<a,vector<a>,cmp> pq;
*/