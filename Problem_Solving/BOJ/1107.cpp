#include <iostream>
#include <cstring>
using namespace std;

int dic[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main() {
	int N; cin >> N;

	int N_backup = N;

	int M; cin >> M;

	if (N == 100) return 0;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp; dic[tmp] = -1;
	}

	string N_str;
	while (1) {
		N_str.push_back(N % 10);
		N %= 10;
	}
	N_str.reserve();

	int len = N_str.length();

	/*
		dic idx에 값이 살아 있다면 그 값을 similar에 push_back

		그렇지 않다면 idx +1, -1로 이동하면서 존재하면 바로 push_back
	*/
	string similar;
	for (int i = 0; i < len; i++) {
		int idx = dic[N_str[i]] - '0';
		if (dic[idx] != -1) {

		}
		else {

		}
	}
}