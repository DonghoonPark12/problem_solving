#define	_CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;
int __max(int a, int b, int c, int d) {
	int L = a > b ? a : b;
	int R = c > d ? c : d;
	return L > R ? L : R;
}
int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	//scanf("%d", &T);
	for (test_case = 0; test_case < 10; test_case++)
	{
		int len; cin >> len;
		vector<int> arr(len, 0);
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		int Answer = 0;
		for (int i = 2; i < len - 2; i++) {
			if (arr[i] > arr[i + 1] && arr[i] > arr[i + 2] && arr[i] > arr[i - 1] && arr[i] > arr[i - 2])
				Answer += arr[i] - __max(arr[i - 1], arr[i - 2], arr[i + 1], arr[i + 2]);
		}


		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}

//#define	_CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define _max(a,b) (((a)>(b)) ? (a):(b))
//int main(void)
//{
//	int T, test_case;
//	
//	freopen("input.txt", "r", stdin);
//
//	setbuf(stdout, NULL);
//
//	//scanf("%d", &T);
//	for (test_case = 0; test_case < 10; test_case++)
//	{
//		/////////////////////////////////////////////////////////////////////////////////////////////////
//		int Answer = 0;
//		int min = 1000, temp =0;
//		int n;
//		int a[1000] = { 0 };
//
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &a[i]);
//		}
//
//		for (int i = 2; i < n - 2; i++) //0 ~ 999 라면 0, 1 , 2~997, 998, 999 에서 2 ~ 997만 검사하면 된다. 
//		{
//				/* 앞 둘, 뒤 둘 차이 봐서 음수 아닌 값이 나오면은 min으로 잡고 카운트 한다. 
//				그래서 min을 처음에 크게 잡아줘야 하는 Overfitting이 생겼다.
//				for (int j = -2; j <= 2; j++)
//				{
//					if (j == 0) continue;
//					temp = a[i] - a[i + j]; //앞에 둘, 뒤에 둘 빼서 가장 작은 값을 찾는다. 
//
//					if (temp < min)
//					{
//						min = temp;
//						if (min <= 0)
//							break;
//					}
//				}
//				*/
//				temp = _max(_max(a[i - 2], a[i - 1]), _max(a[i + 1], a[i + 2]));
//				
//				if(a[i] - temp >0){ //조망권 확보된 집이 있다면
//					Answer = Answer + a[i] - temp;
//				}
//					//min = 1000; //Overfitting
//		}
//		printf("#%d ", test_case + 1);
//		printf("%d\n", Answer);
//
//		/////////////////////////////////////////////////////////////////////////////////////////////////
//	}
//
//
//
//	return 0;
//
//}