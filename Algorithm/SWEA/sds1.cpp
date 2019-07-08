#include <iostream>
using namespace std;

int arr[10001];
//int inf[10001];
int check[10001];
int n, k; 
int max = 0;
//int cnt;
//int max; //count most appear number
//void how_many_appear() {
//	for (int i = 0; i < n - 1; i++) {
//		if (arr[i] != arr[i + 1]) {
//			if (arr[i + 1] == 0 || arr[i] == 0)
//				continue;
//			else
//				cnt++;
//		}
//	}
//	if (cnt != 0)
//		cnt += 1;//if cnt is not 0 then +1
//}
int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		/*---------------------------------------*/
		// Check whether arr has all index of k. 
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			check[arr[i]] = 1;
		}
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum += check[i];
		}
		bool _all = false;
		if (sum == k)
			_all = true;
		/*---------------------------------------*/

		int max = 0;//what is the max number in arr??
		for (int i = 0; i < n; i++) {
			if (arr[i] > max)
				max = arr[i];
		}

		int diff = k - max;

		if (_all) {//if arr has all number in k
			for (int i = n - 1; i >= 0; i--) {
				if (arr[i] == 0)
					arr[i] = max;
				else if (arr[i] != max && arr[i] != 0)
					max -= 1;
			}			
		}
		else {

		}
		
		/*---------------------------------------*/
		int c = 1; // count the consecutive number.
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == arr[i + 1])
				c++;
			if (arr[i] != arr[i + 1]) {
				c = 1;
			}
			if (c > max) {
				max = c;
			}
		}
		/*---------------------------------------*/

		printf("#%d ", test_case + 1);
		printf("%d\n", max);
	}

	return 0;
}
