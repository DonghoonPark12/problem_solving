#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<pair<int, int>> d;
	priority_queue<int> pq;
	//deque<pair<int, int>>::iterator iter;
	for (int i = 0; i < priorities.size(); i++) {
		if (i == location) 
			d.push_back(pair<int, int>(priorities[i], 1));
		else
			d.push_back(pair<int, int>(priorities[i], 0));
		pq.push(priorities[i]);
	}
	int cnt = 0;
	pair<int, int> tmp;
	while (!d.empty()) {
		if (d.front().first < pq.top()) {//자기보다 우선순위가 높은게 있으면
			tmp = d.front();
			d.push_back(tmp);
			d.pop_front();
		}
		else {
			cnt++; //프린트 동작 횟수
			if (d.front().second == 1) {
				answer = cnt;
				break;
			}
			d.pop_front();
			pq.pop();
		}
	}
	return answer;
}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int n, location;
		vector<int> prio;
		cin >> n >> location;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			prio.push_back(tmp);
		}
		Answer = solution(prio, location);
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("%d\n", Answer);
	}

	return 0;

}


//#include<cstdio>
//#include<queue>
//#pragma warning(disable :4996)
//using namespace std;
//
//int main(void)
//{
//	int t;
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &t);
//	int queue[102][2];
//	int t;
//	for (scanf("%d", &t); t--;)
//	{
//		int n, m;
//		scanf("%d%d", &n, &m);
//		int i;
//		for (i = 0; i<n; i++)
//		{
//			scanf("%d", &queue[i][0]);
//			queue[i][1] = i;
//		}
//		int s = 0;
//		for (;;)
//		{
//			for (i = 1; i<n; i++)
//			{
//				if (queue[0][0]<queue[i][0])break;
//			}
//			if (i != n)
//			{
//				queue[n][0] = queue[0][0];
//				queue[n][1] = queue[0][1];
//			}
//			else
//			{
//				s++;
//				n--;
//				if (queue[0][1] == m)break;
//			}
//			for (i = 0; i<n; i++)
//			{
//				queue[i][0] = queue[i + 1][0];
//				queue[i][1] = queue[i + 1][1];
//			}
//		}
//		printf("%d\n", s);
//	}
//	return 0;
//}
