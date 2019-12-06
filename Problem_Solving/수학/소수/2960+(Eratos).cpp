#include <iostream>
using namespace std;

/*
1. 2부터 N까지 모든 수를 써 놓는다
2. 아직 지워지지 않은 수 중에서 가장 작은 소수를 찾는다.
3. 그 수의 배수를 모두 지운다.
*/
int arr[1001];
bool check[1001];

int cnt = 0;
void eratos(int n) {
	for (int i = 2; i <= n; i++) { //처음엔 모두 소수로 본다. check[0], check[1]은 false
		check[i] = true;
	}
	for (int i = 2; i*i <= n; i++) {
		if (check[i] == true) {
			for (int j = i * i; j <= n; j += i) { //i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
				check[j] = false;
			}
		}
	}

	//위에가 헷갈리면 아래와 같이 해도 된다.
	//for (int i = 2; i <= n; i++) {
	//	if (check[i] == true) {
	//		for (int j = i; j <= n; j += i) {  //다만 배수를 위해서 j += i는 중요하다.
	//			check[j] = false;
	//		}
	//	}
	//}
}
int main() {
	int n, k; cin >> n >> k;
	eratos(n);

	return 0;
}

int main() {
	cin >> n;
	eratos(n);

	return 0;
}