//#include <bits/stdc++.h>
#include <iostream>
#define max(a,b) ((a) > (b) ? (a):(b))
using namespace std;
/*
def maxXOR(L,R):
	P = L^R
	ret = 1
	while(P):
		ret<<=1
		P>>1
	return(ret-1)
*/
// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
	int ret = 0;
	//int xor_;
	for (int i = l; i <= r; i++) {
		for (int j = i; j <= r; j++) {
			//xor_ = i^j;
			ret = max(ret, i^j);//1등 자리 유지
			//if (xor_ > max)
			//	max = xor_;
		}
	}
	return ret;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int l;
	cin >> l;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int r;
	cin >> r;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//int result = maximizingXor(l, r);
	maximizingXor(l, r);

	//cout << result << "\n";

	//fout.close();

	return 0;
}