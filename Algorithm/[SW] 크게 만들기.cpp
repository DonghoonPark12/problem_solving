#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
//#include<functional>
#include<string>
#include<vector>
/* ���� �ű�� */
#include <queue>

using namespace std;

//int main()
//{
//	int N = 0, K = 0;
//	int Answer = 0;
//
//	char num[500001];
//
//	scanf("%d %d %s", &N, &K, &num);// ���� ������ �ȴ�. 
//
//	int s = strlen(num); //str�� �Է� ������ ���̴� üũ�ϴ� ���� �⺻!!!!!
//
//	//int *arr = (int*)malloc(sizeof(int)*N); malloc�� ��������
//	//int arr[500000] = { 0 };
//	vector<char> v;
//
//	v.push_back(num[0]);// vector�� push_back���� �ִ� ���� �⺻
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
//	for (int i = 0; i < v.size(); i++) //vector�� ũ�⵵ ���� �Լ��� �ذ��ϸ� �ȴ�.
//	{
//		printf("%c", v[i]); //vector�� �迭 ó�� Ȱ�뵵 �����ϴ� ������
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
//		//������ ���� vector�� ����� 
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
	for (int i = 0; i < k; i++) push(str[i]);// 2�� push
	for (int i = k; i < n; i++)	{// ���� �ι� push ... �� �̷��� �ϴ���....
		push(str[i]);
		printf("%c", q.front());
		q.pop_front();
	}
	return 0;
}