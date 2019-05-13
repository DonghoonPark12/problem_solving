#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define abs(m) ((m > 0) ? m: -m)

/*
*	 0	1	2	3	4	5	6	7	8	9	
* 0  0  0	0	0	0	0	0	0	0	0	0
* 1	 1	1	1	1	1	1	1	1	1	1	0	1 : 1�� �ڸ��� �� �� �ִ� ���
* 2	 1	1	2	2	2	2	2	2	2	1	0	1 : 2�� �ڸ��� �� �� �ִ� ���
* 3	 1	1	3	4	4	4	4	4	4	2	0
* ..
*100 0 
*/

/*
*
* 0�� �տ� ���� ���ִ� ���� �´�.
* ��ȭ���� ���ø� �� �־�� �Ѵ�. 
* �迭�� ���� �� ����� ���� �ʿ䰡 ����. 
*/
int dp[102][11] = { 0 };
const int mod = 1e9; 
int f(int num)
{
	int Ans = 0;

	for (int j = 1; j <= 9; ++j)
	{
		dp[1][j] = 1;
	}

	for (int i = 2; i <= num; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			//if (j == 0)
				//dp[i][j] = dp[i - 1][j + 1];
			//else if (j == 9)
				//dp[i][j] = dp[i - 1][j - 1];
			//else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}

	for (int j = 0; j <= 9; j++)
	{
		Ans += dp[num][j] % mod;
	}

	return Ans;
}


int main(void)
{
	int N, Answer = 0;
	//setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);

	/////////////////////////////////////////////////////////////////////////////////////////////////

	scanf("%d", &N);//110

	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%d\n", f(N));
	return 0;

}

