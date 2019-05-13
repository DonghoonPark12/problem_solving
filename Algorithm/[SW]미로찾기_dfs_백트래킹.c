#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100
#define IS_VISITIED 1
#define NOT_VISITIED 0

int arr[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE]; // 지나 왔던 방향을 넣는 값 빠져 나오면서 0으로
char str[MAX_SIZE];

int dfs_BackTracking(int i, int j)
{
	int temp = 0;

	if (arr[i][j] == 1 || visited[i][j] == 1) // 벽이거나, 한번 방문
		return NOT_VISITIED;//재귀문 종료
	else if (arr[i][j] == 3)
		return IS_VISITIED;
	else
	{
		visited[i][j] = IS_VISITIED;

		temp += dfs_BackTracking(i - 1, j);//위쪽
		temp += dfs_BackTracking(i + 1, j);//아래쪽
		temp += dfs_BackTracking(i, j - 1);//왼쪽
		temp += dfs_BackTracking(i, j + 1);//오른쪽

		visited[i][j] = NOT_VISITIED; //visited가 1이 되면서 현재 위치 왔는데 위,아,왼,오 도 아니면 visited를 다시 0으로

		return temp;
	}
}

int main(void)
{
	int T, test_case;
	int n;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	//scanf("%d\n", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		int Ans = 0;
		for (int i = 0; i<MAX_SIZE; i++) {
			for (int j = 0; j<MAX_SIZE; j++) {
				arr[i][j] = 1; //(!!)
				visited[i][j] = NOT_VISITIED;
			}
		}
		scanf("%d\n", &n);

		for (int i = 0; i < 16; i++)
		{
			scanf("%s", str); //string 입력
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = str[j] - '0';
			}
		}
		//printf("%d\n", dfs_BackTracking(1,1)); 도착지점을 두번 방문하는 경우도 있더라
		//따라서 2가 출력되는 경우도 있음 
		if (dfs_BackTracking(1, 1))
			Ans = 1;
		else
			Ans = 0;
		printf("#%d %d", test_case + 1, Ans);
	}
	return 0;

}


//
///* 예제2 */
//#define	_CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//
//int a[16][16];
//int ans;
//int dyx[4][2] = { { 0,-1 },{ 0,1 } ,{ -1,0 },{ 1,0 } };
//
//void dfs(int y, int x) {
//	if (a[y][x] == 3) {
//		ans = 1;
//		return;
//	}
//	a[y][x] = 1;
//	for (int i = 0; i<4; i++) {
//		int ny = y + dyx[i][0], nx = x + dyx[i][1];
//		if (a[ny][nx] != 1)
//			dfs(ny, nx); //벽이 아니라면, 
//	}
//
//}
//
//int main(int t) {
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	while (t<10) {
//		scanf("%d", &t);
//		for (int i = 0; i<16; i++)
//			for (int j = 0; j<16; j++)
//				scanf("%1d", &a[i][j]);
//		ans = 0;
//		dfs(1, 1);
//		printf("#%d %d\n", t, ans);
//	}
//}
