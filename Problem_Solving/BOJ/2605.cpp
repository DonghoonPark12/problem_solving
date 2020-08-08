#include <iostream>
using namespace std;
int arr[100];

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int n, _in; cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
		cin >> _in;
		for (int j = i; _in > 0; _in--, j--)
		{
			swap(arr[j], arr[j - 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}