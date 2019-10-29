#include <iostream>
#include <vector>
using namespace std;

int gcd(int l, int r) {
	int _end= 1000000;
	int _max= 0;
	int gcd;
	for (int i = 1; i <= _end; i++) {  //1도 최소 공배수가 됨을 잊지 말자
		if (l%i == 0 && r%i == 0 && i > _max) {
			_max = gcd = i;
		}
	}
	return gcd;
}

int gcd2(int l, int r) {
	if (r == 0) return l;
	return gcd2(r, l%r);
}

int gcd3(int l, int r) {
	while (r != 0) {
		int m = l%r;
		l = r;
		r = m;
	}
	return l;
}

int main(void)
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		long long Answer = 0;
		//int n; cin >> n;
		//vector<int> arr(n);
		int tmp;
		//int *arr = new int[100];
		//for (int i = 0; i < n; i++) {
		//	//cin >> tmp;
		//	//arr.push_back(tmp);
		//	cin >> tmp;
		//	arr[i] = tmp;
		//}
		int l, r;
		cin >> l >> r;
		//for (int i = 0; i < n - 1; i++) {
		//	for (int j = i + 1; j < n; j++) {
		//		Answer += gcd2(arr[i], arr[j]);
		//	}
		//}
		Answer = (l * r) / gcd2(l, r);


		//printf("#%d ", test_case + 1);
		printf("%lld\n", Answer);
	}

	return 0;

}