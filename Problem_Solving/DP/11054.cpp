#include <iostream>
#include <algorithm>
using namespace std;

//가장 긴 증가하는 부분 수열
int arr[1001];
int dl[1001];
int dr[1001];
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int max;
	max = dl[0] = dr[n-1] = 1;//처음의 길이는  1

	for (int i = 1; i < n; i++) {
		dl[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dl[j] + 1 > dl[i]) {//i번째 원소(마지막이라고 가정하는 원소)가 j번째 원소보다 크고, j번째 원소까지의 부분 수열에
				dl[i] = dl[j] + 1;					   //i번째 원소를 추가해주는 것이므로 dp[i]에 dp[j]+1을 넣어준다. 
			}
		}
	}
	for (int i = n-2; i >= 0; i--) {
		dr[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (arr[i] > arr[j] && dr[j] + 1 > dr[i]) {//i번째 원소(마지막이라고 가정하는 원소)가 j번째 원소보다 크고, j번째 원소까지의 부분 수열에
				dr[i] = dr[j] + 1;					   //i번째 원소를 추가해주는 것이므로 dp[i]에 dp[j]+1을 넣어준다. 
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (max < dr[i] + dl[i]) max = dr[i] + dl[i];
	}
	cout << max-1 << endl;
	
	/* ----------------------------------------------------------------------------------------------- */
	return 0;
}