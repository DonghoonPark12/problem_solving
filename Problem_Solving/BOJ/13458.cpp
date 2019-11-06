#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >>  n; //[1, 1.000.000]
	vector<int> per;
	per.resize(n); //[1, 1.000.000]
	for (int i = 0; i < n; i++) // 시험장 총 최대 학생수: 10^12
		cin>>per[i];
	int c, b; cin >> c >> b; //[1, 1.000.000]

	unsigned long long cnt = 0; //감독이 감시 할 수 있는 최소 학생수 1이기 때문에 cnt는 최대 10^12

	for (int i = 0; i < n; ++i) {
		if (per[i] >= c) {
			per[i] -= c;
			cnt++;
			//while (per[i]>0) { //때론 이렇게 빼주는 것도 시간초과가 뜬다.
			//	per[i] -= b;
			//	cnt++;
			//}
			while (per[i] > 0) {
				int m = per[i] / b;//몫을 본다.
				per[i] -= m * b;
				if (m > 0) //남은 인원수가 부 감독 능력치 보다 크다면
					cnt += m; //필요한 부감독의 수 만큼(몫) 더해준다.
				else {
					cnt += 1; //부감독의 능력치 보다 적은 인원이 남았다면 1더해주고 끝낸다.
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