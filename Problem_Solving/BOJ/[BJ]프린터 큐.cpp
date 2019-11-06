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
		int tmp; //�ӽ÷� ������ ����

		int n, m;
		cin >> n >> m; // 4 2

		deque<int> papers;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", tmp);
			papers.push_back(tmp); //1(0) 2(1) 3(2) 4(3)
		}

		/* queue�� ���° ���Ҹ� ��� ǥ���� �� */
		int desti = papers.at(m);
		a = max_element(papers.begin(), papers.back());
		/* ť ���ҿ� ���� ���̵� ��� �ο� �ұ� */

		while (1)
		{
			//�ڿ� �켱������ �� ���� ���� �ִٸ�
			//queue�� �Լ� ���ڷ� ��� ������ ��
			if ()
			{
				papers.push_back(papers.front());
				papers.pop_front();
			}
			//�ڿ� �켱 ������ �� ū�� ���ٸ�
			//�׸��� ���� �տ� �ִ� ���� m�̶�� 
			else if (papers.front() == desti && (max_element(papers.begin, papers.back) != 1)) //1�̳�?? �ڿ� �켱 ���� ������ ����?? ó���� �̰����� ���̾���??
			{
				Answer = cnt;
				break;
			}
			else
			{
				papers.pop_front(); //print�Ѵ�.
				cnt++;
			}
		}
		printf("%d", Answer);
	}
	

	return 0;
}

// �ڿ� �켱 ������ ���� �Լ��� ������ 1�� ��ȯ
/*
int priority(papers)
{

	return 1;


	return 0;
}
*/