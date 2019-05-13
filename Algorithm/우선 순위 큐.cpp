/*
* priority_queue<�ڷ���, ����ü, �񱳿�����> �� ����
* �ڷ����� int, double, ����ü, Ŭ���� ���..
* (����ü�� ��� �񱳿��� �Լ��� ���� ������ �־�� �Ѵ�.)
* ����ü�� �⺻������ vector<�ڷ���>
* less<�ڷ���>�� ��������
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