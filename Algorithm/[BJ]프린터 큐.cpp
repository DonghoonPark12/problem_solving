#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <queue>
#include <deque>
using namespace std;

template <class ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
{
	if (first == last) return last;
	ForwardIterator largest = first;

	while (++first != last)
		if (*largest<*first)    // or: if (comp(*largest,*first)) for version (2)
			return 1
	return 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int Answer = 0, cnt = 0;
		int tmp; //임시로 저장할 변수

		int n, m;
		cin >> n >> m; // 4 2

		deque<int> papers;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", tmp);
			papers.push_back(tmp); //1(0) 2(1) 3(2) 4(3)
		}

		/* queue의 몇번째 원소를 어떻게 표현할 까 */
		int desti = papers.at(m);
		a = max_element(papers.begin(), papers.back());
		/* 큐 원소에 고유 아이디를 어떻게 부여 할까 */

		while (1)
		{
			//뒤에 우선순위가 더 높은 것이 있다면
			//queue를 함수 인자로 어떻게 전달할 까
			if ()
			{
				papers.push_back(papers.front());
				papers.pop_front();
			}
			//뒤에 우선 순위가 더 큰게 없다면
			//그리고 가장 앞에 있는 값이 m이라면 
			else if (papers.front() == desti && (max_element(papers.begin, papers.back) != 1)) //1이냐?? 뒤에 우선 순위 높은거 없냐?? 처음에 뽑고자한 값이었나??
			{
				Answer = cnt;
				break;
			}
			else
			{
				papers.pop_front(); //print한다.
				cnt++;
			}
		}
		printf("%d", Answer);
	}
	

	return 0;
}

// 뒤에 우선 순위가 높은 함수가 있으면 1을 반환
/*
int priority(papers)
{

	return 1;


	return 0;
}
*/