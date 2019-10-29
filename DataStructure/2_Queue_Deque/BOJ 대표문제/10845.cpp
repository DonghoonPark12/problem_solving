#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	char input[10];
	queue<int> q;
	scanf("%d", &T);

	while (T--)
	{

		string input;
		cin >> input;
		if (input == "push") //push
		{
			int a;
			scanf("%d", &a);
			q.push(a);
		}
		else if (input == "pop") // pop
		{
			if (!q.empty())
			{
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
		}
		else if (input == "size")  //size
		{
			printf("%d\n", q.size());
		}
		else if (input == "empty") // empty
		{
			if (q.empty())
				printf("1\n");
			else printf("0\n");
		}
		else if (input == "front") //front
		{
			if (!q.empty())
			{
				printf("%d\n", q.front());
			}
			else printf("-1\n");
		}
		else  //back;
		{
			if (input == "back")
			{
				if (!q.empty())
				{
					printf("%d\n", q.back());
				}
				else printf("-1\n");
			}
		}

	}
	return 0;
}
