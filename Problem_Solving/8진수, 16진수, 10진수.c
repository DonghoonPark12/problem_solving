#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int recursive8(int value)
{
	if (value == 0)
		return 1;
	else
	{
		return 8 * recursive8(value - 1);
	}
}
int recursive16(int value)
{
	if (value == 0)
		return 1;
	else
	{
		return 16 * recursive16(value - 1);
	}
}
int change(char temp)
{
	int a;
		if (temp == 'f') a= 15;
		else if (temp == 'e') a= 14;
		else if (temp == 'd') a= 13;
		else if (temp == 'c') a= 12;
		else if (temp == 'b') a= 11;
		else a= 10;

		return a;
}
int main(void)
{
	int T, test_case;
//	int Answer;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
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
		int Answer = 0;
		int n;
		char str[100];
		char *ptr;
		int cnt = 0;
		int temp = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		scanf("%s",str); //표준입력(stdin)에서 문자열을 가져온다.
		ptr = str;

		if (str[0] == '0' && str[1] == '1')
		{
			while (*ptr != '\0')
			{
				cnt++;
				ptr++;
			}
			for (int i = 0; i < cnt-2; i++)
			{
				ptr--;
				Answer = Answer+ ( ((int)(*ptr)-48) * recursive8(i) );
			}
		}
		else if (str[0] == '0' && str[1] == 'x')
		{
			while (*ptr != '\0')
			{
				cnt++;
				ptr++;
			}
			for (int i = 0; i < cnt - 2; i++)
			{
				ptr--;
				if((*ptr-48)<10)
					Answer += ((int)(*ptr-48) * recursive16(i) );
				else
				{
					char temp = *ptr;
					Answer += (change(temp) * recursive16(i));
				}
			}
		}
		else
		{
			Answer = atoi(str);
		}
		*/
		scanf("%i", &n);
		Answer = n;


		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}