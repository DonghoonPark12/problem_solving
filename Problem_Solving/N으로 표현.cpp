#include <string>
#include <vector> 
#include <cmath> 
#include <algorithm>
#include <iostream>B
using namespace std; 

vector<int> list; 
int count_ = 0; 
int minCount = 9; 

// 완전 탐색 알고리즘 (Brute-Force Search) 
void BFS(int N, int number) { 
	if(count_ >= minCount) 
		return; 
	if(list.size() >= minCount) 
		return; 
	int lastNumber = (list.size() == 0) ? 0 : list.back(); 

	if(lastNumber == number) { 
		minCount = min(count_, minCount); 
		return; 
	} 
	
	int n = 0; 
	int addCount = 0; 
	
	for(int c = 1; c <= 10000000; c *= 10) { 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    		addCount++; 
		if(count_ + addCount >= minCount) continue;
		
		n += (N * c);
		count_ += addCount; 
		
		list.push_back(lastNumber + n); 
		BFS(N, number); 
		list.pop_back(); 
		
		if(lastNumber - n != 0) { 
			list.push_back(lastNumber - n); 
			BFS(N, number); 
			list.pop_back(); 
		} 
		
		list.push_back(lastNumber * n);
		BFS(N, number);
		list.pop_back(); 
		
		if(lastNumber / n != 0) { 
			list.push_back(lastNumber / n); 
			BFS(N, number); 
			list.pop_back(); 
		} 
		count_ -= addCount; 
	}
	return; 
} 

int solution(int N, int number) {
	BFS(N, number); 
	return minCount < 9 ? minCount : -1; 
}

int main() {
	cout << solution(5, 12);
}
