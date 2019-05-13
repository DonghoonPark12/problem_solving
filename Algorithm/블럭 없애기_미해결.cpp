//#define	_CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//#define min(a,b) ((a)<(b) ? a : b)
//
//// 배열 문제
////int arr[100000][1000000000];
//int arr[100000]; //타원의 갯수
//int arr_next[100000];
//int main(void)
//{
//	int T, test_case;
//	freopen("input.txt", "r", stdin);
//
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int Answer = 0;
//		int cnt=0;
//		/////////////////////////////////////////////////////////////////////////////////////////////////
//		int n; scanf(" %d", &n);
//		for (int i = 0; i < n; i++) {scanf(" %d", arr+i);}
//		
//		while (1) {
//			for (int i = 1; i < n - 1; i++) { // 1 ~ 4 까지만 조사하면 된다. 그다음 번에는 2~3
//				if (arr[i] >= 2 && ( min(arr[i - 1], arr[i + 1]) != 0) ) //arr[i]이 2보다 커야 하면 양쪽이 1보다는 커야 조사 대상에 들어간다. 
//				{
//					if ( (arr[i] > min(arr[i - 1], arr[i + 1])))
//						arr_next[i] = min(arr[i - 1], arr[i + 1]);
//					else 
//						arr_next[i] = arr[i] - 1;
//				}
//				else {
//					cnt++;
//					continue;
//				}
//			}
//
//			for (int i = 0; i < n; i++) { // 1 ~ 4 까지만 조사하면 된다. 그다음 번에는 2~3
//				arr[i] = 0;
//				arr[i] = arr_next[i];
//				arr_next[i] = 0;
//			}
//			Answer++;
//
//
//			if (cnt == n - 2) break; //한번도 
//			else cnt = 0;
//
//		}
//		
//		/////////////////////////////////////////////////////////////////////////////////////////////////
//		printf("Case#%d\n", test_case + 1);
//		printf("%d\n", Answer);
//	}
//
//	return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int h[100002];
//int l[100002];
//int r[100002];
//int n;
//int main() {
//	int c;
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &c);
//	for (int tc = 1; tc <= c; ++tc) {
//		scanf("%d", &n);
//		l[0] = r[n + 1] = 0;
//		for (int i = 1; i <= n; ++i)
//			scanf("%d", h + i);
//		for (int i = 1; i <= n; ++i)
//			l[i] = min(l[i - 1] + 1, h[i]);

//		for (int i = n; i >= 1; --i)
//			r[i] = min(r[i + 1] + 1, h[i]);

//		int maxVal = 0;
//		for (int i = 1; i <= n; ++i)
//			maxVal = max(maxVal, min(l[i], r[i]));
//		cout << "Case #" << tc << endl;
//		cout << maxVal << endl;
//	}
//}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<int> a(n + 2);
		vector<int> d(n + 2);
		vector<int> l(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int worst = 0;
		for (int i = 1; i <= n; i++) {
			worst = min(worst, a[i] - i); //l[i] = min(l[i - 1] + 1, a[i]);
			d[i] = worst + i;
		}
		worst = n + 1;
		for (int i = n; i >= 1; i--) {
			worst = min(worst, a[i] + i); //r[i] = min(r[i + 1] + 1, a[i]);
			//d[i] = min(d[i], worst - i);
			l[i] = worst - i;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			//ans = max(ans, d[i]);
			ans = max(ans, min(l[i], d[i]));
		}
		cout << "case #" << tc << '\n';
		cout << ans << '\n';
	}
	return 0;
}


//#include <stdio.h>
//#include <string.h>
//
//#define MIN(a,b) a < b ? a : b
//
//int n;
//int arr[100010];
//int result = 0;
//
//int main(void)
//{
//	setbuf(stdout, NULL);
//
//	int TC;
//	int test_case;
//	int i;
//	scanf("%d", &TC);
//	for (test_case = 1; test_case <= TC; test_case++) {
//		result = 0;
//		memset(arr, 0, sizeof(arr));
//		scanf("%d", &n);
//		for (i = 1; i <= n; i++)
//			scanf("%d", &arr[i]);
//		for (i = 1; i <= n; i++)
//			arr[i] = MIN(arr[i], arr[i - 1] + 1);
//		for (i = n; i >= 1; i--)
//		{
//			arr[i] = MIN(arr[i + 1] + 1, arr[i]);
//			if (result < arr[i])
//				result = arr[i];
//		}
//		printf("Case #%d\n", test_case);
//		printf("%d\n", result);
//	}
//
//	return 0;
//}