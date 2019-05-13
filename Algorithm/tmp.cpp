#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
		freopen("input.txt", "r", stdin);

		int LCS_length = 0, max; //LCS length
		int **table; //LCS saved in this table

		string str1, str2;

		//set String
		cin >> str1;
		cin >> str2;

		str1 = "0" + str1;
		str2 = "0" + str2;

		//set Table
		int len1, len2;
		len1 = str1.length();
		len2 = str2.length();

		table = new int*[len2];
		for (int i = 0; i < len2; i++) {
			table[i] = new int[len1];
		}

		for (int i = 0; i < len1; i++) {
			table[0][i] = 0; //행을 0으로 채움
		}

		//Calculation Table Index and LCS Length
		for (int i = 1; i < len2; i++) {
			max = 0;
			table[i][0] = 0; //열을 0으로 채움
			for (int j = 1; j < len1; j++) {
				if (str2[i] == str1[j]) {
					max = table[i - 1][j - 1] + 1;
					table[i][j] = max;
				}
				else {
					if (table[i][j - 1] > table[i - 1][j])
						table[i][j] = table[i][j - 1];
					else
						table[i][j] = table[i - 1][j];
				}
			}
		}
		LCS_length = table[len1 - 1][len2 - 1];
		cout << LCS_length << endl;


	return 0;
}
