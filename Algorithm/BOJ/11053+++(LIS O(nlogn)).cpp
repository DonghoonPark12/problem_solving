#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://onecoke.tistory.com/entry/BOJ-백준-11053-가장-긴-증가하는-부분-수열-LIS
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

//1965번: 상자넣기 https ://www.acmicpc.net/problem/1965
//
//2631번 : 줄세우기 https ://www.acmicpc.net/problem/2631
//
//2352번 : 반도체 설계 https ://www.acmicpc.net/problem/2352

//#include <iostream>
//#include <algorithm>
////https://www.crocus.co.kr/583
//// O(nlogn) 알고리즘에서 실제 LIS 배열 찾는 법 : https://www.crocus.co.kr/680
////https://www.youtube.com/watch?v=S9oUiVYEq7E
//using namespace std;
//
//int _lower_bound(int start, int end, int *arr, int target) {
//	int mid;
//	while (end - start > 0) {
//		mid = (start + end) / 2; //주어진 위치의 중간 위치를 계산
//		if (arr[mid] < target) //찾고자 하는 값보다 작으면 오른쪽으로 한칸 이동한 곳을 시작 구간으로 재 설정
//			start = mid + 1;
//		else
//			end = mid;  //찾고자 하는 값보다 크면 mid 위치를 끝 지점으로 지정
//	}
//	return end + 1; //찾는 구간에 없는 경우 마지막 위치 +1 전달
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
//	dp[i] = arr[i]; //dp 배열에 아무 값이 없다면 조사하는 배열(arr)의 첫번째 값을 넣는다.
//	i++;
//
//	while (i < n) {
//		if (dp[j] < arr[i]) { //dp의 가장 큰 값(가장 오른쪽에 있는 값) 보다 더 큰 값이 들어오면
//			dp[j + 1] = arr[i]; //dp배열에 arr[i]를 추가해 준다.
//			j++;
//		}
//		else {
//			int ans = _lower_bound(0, j, dp, arr[i]); //그 외에는
//			dp[ans - 1] = arr[i];
//		}
//		i++;
//	}
//	cout << j + 1;
//	return 0;
//}
//




