#include <iostream>
#include <vector>
using namespace std;

void pick(int n, vector<int>& picked, int toPick) {
	// n: 전체 원소의 수
	// picked: 지금까지 고른 원소들의 번호
	// topick: 더 고를 원소의 수
	if (toPick == 0) { printPicked(picked); return; }
	//고를 수 있는 가장 작은 번호 계산
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	//이 단계에서 원소 하나를 고른다.
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

void recur(int s, int n) {
	if (n == 1) {

	}
	cout << s
}

int main() {
	int n = 7;
	/*
	중복 없이 4개의 원소를 고른다. 
	*/
	//for (int i = 0; i < n; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		for (int k = j + 1; k < n; k++) {
	//			for (int l = k + 1; l < n; l++) {
	//				cout << i << ' ' << j << ' ' << k << ' '<<l << endl;
	//			}
	//		}
	//	}
	//}

	recur(0, n);
}