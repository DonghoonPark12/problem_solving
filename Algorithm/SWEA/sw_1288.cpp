//#define	_CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include <set> //넣으니 메모리가 8000Kb 정도 커졌다. 
//using namespace std;
//
//int main()
//{
//	int n;//N번 양
//	int Tc;
//	int Ans;//set이 10번 채워졌을 때 출력될 수 후보 값
//	int tmp;//set에 집어 넣기 위해 1자리 별로 나눠지는 값
//	int N;
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &Tc);
//	for (int tc = 1; tc <= Tc; tc++) {
//		
//		//set<int> a;
//		int a[10] = { 0 };
//		scanf("%d", &n);//1295
//
//		//while (1) {
//		for (int i = 1; ; i++) { //i 증가만 시킬 때 조건 없는 for문 괜찮은 방법이다.
//				int cnt = 0;
//			    Ans = n * i;
//			    tmp = Ans; //while문에 int tmp하였는데 while문 밖에서 참조를 하지 못하였다.
//			while (tmp) {
//				int res = tmp % 10;
//				//a.insert(res);
//				a[res]++;
//				tmp /= 10;
//			}
//
//			//if (a.size() == 10) {
//			//	break;
//			//}
//			//else {
//			//	cnt++;
//			//}
//			for (int j = 0; j < 10; j++) {
//				if (a[j]) cnt++; //이렇게 되면 배열 인수가 계속 증가하게 되서 느린 방법이라고 생각했는데 라이브러리 보다 메모리 적게 차지 및 실행 시간 별 차이 없다.
//			}
//			if (cnt == 10) break;
//		}
//		printf("#%d %d\n", tc,Ans);
//	}
//	return 0;
//}
//
#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main() {
	int T;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int a, k = 0, N, mask = (1 << 10) - 1; //00000 00000 0
		scanf("%d", &a);

		while (mask) {// 11111 11111
			++k;
			N = k * a;
			while (N > 0) {
				mask &= ~(1 << (N % 10)); //11111 011110 을 곱한다.
				N /= 10; //각 자리별 숫자 확인
			}
		}
		printf("#%d %d\n", tc, k*a);
	}
	return 0;
}