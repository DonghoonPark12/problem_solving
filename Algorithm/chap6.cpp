#include <iostream>
#include <vector>
using namespace std;

void pick(int n, vector<int>& picked, int toPick) {
	// n: ��ü ������ ��
	// picked: ���ݱ��� �� ���ҵ��� ��ȣ
	// topick: �� �� ������ ��
	if (toPick == 0) { printPicked(picked); return; }
	//�� �� �ִ� ���� ���� ��ȣ ���
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	//�� �ܰ迡�� ���� �ϳ��� ����.
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
	�ߺ� ���� 4���� ���Ҹ� ����. 
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