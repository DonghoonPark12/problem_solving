#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
practice function input 2D array

*/
//#define S(n)	( ((double)(n)) * ((n)+1)/2)
#define S(n) ( ((double)n) * (n+1)/2)


//int f(int **arr, char dir[], int m) //arr, direction
//{
//	int i = 0, j = 0, k = 0;
//	int sum = arr[i][j];
//	while (m--) {
//		switch (dir[k++]) {
//		case 'D':
//			sum += arr[++i][j];
//			break;
//		case 'R':
//			sum += arr[i][++j];
//			break;
//		case 'U':
//			sum += arr[--i][j];
//			break;
//		case 'L':
//			sum += arr[i][--j];
//			break;
//		}
//	}
//	return sum;
//}
int main() {
	// your code goes here
	int tc = 0;
	int n, m;//size, move
	//char dir[300001] = { 0 };

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &tc);

	int t = 0;
	while (tc--)
	{
		double Answer = 1;
		scanf(" %d %d\n", &n, &m);
		int i = 0, j = 0;

		/* �̱� ���� */
		//int arr[][1000000] = { 0 }; //���� ���ϴ°� �����̶�� �迭 ������ �ʿ�� ����. 
		//int **arr = new int *[1000000]; //�� 1000000(�ִ�)

		//for (int i = 0; i <n; i++)
		//	arr[i] = new int[n]; //��

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		if (i + j < n) {
		//			//arr[i][j] = S(i + j + 1) - ( ((i + j) % 2) ? i : j);
		//			Answer += S(i + j + 1) - (((i + j) % 2) ? i : j);
		//		}
		//		else {
		//			//arr[i][j] = n*n - S(2*n - j - i - 2) - n + 1 + (((i + j) % 2) ? i : j);
		//			Answer += n*n - S(2 * n - j - i - 2) - n + 1 + (((i + j) % 2) ? i : j);
		//		}
		//	}
		//}

		char dir;//����
		for (int mm = 0; mm < m; mm++)
		{
			scanf("%c", &dir);
			switch (dir) {
			case 'D':
				i++; break;
			case 'R':
				j++; break;
			case 'U':
				i--; break;
			case 'L':
				j--; break;
			}

			//printf("%d", S(2));//�� 3�̰�
		  //  printf("%d", S(i + j + 1)); // �� �� 2�ϱ�...


			if (i + j < n) {
				//arr[i][j] = S(i + j + 1) - ( ((i + j) % 2) ? i : j);
				//if ((i + j) % 2) //Ȧ��
				//	Answer += S(i + j + 1) - j;
				//else
				//	
				//	Answer += S(i + j + 1) - i;
				Answer += S(i + j + 1) -  ( ((i + j) % 2 )  ? j : i)  ;
			}
			else {
				//if ((i + j) % 2)
				//	Answer += (double)n*n - S(2 * n - j - i - 2) - n + 1 + i;
				//else
				//	Answer += (double)n*n - S(2 * n - j - i - 2) - n + 1 + j;
				Answer += (double)n*n - S(2 * n - j - i - 2) - n + 1 + ( ((i + j) % 2) ? i : j);
				//arr[i][j] = n*n - S(2*n - j - i - 2) - n + 1 + (((i + j) % 2) ? i : j);
				
			}
		}

			printf("Case #%d\n%.0f\n", ++t, Answer);
			//printf("Case #%d\n%d\n", ++t, f(arr, dir, m));
	}
	return 0;
}

/* ���� */
// 1. 2���� �迭 �ʿ� ���� Ǯ �� ������ �׷��� �ϱ�.
// 2. ���ͷ� 2���� �迭 �ٷ�� �� ������ �ϱ�.