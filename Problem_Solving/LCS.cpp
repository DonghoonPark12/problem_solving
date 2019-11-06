#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int T;
	freopen("input.txt", "r",stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		string a, b;
		int chk = 0, chk2 = 0;
		int arr1[100], arr2[100];
		int dp[100];
		int n, m;
		cin >> n >> m;

		int tmp;
		for (int i = 0; i<n; i++) {
			scanf(" %c",&tmp);
			a.push_back(tmp);
		}
		for (int i = 0; i<n; i++) {
			scanf(" %c",&tmp);
			b.push_back(tmp);
		}
		if (a.size() > b.size()) {
			chk = b.size(); chk2 = a.size();
		}
		else {
			chk = a.size(); chk2 = b.size();
		}

		//int len1, len2;
		//while (arr1[i++] != NULL) len1++;
		//while (arr2[i++] != NULL) len2++;
		//if (len1>len2) chk = len2;
		//else chk = len1;
		
//		int start = 0; //공통 문자가 있었던 인덱스 이후를 가리켜 j가 긴배열을 처음부터 검사하지 않도록 한다.
		int cnt = 0; //dp에 입력되는 수로서, 공통 부분 수열끼리 길이를 비교하는 비교군 역할을 한다.
		int old = 0;
		int seq = 0;
		for (int i = 0; i<chk; i++) {
			dp[i] = 0;
			for (int j = 0; j<chk2; j++) {
				if (a[i] == b[j] && (i == 0 || j>=dp[old])) { //직전까지의 최대 길이가
					if (j > seq)
						dp[i] = cnt + 1; //해당 인덱스 i에 공통 문자열이 존재하면 1로 할 것인가 혹은 지금까지의 공통 문자로 인해 증가된 수로 할 것인가
					else
						dp[i] = 1;
					//start = j + 1;
					seq = j;
					old = i;
					cnt++;
					break;
				}
			}
		}

/*		int cnt2 = 0;
		for (int i = 0; i < chk2; i++) {
			if (dp[i] != 0)
				cnt2++;
		}
		cout << cnt2 << endl*/;
		}
}