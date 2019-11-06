#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_palindrome(char *ptr)
{
	int cnt = 0;
	//char *ptr = arr;
	char c = 0;
	int temp = ptr; //temp에 ptr의 주소를 잠깐 저장해 놓고
	while (*ptr != '\0')
	{
		cnt++;
		ptr++;
	}
	*ptr = temp;
	for (int i = 0; i < cnt / 2; i++)
	{
		if (*(ptr + i) != *(ptr + cnt-1-i))
			return 0;
	}

	return 1;
}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%d", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int l;
		scanf("%d", &l);
		int Answer = 0;
		//int cnt = 0;
		char arr[8][8] = {'\0' };
		char temp[5] = { '\0' };
		for (int i = 0; i < 8; i++)
		{
			//for (int j = 0; j < 8; j++)
				scanf("%s\n", &arr[i]);
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8-l+1; j++)
			{
				for (int k = 0; k < l; k++)
				{
					temp[j + k] = arr[i][j + k];
				}
				//temp[j] = arr[i][j];
				//temp[j+1] = arr[i][j+1];
				//temp[j+2] = arr[i][j+2];
				//temp[j+3] = arr[i][j+3];

				if (is_palindrome(temp))
					Answer++;
			}
		}

		for (int i = 0; i <  l + 1; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < l; k++)
				{
					temp[j + k] = arr[i+k][j];
				}
				//temp[j] = arr[i][j];
				//temp[j + 1] = arr[i+1][j];
				//temp[j + 2] = arr[i+2][j];
				//stemp[j + 3] = arr[i+3][j];

				if (is_palindrome(temp))
					Answer++;
			}
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	printf("Case #%d ", test_case + 1);
	printf("%d\n", Answer);

	return 0;

}