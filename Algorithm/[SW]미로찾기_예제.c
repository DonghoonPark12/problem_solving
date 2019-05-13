#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[16][16] = { 1, };
int arr_V[16][16] = { 0, }; // ���� �Դ� ������ �ִ� �� //�̷θ� �� ���� ������ �湮�� ���̸� ���� �����鼭 1�� ä�� ��.
//int cur[16][16] = { 0, };
//int stack[256] = { 0, };

int dfs(int i, int j)
{
	int temp = 0;

	if (arr[i][j] == 1 || arr_V[i][j] == 1) // ���̰ų�, �ѹ� �湮
		return 0;//��͹� ����
	else if (arr[i][j] == 3)
		return 1;
	else
	{
		arr_V[i][j] = 1; 

		temp += dfs(i - 1, j);//����
		temp += dfs(i + 1, j);//�Ʒ���
		temp += dfs(i, j - 1);//����
		temp += dfs(i, j + 1);//������

		arr_V[i][j] = 0; //arr_V�� 1�� �Ǹ鼭 ���� ��ġ �Դµ� ��,��,��,�� �� �ƴϸ� arr_V�� �ٽ� 0����

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
		/* 2���� �迭�� �޴� �� ���� ��� ���� ��...*/



		
		
		printf("%d\n", dfs(1,1));

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	//printf("Case #%d ", n);
	//printf("%d\n", Answer);

	return 0;

}