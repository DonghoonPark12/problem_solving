#include <iostream>
#include <cmath>
using namespace std;
long long l, r;
int n;
typedef struct _dot {
	long long x, y;
}dot;
dot arr[100001] = { 0 };

long long _pow(long long n, long long e) {
	long long ans = 1;
	for (int i = 0; i < e; i++) {
		ans *= n;
	}
	return ans;
}
long long max_square(int _x, int _y) {
	long long  _min = 4 * _pow(10, 12);
	long long range;
	int idx;
	for (int i = 0; i < n; i++) {
		range = _pow( (arr[i].x - _x), 2) + _pow( (arr[i].y - _y), 2);
		if (range < _min) {
			_min = range;
			idx = i;
		}
	}
	long long len = abs(arr[idx].x - _x) > abs(arr[idx].y - _y) ? abs(arr[idx].x - _x) : abs(arr[idx].y - _y);
	return 2 * len;
}

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	//scanf("%d\n", &T);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		long long Answer = 0;
		cin >> l >> r;
		cin >> n;
		//scanf("%lld %lld\n", &l, &r);
		//scanf("%d\n", &n);
		for (int i = 0; i < n; i++) {
			//cin >> arr[i].x >> arr[i].y;
			scanf("%lld %lld", &(arr[i].x), &(arr[i].y));
		}

		long long len;
		for (long long i = l; i <= r; i++) {
			len = max_square(i,0);
			if (Answer < len)
				Answer = len;
		}

		printf("Case #%d\n", test_case + 1);
		printf("%lld\n", Answer);
	}

	return 0;

}