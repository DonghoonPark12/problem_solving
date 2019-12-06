#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//���� �� �����ϴ� �κ� ����
int arr[1001];
int dp[1001];
vector<int> v;
int main() {
	//O(n^2) https://www.youtube.com/watch?v=CE2b_-XfVDk
	// O(n^2)���� dp[i]�� ������ ���� x��°�� '���� �� ������������'
	// O(nlogn)���� dp[i]�� '���̰� x�� �������������� ������ ���� �ּҰ�'
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int _max = 0;
	dp[0] = 1;//ó���� ���̴�  1

	for (int i = 1; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			//if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {//i��° ����(�������̶�� �����ϴ� ����)�� j��° ���Һ��� ũ��, j��° ���ұ����� �κ� ������
			//	dp[i] = dp[j] + 1;					   //i��° ���Ҹ� �߰����ִ� ���̹Ƿ� dp[i]�� dp[j]+1�� �־��ش�. 
			//}
			if (arr[j] < arr[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		if (_max < dp[i]) {
			_max = dp[i];
		}
	}
	/* ----------------------------------------------------------------------------------------------- */
	// 14002. ���� �� �����ϴ� �κ� ���� ��� (my method, I passed but, I don't know this method is right.)
	int ch = _max;
	vector<int> v;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == ch) {
			v.push_back(arr[i]);
			ch--;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	/* ----------------------------------------------------------------------------------------------- */
	return 0;
}

// baekjoon's method
#include <iostream>
using namespace std;
int a[1000];
int d[1000];
int v[1000];
void go(int p) { // Awesome Code. After go to first LIS index & print the number.
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p]);
	cout << a[p] << ' ';
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j; //<----- ��� j�� ���� ������Ʈ �Ǿ����� Ȯ��.
			}
		}
	}
	int ans = d[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i; //LIS�� ������ �ε��� ��ġ
		}
	}
	cout << ans << '\n';
	go(p);
	cout << '\n';
	return 0;
}