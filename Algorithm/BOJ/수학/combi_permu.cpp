#include <iostream>
#include <vector>
#include <algorithm>
/*
���� : ������ ���� �����ϴ� ���(Permutation)
�ߺ� ����: ���� ���� �ٽ� ���� �� �ִ�.
����: ������ ��ȯ���� �̴� ��(Combination)

*/
using namespace std;

typedef struct _info {
	int x, y;
}info;

int m;
vector<int> shop, pick;

void dfs(int pos) {//����
	if (pick.size() == m) {
		for (int i = 0; i < pick.size(); i++) {
			printf("%d ", pick[i]);
		}
		printf("\n");
		return;
	}

	for (int i = pos; i < shop.size(); i++) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {


	//1) next_permutaion
	//vector<int> v(4);
	//for (int i = 0; i < 4; i++)
	//	v[i] = i + 1;

	//do {
	//	for (int i = 0; i < 4; i++) {
	//		cout << v[i] << " ";
	//	}
	//	cout << '\n';
	//} while (next_permutation(v.begin(), v.end()));//����

	//cout << '\n';
	//vector<int> v2(4);

	// 4���� 1���� ���Ϳ� ����
	//for (int i = 0; i<4; i++) {
	//	v2[i] = 4 - i;
	//}

	//2) prev_permutation
	// prev_permutation�� ���ؼ� ���� ���� ���ϱ�
	//do {

	//	for (int i = 0; i<4; i++) {
	//		cout << v2[i] << " ";
	//	}

	//	cout << '\n';

	//} while (prev_permutation(v2.begin(), v2.end()));

	//3)
	//for (int i = 0; i < 3; i++) {
	//	shop.push_back(i + 1);
	//}

	//m = 3;
	//dfs(0);
	int cnt = 0;

	//4) for������ ���� ����

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (j != i) {
				for (int k = 1; k <= 6; k++) {
					if (k != j && k != i) {
						cout << i << " " << j << " " << k << '\n';
						cnt++;
					}
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}
