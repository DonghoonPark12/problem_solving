//#define	_CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include <set> //������ �޸𸮰� 8000Kb ���� Ŀ����. 
//using namespace std;
//
//int main()
//{
//	int n;//N�� ��
//	int Tc;
//	int Ans;//set�� 10�� ä������ �� ��µ� �� �ĺ� ��
//	int tmp;//set�� ���� �ֱ� ���� 1�ڸ� ���� �������� ��
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
//		for (int i = 1; ; i++) { //i ������ ��ų �� ���� ���� for�� ������ ����̴�.
//				int cnt = 0;
//			    Ans = n * i;
//			    tmp = Ans; //while���� int tmp�Ͽ��µ� while�� �ۿ��� ������ ���� ���Ͽ���.
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
//				if (a[j]) cnt++; //�̷��� �Ǹ� �迭 �μ��� ��� �����ϰ� �Ǽ� ���� ����̶�� �����ߴµ� ���̺귯�� ���� �޸� ���� ���� �� ���� �ð� �� ���� ����.
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
				mask &= ~(1 << (N % 10)); //11111 011110 �� ���Ѵ�.
				N /= 10; //�� �ڸ��� ���� Ȯ��
			}
		}
		printf("#%d %d\n", tc, k*a);
	}
	return 0;
}