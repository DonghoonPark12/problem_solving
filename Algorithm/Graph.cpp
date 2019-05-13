#include <iostream>

#include <vector>
#include <list>

#define MAX 55

using namespace std;

int main() {

	int adj_matrix[MAX][MAX], n;

	cin >> n;

	vector < list < int > > head(n + 1); 

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		cin >> adj_matrix[i][j];

		if (adj_matrix[i][j])
			head[i].push_front(j);
	}

	for (int i = 1; i <= n; i++) {
		cout << i << " : ";

		if (!head[i].empty())
		for (auto x : head[i]) 
			cout << x << " ";

		cout << endl;
	}

	return 0;
}