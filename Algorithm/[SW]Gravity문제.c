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

		//printf("선택하시오: (왼쪽회전 : 1, 오른쪽 회전 : 0)");
		//scanf("%d",&sel);

		/* 조금만 생각해 보면 가장 높은 지점만이 최대 낙차를 가질 수 있다. */
		//////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 1; i <= width - 1; i++)
		{
			drop2[i] = width - i;
			for (int j = i+1; j <= width; j++)
			{
				if (arr[i] <= arr[j]) drop2[i]--; //자기 높이 보다 같거나 높은게 있다면 한칸 덜 떨어 진다. 
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
		for (int i = 1; i <= width - 1; i++) // → i=1  // 9 -1 //맨 오른쪽(회전하면 밑에쪽)블록들은 떨어질 곳이 없으므로 확인할 필요 없다.
		{
			for (int j = 1; j <= arr[i]; j++) //  ↓ j=1 // 8
			{
				//if (j <= arr[1]) //j==1
				//{
				drop[i][j] = width - i; // 8만큼 떨어져야 하나
				//if (j < arr[1]) drop[i][j]--;
				//if (j < arr[2]) drop[i][j]--;
				//...
				//if (j < arr[8]) drop[i][j]--;

				// 일반화
				for (int k = i + 1; k <= width; k++)
				{
					if (j <= arr[k]) // 밑에 블록 들이 있다면(j값이 arr[i+1 ~ width] 보다 같더나 작다면)
						drop[i][j]--; // 그만큼 더 못떨어 진다.
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