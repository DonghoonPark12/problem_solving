#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		char str[30] = { 0 };
		char str2[30] = { 0 };
		scanf("%[^\n]\n", str);
		int i, j;
		int N = 0;
		char *ptr = str;
		char *top = str;
		
		for(i=0;i<30;i++)
		{
			ptr++; N++;
				if (*ptr == *top) //if (Str[0] == Str[i]) 
				{
					for (j = 0; j < N; j++) //strncpy, strncmp
					{
						if (*ptr != *top)
						{
							top = str; //원래 자리로
							break;
						}
						else
						{
							top++; ptr++; N++;
						}
					}
				}
				if (j == N ) {
					Answer = N;
					break;
				}
		}

		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	return 0;

}