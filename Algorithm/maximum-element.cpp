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
				max = input_;//�̸��̸� max ����
		}
		else if (ord == 2) {
			if (max == dq.back()) {//(1)���� ū ���� �����ȴٸ�
				dq.pop_back();//(2)��·�� ���� �Ұǵ�
				max = 0; //(3)max�� �ٽ� �����Ѵ�.
				for (it = dq.begin(); it != dq.end(); it++) {
					if (*it>max) max = *it;
				}
			}
			else
				dq.pop_back();//(4)���� ū ���� �ƴ϶�� �������� ����. 
		}
		else {
			printf("%d\n", max);
		}
	}
	return 0;
}