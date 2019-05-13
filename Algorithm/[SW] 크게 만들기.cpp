#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
//#include<functional>
#include<string>
#include<vector>
/* 순위 매기기 */
#include <queue>

using namespace std;

//int main()
//{
//	int N = 0, K = 0;
//	int Answer = 0;
//
//	char num[500001];
//
//	scanf("%d %d %s", &N, &K, &num);// 같이 받으면 된다. 
//
//	int s = strlen(num); //str을 입력 받으면 길이는 체크하는 것이 기본!!!!!
//
//	//int *arr = (int*)malloc(sizeof(int)*N); malloc은 졸업하자
//	//int arr[500000] = { 0 };
//	vector<char> v;
//
//	v.push_back(num[0]);// vector는 push_back으로 넣는 것이 기본
//
//	int i = 0;
//
//	//while (num != 0)
//	//{
//	//	//v.push_back(num % 10);
//	//	arr[i++] = num % 10;
//	//	num = num / 10;
//	//}
//
//	////sort(v.begin(), v.end(), greater<int>());
//	////sort(arr,arr+n,greater<int>());
//	//sort(arr, arr + n);
//
//	//for (int i = n; k > 0; k--)
//	//{
//	//	//printf("%d", v.at(i));
//	//	printf("%d", arr[i]);
//	//}
//
//	for (int i = 0; i < v.size(); i++) //vector는 크기도 내장 함수로 해결하면 된다.
//	{
//		printf("%c", v[i]); //vector는 배열 처럼 활용도 가능하다 ♡♡♡
//	}
//	return 0;
//}

//char str[500001];
//
//int main()
//{
//	int N = 0, K = 0;
//
//	scanf("%d %d", &N, &K);
//	scanf(" %s", &str);
//
//	int s = strlen(str);
//
//	vector <char> ans;
//	ans.push_back(str[0]);
//
//	for (int i = 1; i < s; i++)
//	{
//		//들어오는 값이 vector에 저장된 
//		while (K && !ans.empty() && ans.back() < str[i]) { 
//			K--;
//			ans.pop_back();
//		}
//		ans.push_back(str[i]);
//	}
//
//
//	while (K) {
//		K--;
//		ans.pop_back();
//	}
//
//
//	for (int i = 0; i < ans.size(); i++)
//	{
//		printf("%c", ans[i]);
//	}
//
//	return 0;
//}

int n, k;
char str[500001];
deque<char> q;

void push(char x) {
	while (!q.empty() && q.back() < x)
		q.pop_back();
	q.push_back(x);//9
}

int main()
{
	scanf("%d %d %s", &n, &k, str);//4 2 1924
	for (int i = 0; i < k; i++) push(str[i]);// 2번 push
	for (int i = k; i < n; i++)	{// 남은 두번 push ... 왜 이렇게 하는지....
		push(str[i]);
		printf("%c", q.front());
		q.pop_front();
	}
	return 0;
}