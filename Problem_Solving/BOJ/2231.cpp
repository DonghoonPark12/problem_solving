#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<int> pick;

int ans;
int sum;

void dfs(int goal) {
	sum = 0;
	for (int i = 0; i < pick.size(); i++)
		sum += pick[i];
	if (sum > goal) return;
	if (sum == goal) {
		ans++;
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		pick.push_back(num[i]);
		dfs(goal);
		pick.pop_back();
	}
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= 3; i++) 
		num.push_back(i);
	while (t--) {
		int n; cin >> n;
		ans = 0;
		dfs(n);
		cout << ans << '\n';
	}
	return 0;
}