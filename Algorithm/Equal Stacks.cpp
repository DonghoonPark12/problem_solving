#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int max_among(int a, int b, int c) {
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else if (c > a && c > b)
		return c;
	else {}
}
/*
* Complete the equalStacks function below.
*/
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
	int sum_h1, sum_h2, sum_h3;
	int l;
	vector<int>::iterator iter;
	sum_h1 = 0; sum_h2 = 0; sum_h3 = 0;
	for (iter = h1.begin(); iter != h1.end(); iter++) {
		sum_h1 += *iter;
	}
	for (iter = h2.begin(); iter != h2.end(); iter++) {
		sum_h2 += *iter;
	}
	for (iter = h3.begin(); iter != h3.end(); iter++) {
		sum_h3 += *iter;
	}

	int i1 = 0, i2 = 0, i3 = 0;

/*	while (!(sum_h1 == sum_h2 && sum_h2 == sum_h3)) {
		if (i1 < h1.size() && (sum_h1 > sum_h2 || sum_h1 > sum_h3)) {
			sum_h1 -= h1[i1];
			i1++;
		}
		else if (i2 < h2.size() && (sum_h2 > sum_h1 || sum_h2 > sum_h3)) {
			sum_h2 -= h2[i2];
			i2++;
		}
		else if (i3 < h3.size() && (sum_h3 > sum_h1 || sum_h3 > sum_h2)) {
			sum_h3 -= h3[i3];
			i3++;
		}
	}*/

	//while (!(sum_h1 == sum_h2 && sum_h2 == sum_h3)) {
	//	if (i1 < h1.size() && (max_among(sum_h1, sum_h2, sum_h3) == sum_h1)) {
	//		sum_h1 -= h1[i1];
	//		i1++;
	//	}
	//	else if (i2 < h2.size() && (max_among(sum_h1, sum_h2, sum_h3) == sum_h2)) {
	//		sum_h2 -= h2[i2];
	//		i2++;
	//	}
	//	else if (i3 < h3.size() && (max_among(sum_h1, sum_h2, sum_h3) == sum_h3)) {
	//		sum_h3 -= h3[i3];
	//		i3++;
	//	}
	//}
	return sum_h1;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));
	//auto res = getenv("OUTPUT_PATH");//환경변수 OUTPUT_PATH의 값을 반환.
	//ofstream fout(res); //저장된 환경변수 값 res를 가지고 ofstream 객체를 생성한다. 
	freopen("input.txt", "r", stdin);
	string n1N2N3_temp;
	getline(cin, n1N2N3_temp); //5 3 4

	vector<string> n1N2N3 = split_string(n1N2N3_temp);

	int n1 = stoi(n1N2N3[0]);

	int n2 = stoi(n1N2N3[1]);

	int n3 = stoi(n1N2N3[2]);

	string h1_temp_temp;
	getline(cin, h1_temp_temp); //3 2 1 1 1

	vector<string> h1_temp = split_string(h1_temp_temp);

	vector<int> h1(n1);

	for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
		int h1_item = stoi(h1_temp[h1_itr]);

		h1[h1_itr] = h1_item;
	}

	string h2_temp_temp;
	getline(cin, h2_temp_temp); //4 3 2

	vector<string> h2_temp = split_string(h2_temp_temp);

	vector<int> h2(n2);

	for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
		int h2_item = stoi(h2_temp[h2_itr]);

		h2[h2_itr] = h2_item;
	}

	string h3_temp_temp;
	getline(cin, h3_temp_temp); //1 1 4 1

	vector<string> h3_temp = split_string(h3_temp_temp);

	vector<int> h3(n3);

	for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
		int h3_item = stoi(h3_temp[h3_itr]);

		h3[h3_itr] = h3_item;
	}

	int result = equalStacks(h1, h2, h3);

	//fout << result << "\n";
	cout << result << "\n";
	//fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
