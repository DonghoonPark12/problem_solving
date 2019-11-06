#include <iostream>
using namespace std;

int DP[1000001] = { 0 };
int n1, n2;

int op2(int num) {
	int n = num;
	int cnt = 0;
	while (n != 1) {
		if (DP[n] != 0) { cnt += DP[n]; break; }

		if (n % 2 == 1) n += 1;
		else if (n % 2 == 0) n /= 2;
		else {}
		cnt++;
	}	
	DP[num] = cnt;

	if (num * 2 <= n2 && num - 1 >= n1) {
		while (num * 2 < n2) {
			DP[num * 2] = DP[num] + 1;
			DP[num * 2 - 1] = DP[2 * num] + 1;
			num *= 2;
		}
	}

	return cnt;
}

//void prev(int num, int cnt) {
//	DP[num] = cnt;
//
//	if (num * 2 <= 1000000 && num - 1 >= n1) {
//		while (num * 2 < n2) {
//			DP[num * 2] = DP[num] + 1;
//			DP[num * 2 - 1] = DP[2 * num] + 1;
//			num *= 2;
//		}
//	}
//}

int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		cin >> n1 >> n2;
		//prev(1, 0);
		//prev(2, 1);
		//prev(3, 3);
		for (int i = n1; i <= n2; i++) {
			if (DP[i] != 0)
				Answer += DP[i];
			else
				Answer += op2(i);
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}



//#include <iostream>
//#include <bits/stdc++.h>
//long long f[1000001];
//
//using namespace std;
//
//long long Answer;
//long long sol(long long num)
//{
//	if (num <= 3)
//	{
//		return f[num];
//	}
//	if (f[num]>0)
//	{
//		return f[num];
//	}
//	if (num % 2 == 0)
//	{
//		f[num] = sol(num >> 1) + 1;
//		return f[num];
//	}
//	else if (num % 2 == 1)
//	{
//		f[num] = sol(num + 1) + 1;
//		return f[num];
//	}
//}
//
//int main(int argc, char** argv)
//{
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	int T, test_case;
//	f[1] = 0;
//	f[2] = 1;
//	f[3] = 3;
//
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//
//		Answer = 0;
//		long long first, second;
//		cin >> first >> second;
//		if (first == second)
//		{
//			Answer = sol(first);
//		}
//		else
//		{
//			for (long long i = first; i <= second; i++)
//			{
//				Answer += sol(i);
//			}
//		}
//
//		cout << "Case #" << test_case + 1<<' ' ;
//		cout << Answer << endl;
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}
