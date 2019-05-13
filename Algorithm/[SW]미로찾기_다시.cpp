/* 
백 트래킹 방식은 DFS에서 발전한 형태라고 했다.
백 트래킹 방식은 DFS 처럼 스택을 이용하거나, 재귀를 이용하는 방식이 있다. 
DFS는 스택으로 구현하는게 정석.
*/

#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[16][16] = { 0, };
int arr_V[16][16] = { 0, }; // 지나 왔던 방향을 넣는 값 //미로를 똑 같이 본떠서 방문된 곳이면 빠져 나오면서 1로 채울 것.
int cur[16][16] = { 0, };
int stack[256] = { 0, };

/* 재귀 방식은 일단 스택 오버 플로 
int dfs(int arr[][16]) // 2차원 배열을 어떻게 넘겨 받을 까...
{
	int i, j;
	if(arr_V[i][j] !=1) //두번 밟아 1이 된 곳이 아니라면
	arr_V[i][j] = 2;

	if ((arr[i][j + 1] == 0) && (arr_V[i][j + 1] != 1))//오른쪽 길이 있다면 + 두번 밟아 벽이된 곳이 아니라면.
	{
		//arr_D[i][j + 1] == 1;
		if (arr_V[i][j + 1] == 2) arr_V[i][j + 1] = 1; //두번 밟으면 벽으로 만듬.

		dfs(*(arr+i)[j + 1]);//오른쪽 이동한 뒤 다시 호출
	  //arr_V[i][j + 1] = 2;// 한번은 밟을 수 있다.
	}
	if ((arr[i + 1][j] == 0) && (arr_V[i + 1][j] != 1)) //아래쪽 이동
	{
		if (arr_V[i + 1][j] == 2) arr_V[i + 1][j] = 1;
		dfs[i + 1][j];
	}
	if ((arr[i][j - 1] == 0) && (arr_V[i][j + 1] != 1)) //왼쪽 이동
	{
		if (arr_V[i][j - 1] == 2) arr_V[i][j - 1] = 1;
		dfs[i][j - 1];
	}
	if ((arr[i-1][j] == 0) && (arr_V[i-1][j] != 1)) //위쪽 이동
	{
		if (arr_V[i-1][j] == 2) arr_V[i-1][j] = 1;
		dfs[i-1][j];
	}

	// 다시 복귀 하면 이부분을 타는데 
	// 여기서 1을 채워줘서, 다시 방문하는 일이 없도록 한다. 
}*/

	if ((arr[i][j + 1] == 0) && (arr_V[i][j + 1] != 1))//오른쪽 길이 있다면 + 두번 밟아 벽이된 곳이 아니라면.
	{
		stack[cnt] = 1;
		if (arr_V[i][j + 1] == 2) arr_V[i][j + 1] = 1; //두번 밟으면 벽으로 만듬.
	}
	if ((arr[i + 1][j] == 0) && (arr_V[i + 1][j] != 1)) //아래쪽 이동
	{
		stack[cnt] = 2;
		if (arr_V[i + 1][j] == 2) arr_V[i + 1][j] = 1;
	}
	if ((arr[i][j - 1] == 0) && (arr_V[i][j + 1] != 1)) //왼쪽 이동
	{
		stack[cnt] = 3;
		if (arr_V[i][j - 1] == 2) arr_V[i][j - 1] = 1;
	}
	if ((arr[i - 1][j] == 0) && (arr_V[i - 1][j] != 1)) //위쪽 이동
	{
		stack[cnt] = 4;
		if (arr_V[i - 1][j] == 2) arr_V[i - 1][j] = 1;
	}
	cnt++;

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf("%d", &arr[i][j]);
				scanf("%d", &arr_c[i][j]);
			}
		}

		if (arr[i][j + 1] == 0 && )
			cur[i][j++];
		if (arr[i + 1][j] == 0)
			cur[i++][j];


		if(cur[i][j] == 3)

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	printf("Case #%d ", test_case + 1);
	printf("%d\n", Answer);

	return 0;

}
