#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
int p[10]; 
int m[10];
int n; // ex) 4개 라면 

double e = 1e-13;

double binarySearch(int i, double left, double right)//0 1 2 
{
	double fl=0, fr=0;
	double mid = (left + right) / 2;
	//double r = p[i];

	//do
	//{
	//	fl = 0, fr = 0;
	//	for (int ii = 0; ii <= i; ii++) { //0
	//		fl += (double)m[ii] / ((r - p[ii]) * (r - p[ii]));
	//	}

	//	for (int ii = i+1; ii < n; ii++) { //1
	//		fr += (double)m[ii] / ((r - p[ii]) * (r - p[ii]));
	//	}
	//	r += 0.0000001;
	//} while (fl != fr);

	if (right - left <= e)
		return mid;

	for (int ii = 0; ii <= i; ii++) { //0
		fl += (double)m[ii] / ((mid - p[ii]) * (mid - p[ii]));
	}

	for (int ii = i+1; ii < n; ii++) { //1
		fr += (double)m[ii] / ((mid - p[ii]) * (mid - p[ii]));
	}

	if (fr - fl > e)
		return binarySearch(i, left, mid);
	else if (fl - fr > e)
		return binarySearch(i, mid, right);

	return mid;
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

		scanf(" %d", &n);
		for (int i = 0; i < n; i++)scanf(" %d", &p[i]); //위치
		for (int i = 0; i < n; i++)scanf(" %d", &m[i]); //질량

		//  F = G*m1*m2/(d*d)
		/*for(float x = p[0]; x<=p[1] ;x++)
		if ( (m[0] / (x - p[0])*(x - p[0])) == ( m[1] / (x - p[1])*(x - p[1])) )
			printf("%.10f", x);
		*/
		printf("#%d ", test_case + 1);
		for (int i = 0; i < n - 1; i++) // n개라면 n-1개의 균형점 존재 
		{
			printf("%.10f ",  binarySearch(i, p[i], p[i+1]));
			//printf("#%d %.10f\n", test_case+1, obtain(i);
		}
		printf("\n");
		/*	if (x < m[1])
				if ((m[0] / (x - p[0])*(x - p[0])) == (m[1] / (x - p[1])*(x - p[1])) + (m[2] / (x - p[2])*(x - p[2])) + (m[3] / (x - p[3])*(x - p[3])))
					printf("%.10f", x);
		if(x>m[1] && x<m[2])
			if ( (m[0] / (x - p[0])*(x - p[0])) + (m[1] / (x - p[1])*(x - p[1])) == (m[2] / (x - p[2])*(x - p[2])) + (m[3] / (x - p[3])*(x - p[3])) )
				printf("%.10f", x);
		if(x>m[2] && x<m[3])
			if ( (m[0] / (x - p[0])*(x - p[0])) + (m[1] / (x - p[1])*(x - p[1])) + (m[2] / (x - p[2])*(x - p[2])) == (m[3] / (x - p[3])*(x - p[3])) )
				printf("%.10f", x);
		*/

		/////////////////////////////////////////////////////////////////////////////////////////////////
		//printf("#%d ", test_case + 1);
		//printf("%d\n", Answer);
	}

	return 0;
}
