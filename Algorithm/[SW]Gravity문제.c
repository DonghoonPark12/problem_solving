#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Answer;

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		int width, height;
		int drop[100][100] = { 0 };
		int drop2[100] = { 0 };
		int arr[100] = { 0 };
		int max_drop = 0;
	  //int sel = 0;

		scanf("%d", &width); scanf("%d", &height); //9 8

		for (int i = 1; i <= width; i++)
		{
			scanf("%d", &arr[i]); // 0 7 4 2 0 0 6 0 7 0 
		}

		//printf("�����Ͻÿ�: (����ȸ�� : 1, ������ ȸ�� : 0)");
		//scanf("%d",&sel);

		/* ���ݸ� ������ ���� ���� ���� �������� �ִ� ������ ���� �� �ִ�. */
		//////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 1; i <= width - 1; i++)
		{
			drop2[i] = width - i;
			for (int j = i+1; j <= width; j++)
			{
				if (arr[i] <= arr[j]) drop2[i]--; //�ڱ� ���� ���� ���ų� ������ �ִٸ� ��ĭ �� ���� ����. 
			}
		}
		for (int i = 1; i <= width ; i++)
		{
			if (drop2[i] > max_drop)
				max_drop = drop2[i];
		}
		
		///////////////////////////////////////////////////////////////////////////////////////////////

		/* O(n^2) */
		//////////////////////////////////////////////////////////////////////////////////////////////
		/*
		for (int i = 1; i <= width - 1; i++) // �� i=1  // 9 -1 //�� ������(ȸ���ϸ� �ؿ���)��ϵ��� ������ ���� �����Ƿ� Ȯ���� �ʿ� ����.
		{
			for (int j = 1; j <= arr[i]; j++) //  �� j=1 // 8
			{
				//if (j <= arr[1]) //j==1
				//{
				drop[i][j] = width - i; // 8��ŭ �������� �ϳ�
				//if (j < arr[1]) drop[i][j]--;
				//if (j < arr[2]) drop[i][j]--;
				//...
				//if (j < arr[8]) drop[i][j]--;

				// �Ϲ�ȭ
				for (int k = i + 1; k <= width; k++)
				{
					if (j <= arr[k]) // �ؿ� ��� ���� �ִٸ�(j���� arr[i+1 ~ width] ���� ������ �۴ٸ�)
						drop[i][j]--; // �׸�ŭ �� ������ ����.
				}
			}
		}

		for (int i = 1; i <= width; i++) 
		{
			for (int j = 1; j <= height; j++) 
			{
				if (drop[i][j] > max_drop)
					max_drop = drop[i][j];
			}
		}
		*/
		////////////////////////////////////////////////////////////////////////////////////////////


		printf("Case #%d ", test_case + 1);
		printf("%d\n", max_drop);

	}
    	/////////////////////////////////////////////////////////////////////////////////////////////
		// Print the answer to standard output(screen).
		return 0;//Your program should return 0 on normal termination.
}