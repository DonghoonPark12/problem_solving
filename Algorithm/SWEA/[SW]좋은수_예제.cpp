#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[5000];//수열 저장
int arr_s[400001];//역할이 뭔지???

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int TC, test_case, T, i, j, num, a;
	int good;
	scanf("%d", &TC);

	for (test_case = 0; test_case < TC; test_case++)
	{
		memset(arr_s, 0, sizeof(arr_s));
		good = 0;
		scanf("%d", &T);
		for (i = 0; i < T; i++)
		{

			scanf("%d", &arr[i]);
			//착한수 인지 체크
			// 첫번째의 경우 무조껀 착한수가 아니다. 때문에 i = 0 일때 찾지 않게 수정
			// i 에서 i - a , a-1>=0 일때까지 빼면서 두개 수의 합이 i - a 인 값을 찾는다.
			for (j = i - 1; j >= 0; j--)
			{
				if (arr_s[arr[i] - arr[j] + 200000] == 1)
				{
					good++;
					break;
				}//if
			}//for
			 //숫자의 합에 대칭 되는 행렬, 메모리 공간에 1 대입
			 // ex arr_s[10 + 200000] = 1이라는 말은 두 수의 합이 10이 되는 두 수가 존재한다는 뜻
			for (j = 0; j <= i; j++)
				arr_s[arr[i] + arr[j] + 200000] = 1;

		}//for		
		printf("Case #%d\n%d\n", test_case + 1, good);
	}//for
	return 0;
}