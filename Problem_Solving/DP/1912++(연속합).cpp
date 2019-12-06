//#include <iostream>
//#include <algorithm>
//using namespace std;
///*
//	������ �� ����. 
//	1. ������ ���� ��� sort�ؼ� ���� ū �� �ϳ��� ������� �� ������.
//	2. ���ӵ� �� �߿��� ���� ū ���� ���ؾ� �Ѵ�. 2 -1 3 �� �־����ٸ� (2, -1 3)��� �����ؼ� 4�� ����ؾ� �Ѵ�. 
//	3. �����ϴ��� ���ϴ��� ������� Ǯ�� ������ 2^100000 �̹Ƿ� ��Ǭ��.
//	4. ���� �Ͱ� (���� �� + ���� �� ��) ���ؼ� �ִ븦 dp[i]�� �ִ´�. 
//	5. ���ÿ� result�� dp[i]�� ���ؼ� �ִ� ���� result�� �ִ´�.
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
//	if (cnt == n) { //��� ������ �ִ� ���
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
		dp[i] = max(dp[i], dp[i] + dp[i - 1]); //���� ������ ���ΰ�? or ���� ���ΰ�?
		result = max(result, dp[i]); //�����Ǻκ�.
	}
	cout << result << "\n";
	return 0;
}
