#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, x;
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int Ans = 0;
		queue<pair<int, int>> qu;
		priority_queue<int> pq;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			qu.push({ x,i }); //1,0 / 2,1 / 3,2 / 4,3
			pq.push(x); //4 3 2 1
		}
		while (qu.size()) {
			int here = qu.front().first; //4//들어온 수
			int num = qu.front().second;//3 // 순서
			qu.pop(); // (1, 0 /2, 1 /3, 2 )

			if (pq.top() == here) { //4 != 1 // 4 != 2// 4 !=3 // 3
				Ans++;//1
				pq.pop();//4 / 
				if (num == m)break;
			}
			else qu.push({ here,num });//(1, 0/ 2, 1/ 3, 2 )
		}
		printf("%d\n", Ans);
	}
	return 0;
}
/* 
* Priority_queue 자료 저장 방법
*/