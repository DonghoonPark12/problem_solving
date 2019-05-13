#include <iostream>
#include <vector>
#include <algorithm>
/*
���� : ������ ���� �����ϴ� ���
�ߺ� ����: ���� ���� �ٽ� ���� �� �ִ�.
����: ������ ��ȯ���� �̴� ��

*/
using namespace std;

int main() {
	vector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i + 1;

	do {
		for (int i = 0; i < 4; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));//����

	cout << '\n';
	vector<int> v2(4);

	// 4���� 1���� ���Ϳ� ����
	for (int i = 0; i<4; i++) {
		v2[i] = 4 - i;
	}

	// prev_permutation�� ���ؼ� ���� ���� ���ϱ�
	do {

		for (int i = 0; i<4; i++) {
			cout << v2[i] << " ";
		}

		cout << '\n';

	} while (prev_permutation(v2.begin(), v2.end()));


	return 0;
}
