#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
�� ������ ����, ���� �ڸ��� ���ƿ;� �ϹǷ�
�ڷ��� List�� ����� �ʿ䰡 �ִ�.
*/

int main() {
	int n;
	//list<pair<int, int>> a;//¦�� ���� ���� ���ҷ� ������ List
	list<pair<int, int>> v;
	scanf("%d", &n);

	int tmp;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &tmp);
		v.push_back({ tmp,i });
	}

	auto it = v.begin(); //���� Ÿ���� ������ �ÿ� ����

	for (int i = 0; i < n - 1; i++) {
		//printf("%d ", it->second);
		cout << (it->second) << ' ';
		int step = it->first;// ����� �� ������
		if (step > 0) { //���������� ���ٸ�
			auto temp = it; //�ְ�

			++temp;
			if (temp == v.end())
				temp = v.begin();

			v.erase(it); //�����.
			it = temp;  //�ٽ� ���� �ް�
			for (int i = 1; i < step; i++) {
				++it; //vector�϶��� ������ ����. ��?..
				if (it == v.end())
					it = v.begin();
			}
		}
		//v.erase(it);�� �̸� �ϸ�, --it�� �� �� ����.
		//����, temp���� �Ѱ��ְ�, temp�� �ѹ� �̵� ��Ų ��
		// v.erase(it), it���� temp�� �Ѱ��ְ�, �ѹ� �� ����.
		//list�� end()�� ������ ���� ���� ���� ��, NULL���� ſ�� step -/+ �� ���� ������ �ٸ���.
		else {
			step = -step;
			auto temp = it; //�ְ�

			if (temp == v.begin())
				temp = v.end();
			--temp;

			v.erase(it); //�����.
			it = temp; //�ٽ� ���� �ް�
			for (int i = 1; i < step; i++) {
				if (it == v.begin()) {
					it = v.end();
				}
				--it;
			}
		}
	}

	printf("%d\n", v.front().second);

	return 0;
}