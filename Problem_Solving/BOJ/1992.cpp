#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int img[64][64];
// string to interger in c/c++
//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c

string solve2(int(*arr)[64], int len, int sx, int sy) {
	//arr를 인자로 넘겨 받는 버전
	int s = arr[sy][sx]; bool flag = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i+sy][j+sx] != s) flag = false;
		}
	}
	if (flag) {
		return to_string(s);
	}

	string upperLeft = solve2(arr, len / 2, sx + 0, sy + 0);
	string upperRight = solve2(arr, len / 2, sx + len / 2, sy + 0);
	string lowerLeft = solve2(arr, len / 2, sx + 0, sy + len / 2);
	string lowerRight = solve2(arr, len / 2, sx + len / 2, sy + len / 2);

	return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

string solve3(int len, int sx, int sy) {
	//전역 img 쓰는 버전
	int s = img[sy][sx]; bool flag = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (img[i + sy][j + sx] != s) flag = false;
		}
	}
	if (flag) {
		return to_string(s);
	}

	string upperLeft  = solve3(len / 2, sx + 0,       sy + 0);
	string upperRight = solve3(len / 2, sx + len / 2, sy + 0);
	string lowerLeft  = solve3(len / 2, sx + 0,       sy + len / 2);
	string lowerRight = solve3(len / 2, sx + len / 2, sy + len / 2);

	return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

int main() {
	int len;  cin >> len;
	//for (int h = 0; h < len; h++) {
	//	for (int w = 0; w < len; w++) {
	//		scanf("%1d", &img[h][w]);
	//	}
	//}
	for (int i = 0; i < len; i++)	{
		string s; cin >> s;
		for (int j = 0; j < len; j++)
			img[i][j] = s[j] - '0';
	}

	//cout<<solve2(img, len, 0, 0);
	cout << solve3(len, 0, 0);
	return 0;
}