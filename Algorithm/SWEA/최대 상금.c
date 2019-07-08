#include <iostream>
#include <cstring>
using namespace std;

int maxNum = 0;
int swapCnt;
int visited[1000000];

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;

	return;
}

void solve(string str, int n)
{
	if (n == swapCnt) //n == 1일때 
	{
		//maxNum = atoi(str.c_str()) > maxNum ? atoi(str.c_str()) : maxNum;
		if (atoi(str.c_str()) > maxNum)
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
	//freopen("input.txt", "r", stdin);
	//setbuf(stdout, NULL);
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