#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[16][16] = { 1, };
int arr_V[16][16] = { 0, }; // 지나 왔던 방향을 넣는 값 //미로를 똑 같이 본떠서 방문된 곳이면 빠져 나오면서 1로 채울 것.
//int cur[16][16] = { 0, };
//int stack[256] = { 0, };

int dfs(int i, int j)
{
	int temp = 0;

	if (arr[i][j] == 1 || arr_V[i][j] == 1) // 벽이거나, 한번 방문
		return 0;//재귀문 종료
	else if (arr[i][j] == 3)
		return 1;
	else
	{
		arr_V[i][j] = 1; 

		temp += dfs(i - 1, j);//위쪽
		temp += dfs(i + 1, j);//아래쪽
		temp += dfs(i, j - 1);//왼쪽
		temp += dfs(i, j + 1);//오른쪽

		arr_V[i][j] = 0; //arr_V가 1이 되면서 현재 위치 왔는데 위,아,왼,오 도 아니면 arr_V를 다시 0으로

		return temp;
	}
}


int main(void)
{
	int T, test_case;
	//int Answer = 0;
	int n;
	char str[16];
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d\n", &n);
		for (int i = 0; i < 16; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = str[j] - '0';
			}
		}
		/* 2차원 배열을 받는 더 좋은 방법 없을 까...*/



		
		
		printf("%d\n", dfs(1,1));

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	//printf("Case #%d ", n);
	//printf("%d\n", Answer);

	return 0;

}