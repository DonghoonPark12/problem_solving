#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://onecoke.tistory.com/entry/BOJ-����-11053-����-��-�����ϴ�-�κ�-����-LIS
#define INF 0x7fffffff

int main() {
	vector<int> v;
	v.push_back(-INF);

	int n; cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > v.back()) {
			if (v.back() == -INF) v.clear();
			v.push_back(x);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	cout << v.size() << endl;
	return 0;
}

//1965��: ���ڳֱ� https ://www.acmicpc.net/problem/1965
//
//2631�� : �ټ���� https ://www.acmicpc.net/problem/2631
//
//2352�� : �ݵ�ü ���� https ://www.acmicpc.net/problem/2352

//#include <iostream>
//#include <algorithm>
////https://www.crocus.co.kr/583
//// O(nlogn) �˰��򿡼� ���� LIS �迭 ã�� �� : https://www.crocus.co.kr/680
////https://www.youtube.com/watch?v=S9oUiVYEq7E
//using namespace std;
//
//int _lower_bound(int start, int end, int *arr, int target) {
//	int mid;
//	while (end - start > 0) {
//		mid = (start + end) / 2; //�־��� ��ġ�� �߰� ��ġ�� ���
//		if (arr[mid] < target) //ã���� �ϴ� ������ ������ ���������� ��ĭ �̵��� ���� ���� �������� �� ����
//			start = mid + 1;
//		else
//			end = mid;  //ã���� �ϴ� ������ ũ�� mid ��ġ�� �� �������� ����
//	}
//	return end + 1; //ã�� ������ ���� ��� ������ ��ġ +1 ����
//}
//
//int main() {
//	int cnt = 0;
//	int dp[1001];
//	int arr[1001];
//
//	int n; cin >> n;
//
//	for (int i = 0; i < n; i++) { cin >> arr[i]; }
//
//	int i, j = 0;
//	dp[i] = arr[i]; //dp �迭�� �ƹ� ���� ���ٸ� �����ϴ� �迭(arr)�� ù��° ���� �ִ´�.
//	i++;
//
//	while (i < n) {
//		if (dp[j] < arr[i]) { //dp�� ���� ū ��(���� �����ʿ� �ִ� ��) ���� �� ū ���� ������
//			dp[j + 1] = arr[i]; //dp�迭�� arr[i]�� �߰��� �ش�.
//			j++;
//		}
//		else {
//			int ans = _lower_bound(0, j, dp, arr[i]); //�� �ܿ���
//			dp[ans - 1] = arr[i];
//		}
//		i++;
//	}
//	cout << j + 1;
//	return 0;
//}
//




