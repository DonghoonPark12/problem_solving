#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int> person;
//vector<int> pick;
//
//void dfs(int s) {
//	if (pick.size() == 7) {
//		int sum = 0;
//		for (int i = 0; i < 7; i++) {
//			sum += pick[i];
//		}
//		if (sum == 100) {
//			sort(pick.begin(), pick.end());
//			for (int i = 0; i < 7; i++) {
//				cout<<pick[i]<<'\n';
//			}
//		}
//		return;
//	}
//
//	for (int i = s;  i < person.size(); i++) {
//		pick.push_back(person[i]);
//		dfs(i+1);
//		pick.pop_back();
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int tmp;
//	for (int i = 0; i < 9; i++) {
//		cin >> tmp;
//		person.push_back(tmp);
//	}
//	dfs(0);
//	return 0;
//}

//2) 비트 마스크로 푸는 방법
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a[10];
//
//int main() {
//	for (int i = 0; i < 9; i++) scanf("%d", &a[i]);
//
//	std::sort(a, a + 9);
//
//	for (int i = 0; i < (1 << 9); i++) {
//		cout << i << '\n';
//		int cnt = 0, sum = 0;
//
//		for (int j = 0; j < 9; j++) 
//			if ((1 << j) & i)
//			cnt++, sum += a[j];
//
//		if (cnt != 7 || sum != 100) continue;
//
//		for (int j = 0; j < 9; j++) 
//			if ((1 << j) & i)
//			printf("%d\n", a[j]);
//
//	}
//
//	return 0;
//}

//3) for문으로 푸는 방법
int per[9];
int sum;
const int n = 9;
void solve() {
	//sort(per, per + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			
			if (sum - per[i] - per[j] == 100) {
				for (int k = 0; k < n; k++) {
					if (k != i && k != j) {
						printf("%d\n", per[k]);
					}
				}
				return;
			}

		}
	}
}
int main() {
	for (int i = 0; i < n; i++) {
		scanf("%d", &per[i]);
		sum += per[i];
	}
	solve();
}