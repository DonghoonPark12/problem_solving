#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <csting>
#include <iostream>
#include <string>
using namespace std;

int is_palindrome(char arr[])
{
	int cnt = 0, Answer = 0;
	//char *ptr = arr;

	//string arr;ÀÏ °æ¿ì
	//cnt = arr.length(); 

	cnt = strlen(arr); //#include <string.h>
	/*
	while (*(ptr++) != '\0')
	{
		cnt++;
	}
	*/
	//ptr = arr;
	for (int i = 0; i < cnt / 2; i++)
	{
		if (arr[i] == arr[cnt-1 - i])
			Answer = 1;
		else
		{
			Answer = 0;
			break;
		}

	}
	return Answer;
}
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
		char arr[101] = { 0 };
		scanf("%s", arr);
		

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", is_palindrome(arr));
	}

	return 0;

}
/*
int main()
{
	string str;
	cin >> str;
	bool Answer = true;

	int curLength = str.length() / 2;
	int i = 0;

	while (curLength > 0)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			Answer = 0;
			break;
		}
		curLength--;
	}
}
*/


