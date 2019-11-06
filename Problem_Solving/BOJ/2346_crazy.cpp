#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int it = 0;
	int it_old = 0;
	int n;
	int cnt = 0;

	//freopen("input.txt", stdin);

	scanf("%d", &n);

	int tmp;
	vector<int> v;
	for(int i=0;i<n;i++) {
		scanf(" %d", &tmp);
		v.push_back(tmp);
	}

	while (1) {
		printf("%d ", it+1);//1
		if (v.at(it_old) < 0) { //왼쪽으로 돌 것
			for (int i = 0; i < abs(v.at(it_old)); i++) {// i.g) -3이라면 절대값으로 계산
					it--; // 인덱스 감소
					if (v.at(it) == 0) { // 0이라면..
						while (v.at(it) == 0) { // 인덱스에 해당 값이 0 이 아닐때 까지
							it--; // 인덱스 감소
							if (it < 0) // 인덱스가 음수가 되면, 다시 뒷 줄로 넘어온다. 
								it = it + n;
						}
					}
			}
			if (it < 0)
				it =it + n;
		}
		else { //오른쪽으로 돌 것. 
			for (int i = 0; i < v.at(it_old); i++) { // i.g) 3이라면 3바퀴 회전
					it++; // 인덱스 증가
					if (v.at(it) == 0) { // 0이라면..
						while (v.at(it) == 0) { // 인덱스에 해당 값이 0 이 아닐때 까지
							it++; // 인덱스 증가
							if (it >= n) // 인덱스가 n의 크기가 되면, 다시 첫 줄로 넘어온다.
								it = it - n;
						}
					}
			}
			if (it > n)
				it = it - n;
		}

		v.at(it_old) = 0;

		it_old = it;

		for (int i = 0; i < n; i++) {
			if (v.at(i) == 0)
				cnt++;
		}
		if (cnt == n)
			break;
		else
			cnt = 0;
	}

	return 0;
}