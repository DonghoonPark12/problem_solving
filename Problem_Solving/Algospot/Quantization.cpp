#include<iostream>
#include<algorithm>
#include <memory.h>
using namespace std;

int N, S; //데이터 길이, 양자화 구간수
const int MAX = 987654321;
int dataArr[100];
//int partSum[100];
//int partSqSum[100];
int cache[100][10]; //구간에 따른 부분합 계산

int minQuare(int low, int high) {
	int partSum = 0; int size = high - low + 1;
	for (int i = low; i <= high; i++) { partSum += dataArr[i];}

	int mean = (int)(0.5 + (double)partSum/size); //round 값
	
	int res = 0;
	for (int i = low; i <= high; i++) {
			int t = abs(mean - dataArr[i]);
			res += t * t;
			//res += pow(abs(mean - dataArr[i]), 2);
		}
	
	return res;
}

int quantize(int start, int QuanSize) {
	if (start == N) return 0;
	if (QuanSize == 0) return MAX; //?

	int& res = cache[start][QuanSize];
	if (res != -1) return res;

	res = MAX;
	for (int partSize = 1; start + partSize <= N; partSize++) { //start + 를 이해하는게 중요.
		res = min(res,	minQuare(start, start + partSize - 1) + quantize(start + partSize, QuanSize - 1));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		
		
		cin >> N >> S;
		for (int i = 0; i < N; i++) 
			cin >> dataArr[i];

		sort(dataArr, dataArr + N);

		memset(cache, -1, sizeof(cache));

		cout << quantize(0, S) << '\n';
	}
	return 0;
}
