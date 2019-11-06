#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >>  n; //[1, 1.000.000]
	vector<int> per;
	per.resize(n); //[1, 1.000.000]
	for (int i = 0; i < n; i++) // ������ �� �ִ� �л���: 10^12
		cin>>per[i];
	int c, b; cin >> c >> b; //[1, 1.000.000]

	unsigned long long cnt = 0; //������ ���� �� �� �ִ� �ּ� �л��� 1�̱� ������ cnt�� �ִ� 10^12

	for (int i = 0; i < n; ++i) {
		if (per[i] >= c) {
			per[i] -= c;
			cnt++;
			//while (per[i]>0) { //���� �̷��� ���ִ� �͵� �ð��ʰ��� ���.
			//	per[i] -= b;
			//	cnt++;
			//}
			while (per[i] > 0) {
				int m = per[i] / b;//���� ����.
				per[i] -= m * b;
				if (m > 0) //���� �ο����� �� ���� �ɷ�ġ ���� ũ�ٸ�
					cnt += m; //�ʿ��� �ΰ����� �� ��ŭ(��) �����ش�.
				else {
					cnt += 1; //�ΰ����� �ɷ�ġ ���� ���� �ο��� ���Ҵٸ� 1�����ְ� ������.
					break;
				}
			}
		}
		else {
			cnt++;
		}
	}
	cout << cnt;


	return 0;
}