#include <iostream>
#include <string>
#include <deque>
using namespace std;

int find(string str, deque<string> vstr) {
	for (int i = 0; i < vstr.size(); i++) {
		if (vstr[i] == str) return i;
	}
	return -1;
}

void LRU(int n, string memory[],int len) {
	int pf = 0;
	deque<string> strarr;
	//int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i<len; i++) {
		string str = memory[i]; //임시 저장

		for (int k = 0; k < memory[i].size(); k++) {
			str[k] = (str[k] >= 'a' && str[k] <= 'z') ? str[k] - 32 : str[k];
		}//대문자로 바꾸기

		memory[i] = str;

		int m = find(memory[i], strarr); //캐시에서 어디에 위치하는지, 못찾으면 -1
		
		if (strarr.size() < n && find(memory[i], strarr) < 0) {//캐시가 비었고, 캐시에 위치하지 않는다면
			pf += 5;
			strarr.push_back(memory[i]);//캐시에 삽입
		}
		else if (m >= 0) { //캐시에 위치하고 있다면 
			string tmp = strarr[m];
			strarr[m] = strarr.back();// 왜 가장 최근 것을 해당 자리에 집어 넣지??
			strarr.pop_back();
			strarr.push_back(tmp);
			pf++;
		}
		else if (m < 0) { //캐시에 위치하고 있지 않다면
			pf += 5;
			if (strarr.size() != 0)// 캐시에 원소가 있을 경우, pop_front()
				strarr.pop_front();// 캐시에 원소가 없으면 pop_front() 안한다.
			strarr.push_back(memory[i]);
		}
		else
		{

		}
	}
	cout << pf << endl;
}

int main() {
	// string의 배열
	string memory1[10] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
	string memory2[9] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
	string memory3[12] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string memory4[12] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string memory5[4] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	string memory6[5] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	LRU(3, memory1, sizeof(memory1) / sizeof(memory1[0]));
	LRU(3, memory2, sizeof(memory2) / sizeof(memory2[0]));
	LRU(2, memory3, sizeof(memory3) / sizeof(memory3[0]));
	LRU(5, memory4, sizeof(memory4) / sizeof(memory4[0]));
	LRU(2, memory5, sizeof(memory5) / sizeof(memory5[0]));
	LRU(0, memory6, sizeof(memory6) / sizeof(memory6[0]));

	return 0;
}