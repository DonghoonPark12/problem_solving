#include <iostream>
#include <vector>

using namespace std;
/*
	골드바흐 파티션
	가설: 4 보다 큰 모든 짝수는 두 홀수소수의 합으로 나타낼 수 있다.
*/
int n;
const int Max = 1000000;
bool arr[Max + 1];

void eratos() {
	for (int i = 2; i <= Max; i++) //2는 소수에 포함!!!
		arr[i] = true;

	for (int i = 2; i * i <= Max; i++) {//i가 제곱을 해도 n보다 작거나 같으면
		if (arr[i]) // 소수이면
			for (int j = i * i; j <= Max; j += i) {
				arr[j] = false; // 배수는 모두 소수가 아니다.
			}
	}
}

int main() {
	eratos();
	int num; cin >> num;
	while (num--) {
		cin >> n;
		int cnt = 0;
		int o1 = 0, o2 = 0; bool flag = false;
		for (o1 = 2; o1 <= n / 2; o1++) { //홀수 부터 시작하니 3부터 시작, 본인(n)까지 갈 필요도 없다. 
			if (arr[o1]) { //0이 아니고 : 소수이며
				o2 = n - o1; // o1 + o2 = n을 만족하는 o2가 있을때,
				if (arr[o2]) { //o2도 소수이면
					cnt++;
				}
			}

		}
		cout << cnt << '\n';
	}
	return 0;
}
