#include<iostream>
using namespace std;

int chess[10][10];
int main()
{
	int num;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> chess[i][j];
		}
	}

	cout << num;
}