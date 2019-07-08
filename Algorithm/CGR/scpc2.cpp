#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.141592653589
double Answer;
int R, s, e;
int l, r, h;
int n;

typedef struct obstacle{
	int l,r,h;
}obs;
obs arr[1001];

double high_building(int i) {
	double ans = 0;
	ans += (arr[i].h * 2) - 2 * R + (arr[i].r - arr[i].l);
	//	cout << (arr[i].h * 2) - 2 * R + (arr[i].r - arr[i].l) << endl;
	ans += pi * R;

	if (i != n) {
		ans += arr[i + 1].l - arr[i].r - 2 * R;
		//cout<< arr[i + 1].l - arr[i].r - 2 * R<<endl;
	}

	return ans;

}

double low_building(int i) {
	double ans = 0;
	ans += arr[i].r - arr[i].l;
	
	//double rate =
	ans += 2 * R * acos((R - arr[i].h) / (double)R);

	//double sqrt_ = //important
	ans += (R - sqrt(pow(R, 2) - pow((R - arr[i].h), 2))) * 2; 
	
	if (i != n) {
		ans += arr[i + 1].l - arr[i].r - 2 * R;
		//cout<< arr[i + 1].l - arr[i].r - 2 * R<<endl;
	}
	return ans;
}

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> R >> s >> e;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			cin >> l >> r >> h;
			arr[i] = { l, r, h };

		}
		Answer += arr[1].l - s - R;
		for (int i = 1; i <= n; i++) {
			if (arr[i].h >= R)
				Answer += high_building(i);
			else
				Answer += low_building(i);
		}

		Answer += e - arr[n].r - R;

		cout << "Case #" << test_case + 1 << endl;
		//cout << Answer << endl;
		printf("%f\n", Answer);
	}

	return 0;

}