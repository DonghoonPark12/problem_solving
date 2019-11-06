#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define max(x,y) ((x)>(y)? x : y)
using namespace std;
/*
N개의 아이템, W개의 Capa
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W

최대 가치를 찾아라. 

2번째 줄에는 담을수 있는 최대 무게가 주어진다. 
3번째 줄에는 가치가 주어딘다.

4번째 줄에는 무게가 주어진다. 
*/
int N, W; //물건 갯수와 가방 부피

int val[100];
int wt[100];

int T;
int w; int v;
int max = 0;

int KS(int i) {
	w += wt[i];
	v += val[i];
	if (w > W) {
		w -= wt[i];
		v -= val[i];
		return 0; //w가 가방 담을 수 있는 최대 무게 보다 크면 아웃.
	}
	KS(i + 1);
	if (w <= W && v > max) //합한 무게가 W 보다 작거나 같더나 
		max = v;
	
}
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T); //1

	for (int tc = 0; tc < T; tc++) {

		scanf(" %d %d", &N, &W); //3, 담을 수 있는 최대 무게:4

		int v, c;
		for (int i = 0; i < N; i++) {
			scanf(" %d", &v); val[i] = v; //value of n items
		}
		for (int i = 0; i < N; i++) {
			scanf(" %d", &c); wt[i] = c; //weight of n items
		}

		printf("%d", KS(0));
	}
}