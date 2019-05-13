/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int maxNum = 0;
int swapCnt;
int visited[1000000];

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;

	return ;
}

void solve(string str, int n)
{
	if (n == swapCnt) //n == 1일때 
	{
		//maxNum = atoi(str.c_str()) > maxNum ? atoi(str.c_str()) : maxNum;
		if( atoi(str.c_str()) > maxNum )
			maxNum = atoi(str.c_str());
		return;
	}

	if (visited[atoi(str.c_str())] == true)//231일 경우
		return;

	visited[atoi(str.c_str())] = true;

	for (int i = 0; i < strlen(str.c_str()); i++)//0
	{
		for (int j = i + 1; j < strlen(str.c_str()); j++)//1
		{
			swap(str[i], str[j]);//i, j 다 바꿔 보면서 
			solve(str, n + 1);
			swap(str[i], str[j]);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int tc;
	cin >> tc;

	for (int p = 1; p <= tc; p++)
	{

		string num;
		cin >> num >> swapCnt;

		maxNum = 0;
		solve(num, 0);

		cout << "#" << p << " " << maxNum << endl;

	}

	return 0;
}

//int main(void)
//{
//	int T, test_case;
//	int Answer=0;
//	/*
//	The freopen function below opens input.txt file in read only mode, and afterward,
//	the program will read from input.txt file instead of standard(keyboard) input.
//	To test your program, you may save input data in input.txt file,
//	and use freopen function to read from the file when using scanf function.
//	You may remove the comment symbols(//) in the below statement and use it.
//	But before submission, you must remove the freopen function or rewrite comment symbols(//).
//	*/
//	freopen("input.txt", "r", stdin);
//
//	/*
//	If you remove the statement below, your program's output may not be rocorded
//	when your program is terminated after the time limit.
//	For safety, please use setbuf(stdout, NULL); statement.
//	*/
//	setbuf(stdout, NULL);
//
//	scanf("%d\n", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int c;
//		int sw, M, m;
//		/////////////////////////////////////////////////////////////////////////////////////////////
//		int num[7] = { 0 }; //최대 자리수는 6자리수 이므로 
//
//		int i = 0;
//		while ((c = getchar()) != ' ')
//		{
//			//scanf("%1d", &num[i]);
//			num[i] = c-48; //0 ~ 9까지의 정수가 들어올 것.
//			i++;
//		}
//		scanf("%d\n",&sw);
//
//		//가장 큰수를 앞에 배치 
//		int j = 0;
//		while (sw--)
//		{
//			swap(num[i - 1-(j++)], num[(j++)]);
//		}
//		/* 가장 큰 수의 index를 찾는다. */
//
//		/////////////////////////////////////////////////////////////////////////////////////////////
//
//		// Print the answer to standard output(screen).
//
//		printf("Case #%d\n", test_case + 1);
//		printf("%d\n", Answer);
//
//	}
//
//	return 0;//Your program should return 0 on normal termination.
//}