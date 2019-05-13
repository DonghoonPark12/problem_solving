#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100
#define IS_VISITIED 1
#define NOT_VISITIED 0

int arr[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE]; // ���� �Դ� ������ �ִ� �� ���� �����鼭 0����
char str[MAX_SIZE];

int dfs_BackTracking(int i, int j)
{
	int temp = 0;

	if (arr[i][j] == 1 || visited[i][j] == 1) // ���̰ų�, �ѹ� �湮
		return NOT_VISITIED;//��͹� ����
	else if (arr[i][j] == 3)
		return IS_VISITIED;
	else
	{
		visited[i][j] = IS_VISITIED;

		temp += dfs_BackTracking(i - 1, j);//����
		temp += dfs_BackTracking(i + 1, j);//�Ʒ���
		temp += dfs_BackTracking(i, j - 1);//����
		temp += dfs_BackTracking(i, j + 1);//������

		visited[i][j] = NOT_VISITIED; //visited�� 1�� �Ǹ鼭 ���� ��ġ �Դµ� ��,��,��,�� �� �ƴϸ� visited�� �ٽ� 0����

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
			scanf("%s", str); //string �Է�
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = str[j] - '0';
			}
		}
		//printf("%d\n", dfs_BackTracking(1,1)); ���������� �ι� �湮�ϴ� ��쵵 �ִ���
		//���� 2�� ��µǴ� ��쵵 ���� 
		if (dfs_BackTracking(1, 1))
			Ans = 1;
		else
			Ans = 0;
		printf("#%d %d", test_case + 1, Ans);
	}
	return 0;

}


//
///* ����2 */
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
//			dfs(ny, nx); //���� �ƴ϶��, 
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
