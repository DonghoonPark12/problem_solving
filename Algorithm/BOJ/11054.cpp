#include <iostream>
#include <algorithm>
using namespace std;

//���� �� �����ϴ� �κ� ����
int arr[1001];
int dl[1001];
int dr[1001];
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int max;
	max = dl[0] = dr[n-1] = 1;//ó���� ���̴�  1

	for (int i = 1; i < n; i++) {
		dl[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dl[j] + 1 > dl[i]) {//i��° ����(�������̶�� �����ϴ� ����)�� j��° ���Һ��� ũ��, j��° ���ұ����� �κ� ������
				dl[i] = dl[j] + 1;					   //i��° ���Ҹ� �߰����ִ� ���̹Ƿ� dp[i]�� dp[j]+1�� �־��ش�. 
			}
		}
	}
	for (int i = n-2; i >= 0; i--) {
		dr[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (arr[i] > arr[j] && dr[j] + 1 > dr[i]) {//i��° ����(�������̶�� �����ϴ� ����)�� j��° ���Һ��� ũ��, j��° ���ұ����� �κ� ������
				dr[i] = dr[j] + 1;					   //i��° ���Ҹ� �߰����ִ� ���̹Ƿ� dp[i]�� dp[j]+1�� �־��ش�. 
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