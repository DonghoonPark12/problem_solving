#include <iostream>
using namespace std;
int desti;
int jump;
int cnt;
int flag = 0;
int DP[10001] = { 0 };

int recur(int i, int desti) {
	if (flag == 1) return 0;
	if (i > desti) { jump = 0; cnt--; return 0; }
	if (i == desti) {
		//DP[i] = cnt;
		flag = 1;
		return 0;
	}

	jump++; cnt++;

	if (DP[i + jump] == 0)
		DP[i + jump] = cnt;
	else
		if (cnt < DP[i + jump])
			DP[i + jump] = cnt;
		//DP[i + jump] = cnt < DP[i + jump] ? cnt : DP[i + jump];

	recur(i + jump, desti);
	recur(i, desti);
	return 0;
}
int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		int x, y; cin >> x >> y;
		int max = 0;
		for (int des = x; des <= y; des++) {
			flag = 0; jump = 0; cnt = 0; recur(0, des);
			if (DP[des] > max)
				max = DP[des];
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", max);
	}

	return 0;

}