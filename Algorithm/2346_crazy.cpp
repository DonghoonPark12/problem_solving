#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int it = 0;
	int it_old = 0;
	int n;
	int cnt = 0;

	//freopen("input.txt", stdin);

	scanf("%d", &n);

	int tmp;
	vector<int> v;
	for(int i=0;i<n;i++) {
		scanf(" %d", &tmp);
		v.push_back(tmp);
	}

	while (1) {
		printf("%d ", it+1);//1
		if (v.at(it_old) < 0) { //�������� �� ��
			for (int i = 0; i < abs(v.at(it_old)); i++) {// i.g) -3�̶�� ���밪���� ���
					it--; // �ε��� ����
					if (v.at(it) == 0) { // 0�̶��..
						while (v.at(it) == 0) { // �ε����� �ش� ���� 0 �� �ƴҶ� ����
							it--; // �ε��� ����
							if (it < 0) // �ε����� ������ �Ǹ�, �ٽ� �� �ٷ� �Ѿ�´�. 
								it = it + n;
						}
					}
			}
			if (it < 0)
				it =it + n;
		}
		else { //���������� �� ��. 
			for (int i = 0; i < v.at(it_old); i++) { // i.g) 3�̶�� 3���� ȸ��
					it++; // �ε��� ����
					if (v.at(it) == 0) { // 0�̶��..
						while (v.at(it) == 0) { // �ε����� �ش� ���� 0 �� �ƴҶ� ����
							it++; // �ε��� ����
							if (it >= n) // �ε����� n�� ũ�Ⱑ �Ǹ�, �ٽ� ù �ٷ� �Ѿ�´�.
								it = it - n;
						}
					}
			}
			if (it > n)
				it = it - n;
		}

		v.at(it_old) = 0;

		it_old = it;

		for (int i = 0; i < n; i++) {
			if (v.at(i) == 0)
				cnt++;
		}
		if (cnt == n)
			break;
		else
			cnt = 0;
	}

	return 0;
}