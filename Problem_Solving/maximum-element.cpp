#define   _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	deque<int> dq;
	deque<int>::iterator it;
	int T;
	scanf("%d\n", &T);
	int ord = 0;
	int input_;

	int max = -1;
	for (int i = 0; i<T; i++) {
		scanf("%d ", &ord);
		if (ord == 1) {
			scanf("%d ", &input_);
			dq.push_back(input_);
			if (input_>max)
				max = input_;//미리미리 max 갱신
		}
		else if (ord == 2) {
			if (max == dq.back()) {//(1)가장 큰 값을 빼버렸다면
				dq.pop_back();//(2)어쨌든 빼긴 할건데
				max = 0; //(3)max를 다시 갱신한다.
				for (it = dq.begin(); it != dq.end(); it++) {
					if (*it>max) max = *it;
				}
			}
			else
				dq.pop_back();//(4)가장 큰 값이 아니라면 생각없이 뺀다. 
		}
		else {
			printf("%d\n", max);
		}
	}
	return 0;
}