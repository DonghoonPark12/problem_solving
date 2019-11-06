// C++ program to check if a
// String can be converted
// to Pangram by atmost k modifications
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// Function to find if string
// can be converted to Pangram
// by atmost k modifications
bool isPangram(string S, int k)
{
	if (S.length() < 26) return false; // visit array to keep track // of all the characters // present in the array 
	int visited[26]; 
	for(int i = 0; i < S.length(); i++) 
		visited[S[i] - 'a'] = true; // A variable to keep count // of characters missing // in the string 
	int count = 0; 
	for(int i = 0; i < 26; i++){ 
		if (!visited[i]) count += 1; 
	} // Comparison of count // with given value K 
	if(count <= k ) 
		return true; 
	return false; 
} // Driver Code 
int main() { 
	freopen("input.txt", "r", stdin);
	//string S = "thequickquickfoxmumpsoverthelazydog";
	//int k = 15; // function calling 
	int t; string input; int k;
	cin >> t;
	cin >> input;
	cin >> k;
	isPangram(input, k) ? cout<< "true" : cout<< "false";
	return 0; 
} 