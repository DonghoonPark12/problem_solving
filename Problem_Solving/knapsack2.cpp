#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define max(x,y) ((x)>(y)? x : y)
using namespace std;
/*
N���� ������, W���� Capa
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W

�ִ� ��ġ�� ã�ƶ�. 

2��° �ٿ��� ������ �ִ� �ִ� ���԰� �־�����. 
3��° �ٿ��� ��ġ�� �־���.

4��° �ٿ��� ���԰� �־�����. 
*/
int N, W; //���� ������ ���� ����

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
		return 0; //w�� ���� ���� �� �ִ� �ִ� ���� ���� ũ�� �ƿ�.
	}
	KS(i + 1);
	if (w <= W && v > max) //���� ���԰� W ���� �۰ų� ������ 
		max = v;
	
}
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T); //1

	for (int tc = 0; tc < T; tc++) {

		scanf(" %d %d", &N, &W); //3, ���� �� �ִ� �ִ� ����:4

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