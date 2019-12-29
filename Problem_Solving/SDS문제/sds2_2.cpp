#include <iostream>
#include <algorithm>
#include <cstring>

//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

using namespace std;

int arr[64][64];
//int* arr[64];

//void solve(int arr[][64], int len) {
void solve(int (*arr)[64], int len, int sx, int sy) {
	if (len == 2) return;

	int maxB0=0, maxB1=0, maxB2=0, maxB3=0;

	for (int i = 0; i < len / 2; i++) { //2
		for (int j = 0; j < len / 2; j++) {
			maxB0 = max(maxB0, arr[sy+i][sx+j]);
		}

	}
	for (int i = 0; i < len / 2; i++) { //1
		for (int j = 0; j < len / 2; j++) {
			maxB1 = max(maxB1, arr[sy+i][sx+j+len/2]);
		}
	}
	for (int i = 0; i < len / 2; i++) { //3
		for (int j = 0; j < len / 2; j++) {
			maxB2 = max(maxB2, arr[sy+i+len/2][sx+j]);
		}
	}
	for (int i = 0; i < len / 2; i++) { //4
		for (int j = 0; j < len / 2; j++) {
			maxB3 = max(maxB3, arr[sy+i+len/2][sx+j+len/2]);
		}
	}
	int _min = min(min(min(maxB0, maxB1), maxB2), maxB3);
	int maxA = max(max(max(maxB0, maxB1), maxB2), maxB3);

	if (maxA < 1.2 * _min) {
		//분할 수행
		cout << "1";
		solve(arr, len / 2, 0, 0);//2
		solve(arr, len / 2, len/2, 0);//1
		solve(arr, len / 2, 0, len / 2);//1
		solve(arr, len / 2, len/2, len / 2);//1
	}
	else {
		cout << "0";
	}

}

int main() {
	//for (int i = 0; i < 64; i++)
	//	arr[i] = new int[64];

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		memset(arr, 0, sizeof(arr));
		int len;  cin >> len;
		for (int h = 0; h < len; h++) {
			for (int w = 0; w < len; w++) {
				cin >> arr[h][w];
			}
		}

		cout << "#" << i<<" ";
		solve(arr, len, 0, 0);
	}

	return 0;
}