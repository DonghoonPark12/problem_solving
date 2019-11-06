#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
int arr[5000];
int flag;
int cnt;
int sum;
int f(int *arr,int j, int idx)// 1 2 3 5 7 10
{
	if (flag) return 1;

	if (cnt == 3 && sum == arr[idx]) {
		flag = 1;
		return 0;
	}
	else if (cnt == 3 && sum != arr[idx]) {
		cnt--;
		sum -= arr[j];
		return cnt;
	}

	if (j < idx) { //0
		cnt++;
		sum += arr[j];
	}
	else
		return 0;
	//0 ~ idx -1 배열 원소로 만들 수 있는 수
	
	
	f(arr, j, idx);
	f(arr, j + 1, idx);

	
	if (flag) {
		cnt = 0;
		return 1;
	}
	else {
		cnt = 0;
		return 0;
	}
	
}
int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int cnt = 0;

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) { scanf(" %d", &(arr[i])); }

		for (int i = 1; i < n; i++)//arr[1]: 2 ~ arr[5] : 10검사
		{
			Answer += f(arr,0,i);
			//cnt = 0; 
			sum = 0; flag = 0;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}

