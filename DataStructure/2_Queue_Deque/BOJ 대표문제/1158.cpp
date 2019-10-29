#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m; // 7 3

	queue<int> suvivors;
	for (int i = 1; i <= n; i++)
		suvivors.push(i);//1 2 3 4 5 6 7

	cout << "<";

	while (n--)
	{
		for (int i = 0; i < m - 1; i++)
		{
			suvivors.push(suvivors.front()); //앞에껄 빼서 뒤에다 넣는다. 
			suvivors.pop();
		}
		cout << suvivors.front();
		suvivors.pop();

		if(n>0)
		cout << ", ";
	}
	cout << ">";
}