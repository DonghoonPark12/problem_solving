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
