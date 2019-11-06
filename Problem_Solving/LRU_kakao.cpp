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
		string str = memory[i]; //�ӽ� ����

		for (int k = 0; k < memory[i].size(); k++) {
			str[k] = (str[k] >= 'a' && str[k] <= 'z') ? str[k] - 32 : str[k];
		}//�빮�ڷ� �ٲٱ�

		memory[i] = str;

		int m = find(memory[i], strarr); //ĳ�ÿ��� ��� ��ġ�ϴ���, ��ã���� -1
		
		if (strarr.size() < n && find(memory[i], strarr) < 0) {//ĳ�ð� �����, ĳ�ÿ� ��ġ���� �ʴ´ٸ�
			pf += 5;
			strarr.push_back(memory[i]);//ĳ�ÿ� ����
		}
		else if (m >= 0) { //ĳ�ÿ� ��ġ�ϰ� �ִٸ� 
			string tmp = strarr[m];
			strarr[m] = strarr.back();// �� ���� �ֱ� ���� �ش� �ڸ��� ���� ����??
			strarr.pop_back();
			strarr.push_back(tmp);
			pf++;
		}
		else if (m < 0) { //ĳ�ÿ� ��ġ�ϰ� ���� �ʴٸ�
			pf += 5;
			if (strarr.size() != 0)// ĳ�ÿ� ���Ұ� ���� ���, pop_front()
				strarr.pop_front();// ĳ�ÿ� ���Ұ� ������ pop_front() ���Ѵ�.
			strarr.push_back(memory[i]);
		}
		else
		{

		}
	}
	cout << pf << endl;
}

int main() {
	// string�� �迭
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