#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int queue[102][2];
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, m;
		scanf("%d%d", &n, &m);//4 2

		for (int i = 0; i<n; i++)
		{
			scanf("%d", &queue[i][0]);// 1 2 3 4
			queue[i][1] = i;
		}
		int s = 0;

		//   i   queue[i][0]  queue[i][1]
		//   0		1			0		
		//   1		2			1
		//   2		3			2
		//   3		4			3

		//1234 -> 2341 -> 3412 -> 4123 -> 123 -> 231 -> 312 -> 12
		//0123    1230    2301    3012    012    120    201    01
		while(1)
		{
			for (i = 1; i < n; i++)// 3번  // 2번
			{
				if (queue[0][0]<queue[i][0])break; //뒤에  더 큰게 있다면 
			}
			if (i != n) // 뒤에 더 큰게 있다면 
			{
				queue[n][0] = queue[0][0]; //5번째에 넣고
				queue[n][1] = queue[0][1];
			}
			else
			{
				s++; // 1 //2
				n--; // 3 //2
				if (queue[0][1] == m)break; // 3 != 2 //
			}

			for (i = 0; i<n; i++) // 4번 
			{
				queue[i][0] = queue[i + 1][0];
				queue[i][1] = queue[i + 1][1];
			}
		}
		printf("%d\n", s);
	}
}
