#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[101];
int main() {
	int num, curinput, ans;
	vector<int> v;
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &num);
		v.clear();
		for (int i = 0; i < num; i++) {
			scanf("%1d", &curinput);
			if (!v.empty() && curinput == v.back()) {
				v.pop_back(); continue;
			}
			v.push_back(curinput);
		}

		cout << "#" << t << " ";
		for (int i = 0; i < v.size(); i++) cout << v[i];
		cout << '\n';
	}
	return 0;
}
