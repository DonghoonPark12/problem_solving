#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int heap[100000] = { 0 };

void insert(int a)
{

}

void delete_()
{

}

int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &test_case); //2

	for (int i = 0; i < test_case; i++)
	{
		printf("%d", test_case + 1);

		int n;//¿¬»ê ¼ö
		scanf("%d\n", &n); //3

		int op, value;
		while (n--)
		{
			scanf("%d ", &op);
			if (op == 1)
			{
				scanf("%d\n", &value);
				insert(value);
			}
			else
			{
				delete_();
			}
		}


	}
	return 0;
