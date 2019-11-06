/*
https://www.geeksforgeeks.org/operating-system-page-replacement-algorithm/
https://www.geeksforgeeks.org/program-page-replacement-algorithms-set-1-lru/
Place replacement algorithm are needed to decise which page needed to be replaced when new page comes in.
Whenever a new page is referred and not present in cache, page fault occurs and OS replaces one of the existing pages with newly needed page.
Different page replacement algo suggest diff ways to decide page to replace. 
The target for all algo is to reduce number of page faults.
http://simsimjae.tistory.com/87
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
//#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

int find(deque<int> cache, int n ) {
	for (int i = 0; i < cache.size(); i++) {
		if (cache[i] == n) return i;
	}
	return -1;
}

int main() {
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	// �������� ���������� �о���̴� ���̹Ƿ�, ��������. list, vector, �迭.
	//list<int> page;
	//list<int> cache;
	//tree<int> cache;

	
	for (int tc = 1; tc <= t; tc++) {
		int PageFault = 0;
		int n, pages;
		int space;
		int idx; //
		//list<int>::iterator it;
		//list<string> cache;
		//list<int> memory;
		//int memory[1001];
		deque<int> memory;
		deque<int> cache;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> pages;
			memory.push_back(pages);
		}

		cin >> space;
		
		//for(it = page.begin(); it != page.end(); it++) {
		for(int i=0; i < n ; i++){
			int m = find(cache, memory.at(i));
			/* cache�� full�� �ƴϸ� ä��� PageFault++ */
			if (cache.size() != space && m < 0 ) {
				cache.push_back(memory.at(i));
				PageFault++;
			}
			/* cache�� full�̰�, memory�� �ִٸ� ������ ����´�. */
			else if (m >= 0)  {
				int tmp = cache.at(m);
				for (; m+1 < cache.size(); m++) {
					cache.at(m) = cache.at(m + 1);
				}
				//cache.at(m) = cache.back();
				cache.pop_back();
				cache.push_back(tmp);
			}
			/* ���ٸ� �� �ڿ� ���� ����. */
			else if (m < 0) {
				PageFault++;
				if (cache.size() != 0)
					cache.pop_front();
				cache.push_back(memory.at(i));
			}
			else {}
		}
		cout << PageFault << endl;
	}
	return 0;
}