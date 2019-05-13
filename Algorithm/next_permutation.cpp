#include <iostream>
#include <vector>
#include <algorithm>
/*
순열 : 순서를 정해 나열하는 경우
중복 순열: 같은 것을 다시 뽑을 수 있다.
조합: 순서에 상환없이 뽑는 것

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
	} while (next_permutation(v.begin(), v.end()));//순열

	cout << '\n';
	vector<int> v2(4);

	// 4부터 1까지 벡터에 저장
	for (int i = 0; i<4; i++) {
		v2[i] = 4 - i;
	}

	// prev_permutation을 통해서 이전 순열 구하기
	do {

		for (int i = 0; i<4; i++) {
			cout << v2[i] << " ";
		}

		cout << '\n';

	} while (prev_permutation(v2.begin(), v2.end()));


	return 0;
}
