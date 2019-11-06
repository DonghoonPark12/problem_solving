#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
int arr[41];
int M[41];

//void recur(int idx, int val) {
//	if (idx == n + 1) {
//		ans++;
//		return;
//	}
//	arr[idx] = val;
//		
//	if (idx == 1 && (arr[idx] == arr[idx + 1]))
//		return;
//	else if (idx == n && (arr[idx] == arr[idx - 1]))
//		return;
//	else if ( (idx!=1 && idx != n) && (arr[idx] == arr[idx - 1] || arr[idx] == arr[idx + 1]) )
//		return;
//
//	idx++; val++;
//
//	if (idx != 1) {
//		recur(idx, val - 1);
//	}
//
//	recur(idx, val);
//
//	if (idx != n) {
//		recur(idx, val + 1);
//	}
//	
//}

//int main() {
//	freopen("input.txt", "r", stdin);
//
//	long long ans = 1;
//	int n; cin >> n; //ÁÂ¼®ÀÇ °¹¼ö
//	int m; cin >> m; //°íÁ¤¼®ÀÇ °¹¼ö
//
//	int tmp;
//	for (int i = 0; i < m; i++) {
//		cin >> tmp;
//		M[tmp] = 1;
//	}
//
//	arr[1] = 1;
//	arr[2] = 2;
//	
//	for (int i = 3; i <= n; i++) {
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//
//	for (int i = 0; i < m; i++) {
//		ans *= arr[M[i] - M[i - 1] - 1];
//	}
//	ans *= arr[n - M[m]];
	//for (int i = 3; i <= n+1; i++) {
	//	if (M[i] == 1 || i > n) {
	//		ans *= arr[i - 1];
	//		arr[i + 1] = 1;
	//		arr[i + 2] = 2;
	//		i += 2;
	//	}
	//	else
	//		arr[i] = arr[i - 1] + arr[i - 2];
	//}
	
	
	//int flag;

	//recur(1, 1);

	//¼ø¿­Àº ½Ã°£ ÃÊ°ú
	//do {
	//	flag = 0;
	//	for (int i = 0; i < m; i++)
	//		if (arr[marr[i]-1] != marr[i])
	//			flag = 1;

	//	for (int i = 0; i < n; i++) {
	//		if (i == 0 && !(arr[0] == 1 || arr[0] == 2))
	//			flag = 1;
	//		else if (i == n - 1 && !(arr[n - 1] == n || arr[n - 1] == n - 1))
	//			flag = 1;
	//		else if (!((arr[i] == i + 1) || (arr[i] == i + 2) || (arr[i] == i)))
	//			flag = 1;
	//	}

	//	if (flag)
	//		continue;
	//	ans += 1;
	//} while (next_permutation(arr.begin(), arr.end()));

//	cout << ans << '\n';
//	return 0;
//}
//

#include <cstdio>

void fib(int *arr, int n) {
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
}

void main() {
	freopen("input.txt", "r", stdin);
	
	int n; cin >> n; //ÁÂ¼®ÀÇ °¹¼ö
	int M; cin >> M; //°íÁ¤¼®ÀÇ °¹¼ö
	
	int cur = 0;
	int ans = 1;
	int sit[41] = { 1, 1 };
	
	fib(sit, n);

	int m;
	for (int i = 0; i < M; i++) {
		cin >> m;
		ans *= sit[m - cur - 1];
		cur = m;
	}
	ans *= sit[n - cur];
	cout << ans << '\n';

	return;
}