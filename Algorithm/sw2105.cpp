// [모의 SW역량 테스트: 디저트 카페

#include <iostream>
using namespace std;
int arr[20][20];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		int answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		
		



		cout << "#" << t << answer << endl;
	}
}