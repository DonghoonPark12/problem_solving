#define	_CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include <iostream>
using namespace std;
/*
5 2 -> 4*4
6 3 -> 4*4
*/


int main(void)
{
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int Answer = 0;
		int frame, fil;
		scanf("%d %d\n", &frame, &fil);
		int size = frame - fil;

		int arr[15][15] = { 0 };// 5<= frame <=15
		for (int i = 0; i < frame; i++)
		{
			for (int j = 0; j < frame; j++)
			{
				cin >> arr[i][j]; //sca
			}
		}

		//int arr2[15][15] = { 0 }; //4 <= 새로운 필터 한변 크기 <=15
		int max = 0,sum;
		for (int i = 0; i <= frame-fil; i++)//5 2 : 0 1 2 3
		{
			for (int j = 0; j <= frame-fil; j++)//5 2 : 0 1 2 3
			{
				sum = 0;//4면의 합을 더한 수
				for(int x=i;x<i+fil;x++)
					for(int y=j;y<j+fil;y++)
						sum += arr[x][y];

				if (sum > max)
					max = sum;
			}
		}


		/*
		int main()
		{
			int T;
			cin >> T;

			for (int i = 1; i <= T; i++)
			{
				int N, M;
				cin >> N >> M;
				int map[15][15];
				int max = 0;
				for (int x = 0; x<N; x++) for (int y = 0; y<N; y++) cin >> map[x][y];
				for (int x = 0; x <= (N - M); x++) for (int y = 0; y <= (N - M); y++)
				{
					int sum = 0;
					for (int a = x; a<x + M; a++)
						for (int b = y; b<y + M; b++)
							sum += map[a][b];
					if (max<sum) max = sum;
				}
				cout << "#" << i << " " << max << endl;
			}
		}
		*/

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", max);
	}

	return 0;

}