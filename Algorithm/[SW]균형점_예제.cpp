#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
int p[10];
int m[10];
int n; 

double e = 1e-13;

double binarySearch(int i, double left, double right)
{
	double fl = 0, fr = 0;
	double mid = (left + right) / 2;

	if (right - left <= e)
		return mid;

	for (int ii = 0; ii <= i; ii++) { 
		fl += (double)m[ii] / ((mid - p[ii]) * (mid - p[ii]));
	}

	for (int ii = i + 1; ii < n; ii++) { 
		fr += (double)m[ii] / ((mid - p[ii]) * (mid - p[ii]));
	}

	if (fr - fl > e)
		return binarySearch(i, left, mid);
	else if (fl - fr > e)
		return binarySearch(i, mid, right);

	return mid;
}

//double obtain(int i) {
//
//	int ii;
//	double rBefore = 0, r, rL = x[i], rR = x[i + 1];
//	double f1, f2;
//
//	while (1) {
//		r = (rL + rR) / 2;
//		if (rBefore > r && (rBefore - r) < 0.000000000001)
//			break;
//		if (rBefore < r && (r - rBefore) < 0.000000000001)
//			break;
//
//		f1 = f2 = 0;
//		for (ii = 0; ii <= i; ii++) {
//			f1 += m[ii] / ((r - x[ii]) * (r - x[ii]));
//		}
//
//		for (ii = i + 1; ii < N; ii++) {
//			f2 += m[ii] / ((x[ii] - r) * (x[ii] - r));
//		}
//
//		//printf("\nr=%.10f f1=%.10f f2=%.10f ", r, f1, f2);
//
//		if (f1 == f2)
//			break;
//		else if (f1 < f2)
//			rR = r;
//		else if (f1 > f2)
//			rL = r;
//
//		rBefore = r;
//	}
//
//	return r;
//}

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

		scanf(" %d", &n);
		for (int i = 0; i < n; i++)scanf(" %d", &p[i]); //위치
		for (int i = 0; i < n; i++)scanf(" %d", &m[i]); //질량

		printf("#%d ", test_case + 1);
		for (int i = 0; i < n - 1; i++) // n개라면 n-1개의 균형점 존재 
		{
			printf("%.10f ", binarySearch(i, p[i], p[i + 1]));
		}
		printf("\n");

	}

	return 0;
}
