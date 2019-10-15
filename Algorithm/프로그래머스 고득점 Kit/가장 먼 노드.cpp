#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adjl[20001];
int main() {
	cin >> n;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		adjl[l].push_back(r);
		adjl[r].push_back(l);
	}

}