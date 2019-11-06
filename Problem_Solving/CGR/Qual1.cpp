#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int _max(int a, int b, int c) {
	int max_l = a>b ? a : b;
	int max_r = b>c ? b : c;
	return max_l>max_r ? max_l : max_r;
}

vector<int> solution(vector<vector<int>> v, int k)
{
	vector<int> answer;

	vector<vector<int>> tmp(1000, vector<int>(2));
	int num_of_per = v.size();
	for (int i = 0; i<num_of_per; i++) {
		tmp[i][0] = _max(v[i][0], v[i][1], v[i][2]);
		tmp[i][1] = i + 1;
	}


	/*
	int m = tmp.size();
	int n = tmp[0].size();
	for(int i=0;i<m;i++){
	for(int j=0;j<n;j++)
	cout<<tmp[i][j]<<" ";
	cout<<endl;
	}
	*/

	return answer;
}