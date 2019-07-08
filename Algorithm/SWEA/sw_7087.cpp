#include<iostream>
using namespace std;
int main(void)
{
	freopen("input.txt", "r", stdin);
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int N = 0;
		int alpha[27] = { 0 };

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			char al[30];
			scanf("%s\n", al);
			alpha[al[0] - 'A']++;
		}

		int result = 0;
		for (int i = 0; alpha[i] != 0; i++)
		{
			result++;
		}
		printf("#%d %d\n", test_case + 1, result);
	}

	return 0;
}



//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
///*
//	string sort : https://www.acmicpc.net/blog/view/22
//*/
//string arr[100];
//int main(void)
//{
//	int T, test_case;
//
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int Answer = 0;
//		int n; cin >> n;
//		memset(arr, 0, sizeof(arr));
//		for (int i = 0; i < n; i++) {
//			cin>>arr[i];
//		}
//		sort(arr, arr + n);
//		int step = 0;
//		for (int i = 0; i < n; i++) {
//			if (arr[i][0] == (int('A') + step)){
//				Answer++; // alphabet이 변하였다면 증가시켜 주는 변수. 하지만, 같은 알파벳이 등장하면 증가 시키지 않는다.
//				step++; //alphabet을 증가 시켜 A~Z까지 몇번 등장하는지 확인하기 위한 변수
//			}
//			if(i != 0 && (arr[i][0] == arr[i - 1][0])) {
//				step--;
//			}
//		}
//
//		printf("#%d ", test_case + 1);
//		printf("%d\n", step);
//	}
//
//	return 0;
//
//}