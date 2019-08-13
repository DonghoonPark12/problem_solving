#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<int> choose;
vector<int> pick;

int n, m;

void dfs(int pos, vector<bool> &visited) {
	if (pick.size() == n) {

		return;
	}
	for (int i = 0; i<num.size(); i++) {
		if (!visited[num[i]]) {
			pick.push_back(num[i]);
			visited[num[i]] = true;

			dfs(i + 1, visited);

			pick.pop_back();
			visited[num[i]] = false;
		}
	}
	return;
}

int arr[10000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	choose.resize(n);

	for (int i = 0; i<n; i++) {
		cin>>choose[i];
		num.push_back(i + 1);
	}
	vector<bool> visited(n+1, false);
	dfs(0, visited);

	return 0;
}