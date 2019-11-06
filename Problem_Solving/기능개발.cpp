#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	//vector<int> prices_compare(prices.size(), 0);
	//prices_compare[prices.size() - 1] = prices.back();
	//int min = prices.back();
	//for (int i = prices.size()-2; i>=0; i--) {
	//	if (prices[i] < min )
	//		min = prices[i];
	//	prices_compare[i] = min;
	//}
	//int cum = 0;
	//answer[prices.size() - 1] = 0;
	//for (int i = prices.size() -2; i >= 0; i--) {
	//	if (prices[i] >= prices_compare[i])
	//		cum++;
	//	answer[i] = cum;
	//}

	//int cnt;
	//for (int i = 0; i<prices.size(); i++) {
	//	//cnt = 1;
	//	for (int j = i; j<prices.size() - 1; j++) {
	//		if (prices[j] >= prices[i])
	//			answer[i] += 1; 
	//		else
	//			break;
	//	}
	//}
	//return answer;


	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();
	for (int i = 0; i<size; i++) {
		while (!s.empty() && prices[s.top()]>prices[i]) {
			answer[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
	
}

int main(void)
{
	int N;
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	vector<int> heights;
	int n;
	for (int i = 0; i < 4; i++) {
		cin >> n;
		heights.push_back(n);
	}
	solution(heights);


	return 0;

}