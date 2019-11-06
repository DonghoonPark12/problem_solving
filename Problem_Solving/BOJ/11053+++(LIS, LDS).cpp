#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* ------------------------------------------------------------------------------------------------------ */
//int n;
//int arr[1001] = { 1001, };
//int dp[1001];
//
//int lis(const vector<int> &A) {
//	if (A.empty()) return 0;
//	int ret = 0;
//	for (int i = 0; i < A.size(); ++i) {
//		vector<int> B;
//		for (int j = i + 1; j < A.size(); ++j) {
//			if (A[i] < A[j])
//				B.push_back(A[j]);
//		}
//		ret = max(ret, 1 + lis(B));
//	}
//	return ret;
//}
//
//int  cache[100], S[100];
//int lis2(int start) {
//	int &ret = cache[start];
//	if (ret != -1) return ret;
//
//	ret = 1;
//	for (int next = start + 1; next < n; ++next) {
//		if (S[start] < S[next])
//			ret = max(ret, lis2(next) + 1);
//	}
//	return ret;
//}
//
//int lis3(int start) {
//	int &ret = cache[start + 1];
//	if (ret != -1) return ret;
//
//	ret = 1;
//	for (int next = start + 1; next < n; ++next) {
//		if (start == -1 || S[start] < S[next])
//			ret = max(ret, lis3(next) + 1);
//	}
//	return ret;
//}
/* ------------------------------------------------------------------------------------------------------ */

//���� �� �����ϴ� �κ� ����
//int arr[1001];
//int dp[1001];
//vector<int> v;
//int main() {
//	//O(n^2) https://www.youtube.com/watch?v=CE2b_-XfVDk
//	// O(n^2)���� dp[i]�� ������ ���� x��°�� '���� �� ������������'
//	// O(nlogn)���� dp[i]�� '���̰� x�� �������������� ������ ���� �ּҰ�'
//	int n; cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	int max = 0;
//	dp[0] = 1;//ó���� ���̴�  1
//
//	for (int i = 1; i < n; i++) {
//		dp[i] = 1;
//
//		for (int j = 0; j < i; j++) {
//			if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {//i��° ����(�������̶�� �����ϴ� ����)�� j��° ���Һ��� ũ��, j��° ���ұ����� �κ� ������
//				dp[i] = dp[j] + 1;					   //i��° ���Ҹ� �߰����ִ� ���̹Ƿ� dp[i]�� dp[j]+1�� �־��ش�. 
//			}
//		}
//		if (max < dp[i]) {
//			max = dp[i];
//		}
//	}
//	cout << max << endl;
//	
//	/* ----------------------------------------------------------------------------------------------- */
//	// 14002. ���� �� �����ϴ� �κ� ���� ���
//	int ch = max;
//	vector<int> v;
//	for (int i = n-1; i >= 0; i--) {
//		if (dp[i] == ch) {
//			v.push_back(arr[i]);
//			ch--;
//		}
//	}
//	for (int i = v.size()-1; i >= 0; i--) {
//		cout << v[i] << " ";
//	}
//	/* ----------------------------------------------------------------------------------------------- */
//	return 0;
//}

//���� �� �����ϴ� �κ� ����
int arr[1001];
int dp[1001];
int main() {
	//O(n^2) https://www.youtube.com/watch?v=CE2b_-XfVDk
	// O(n^2)���� dp[i]�� ������ ���� x��°�� '���� �� ������������'
	// O(nlogn)���� dp[i]�� '���̰� x�� �������������� ������ ���� �ּҰ�'
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;
	dp[0] = 1;//ó���� ���̴�  1

	int _min = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		//1) ù��° ���
		//_min = arr[i];
		//for (int j = i-1; j >=0; j--) {
		//	if (arr[j] > _min && dp[j]+1 > dp[i]) {//i��° ����(�������̶�� �����ϴ� ����)�� j��° ���Һ��� ũ��, j��° ���ұ����� �κ� ������
		//		dp[i] = dp[j] + 1;					   //i��° ���Ҹ� �߰����ִ� ���̹Ƿ� dp[i]�� dp[j]+1�� �־��ش�. 
		//		_min = arr[i];
		//	}
		//}
		////2) �ι�° ���
		//for (int j = i-1; j >= 0; j--) {
		//	if (arr[j] > arr[i] && dp[j]+1 > dp[i]) {
		//		dp[i] = dp[j] + 1;					 
		//	}
		//}
		//3) ����° ���
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i] && dp[j]+1 > dp[i]) {
				dp[i] = dp[j] + 1;					 
			}
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	cout << max << endl;
	
	/* ----------------------------------------------------------------------------------------------- */
	// 14002. ���� �� �����ϴ� �κ� ���� ���
	//int ch = max;
	//vector<int> v;
	//for (int i = n-1; i >= 0; i--) {
	//	if (dp[i] == ch) {
	//		v.push_back(arr[i]);
	//		ch--;
	//	}
	//}
	//for (int i = v.size()-1; i >= 0; i--) {
	//	cout << v[i] << " ";
	//}
	/* ----------------------------------------------------------------------------------------------- */
	return 0;
}

//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//	}
//	dp[1] = 1; int s = 1; int max_idx = 0;
//	for (int i = 2; i <= n; i++) {
//		if (arr[i] > arr[i - 1] && arr[i] < arr[max_idx]) {
//			dp[i] = ++s;
//			max_idx = i;
//		}
//		else if (arr[i] > arr[i - 1] && arr[i] > arr[max_idx]) {
//			dp[i] = ++max_idx;
//			max_idx = i;
//		}
//		else {
//			s = 1;
//		}
//	}
//	cout << max(dp[max_idx], s);
//	return 0;
//
//}
//

