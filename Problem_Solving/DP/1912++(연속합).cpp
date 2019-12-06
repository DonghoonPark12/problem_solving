//#include <iostream>
//#include <algorithm>
//using namespace std;
///*
//	문제를 잘 읽자. 
//	1. 음수만 들어올 경우 sort해서 가장 큰 값 하나만 출력으로 내 보낸다.
//	2. 연속된 합 중에서 가장 큰 합을 구해야 한다. 2 -1 3 이 주어졌다면 (2, -1 3)모두 선택해서 4를 출력해야 한다. 
//	3. 선택하느냐 안하느냐 방식으로 풀면 경우수가 2^100000 이므로 못푼다.
//	4. 현재 것과 (이전 것 + 현재 것 합) 비교해서 최대를 dp[i]에 넣는다. 
//	5. 동시에 result와 dp[i]를 비교해서 최대 값을 result에 넣는다.
//*/
//int arr[100000];
//int main() {
//	int n; cin >> n;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//		if (arr[i] < 0)
//			cnt++;
//	}
//	if (cnt == n) { //모두 음수만 있는 경우
//		sort(arr, arr + n);
//		cout << arr[n - 1];
//		return 0;
//	}
//
//	int _max = 0;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > 0)
//			sum += arr[i];
//		else {
//			//_max = max(_max, sum);
//			//sum = 0;
//		}
//	}
//	cout << _max;
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, result, dp[100000] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) cin >> dp[i];

	result = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i], dp[i] + dp[i - 1]); //새로 시작할 것인가? or 더할 것인가?
		result = max(result, dp[i]); //문제의부분.
	}
	cout << result << "\n";
	return 0;
}
