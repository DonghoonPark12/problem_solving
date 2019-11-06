#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool isPangram(string s, int k) {
	if (s.length() < 26) return false;

	int visited[26];
	for (int i = 0; i < 26; i++) visited[i] = 0;

	for (int i = 0; i<s.length(); i++) {
		//visited[i] = 0; //initialize
		visited[s[i] - 'a'] = true;
	}
	int cnt = 0;
	for (int i = 0; i<26; i++) {
		if (!visited[i]) 
			cnt++; //# of @ need to be changed
	}
	if (cnt<=k)
		return true;
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	int answer = 0;
	string input;
	int k; //# of character that can change

	int t; cin >> t;
	for (int i = 0; i<t; i++) {
		//getline(cin,input); 
		cin >> input;
		cin >> k;
		isPangram(input, k) ? cout << "1" : cout << "0";
		cout << endl;
	}
	return 0;
}