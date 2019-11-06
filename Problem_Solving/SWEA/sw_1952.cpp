//#include <iostream>
//#include <cstdio>
//using namespace std;
////https://2youngjae.tistory.com/72
////https://github.com/gommuluk/SWExpertAcademy/blob/master/1952.cpp
//int cost[4];
//int plan[13]; //달별 이용일수 -> 달별 최소 비용(하루를 끊거나 한달 비용 지불)
////int dMonth[13];
//int min_cost[13];     // N번째 날의 누적된 최소값
//
//#define _min(a,b) (a) < (b) ?  a: b;
//
//int d, m, m3, y;
//int main() {
//		int T, test_case;
//	
//		freopen("input.txt", "r", stdin);
//		setbuf(stdout, NULL);
//	
//		scanf("%d", &T);
//	
//		//cin >> d >> m >> m3 >> y;
//		for (test_case = 0; test_case < T; test_case++)
//		{
//			for (int i = 0; i < 4; i++) {
//				cin >> cost[i]; //d, m, m3, y
//			}
//
//			for (int i = 1; i <= 12; i++) {
//				cin >> plan[i];//달별 사용 일수
//			}
//			
//			//min(하루요금x일수, 한달요금)
//			//1 ~ 12월간 최소값 저장
//			for (int i = 1; i <= 12; i++) {
//				plan[i] = _min(cost[0] * plan[i], cost[1]); // 따로 저장해 둔다???
//			}
//
//			//d[N] = N번째 날의 누적된 최소값
//			for (int i = 1; i <= 12; i++) {
//				min_cost[i] = min_cost[i - 1] + plan[i];
//				
//				if (i >= 3) {
//					if (min_cost[i - 3] + cost[2] < min_cost[i]) {
//						min_cost[i] = min_cost[i - 3] + cost[2];
//					}
//				}
//			}
//
//			if (min_cost[12] > cost[3]) {
//				min_cost[12] = cost[3];
//			}
//
//
//			printf("%%d %d\n", test_case + 1, min_cost[12]);
//		}
//		return 0;
//}


#include<iostream>
using namespace std;
int fee[4];
int month[12];
void total(int count, int ans);
int minimum;
int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		minimum = 99999999;
		for (int j = 0; j < 4; j++) {
			cin >> fee[j];
		}
		for (int j = 0; j < 12; j++) {
			cin >> month[j];
		}
		total(0, 0);
		if (minimum > fee[3]) {
			minimum = fee[3];
		}
		cout << "#" << i << " " << minimum << endl;
	}
}
void total(int count, int ans) {
	int i = count;
	for (i; i < 12; i++) {
		if (month[i] != 0) {
			total(i + 1, ans + fee[0] * month[i]);
			total(i + 1, ans + fee[1]);
			total(i + 3, ans + fee[2]);
			break; // break가 없으면 가령 3, 4, 5월 1일권으로 끊은 값만 합해지고 6월은 무시되면서 12월까지 가게 된다.
					 // 따라서, 1일권, 1개월권, 3개월권 전략을 한번씩 쓰고 끝내려면 break문을 써줘야 한다. 
			         // 그래야 i가 12까지 안간다. 
		}
	}
	if (i >= 12) {
		if (ans < minimum) {
			minimum = ans;
		}
	}
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
////https://2heedu.tistory.com/23
////개선된 코드로 수정
//int i, j, t, T, result;
//int d, m, m3, y;
////int dp[15];
//
//int plan[13];
//int dp[13];
//
//int main() {
//	int T, test_case;
//
//	freopen("input.txt", "r", stdin);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		cin >> d >> m >> m3 >> y;
//		
//		//int d_or_m;
//		//for (int i = 3; i <= 14; i++) {
//		//	cin >> dp[i]; // 1 ~ 12월 이용계획
//		//	d_or_m = min(dp[i - 1] + dp[i] * d, dp[i - 1] + m); //
//		//	dp[i] = min(d_or_m, dp[i - 3] + m3);
//		//}
//		//result = min(dp[14], y);
//
//		for (int i = 1; i <= 12; i++) {
//			cin >> plan[i];
//		}
//		dp[1] = min(min(plan[1] * d, m), m3);
//		dp[2] = min(min(plan[2] * d, m) + dp[1], m3);
//
//		for (int i = 3; i <= 12; i++) {
//			dp[i] = min(  min(plan[i] * d, m) + dp[i - 1], m3 + dp[i - 3]);
//		}
//		result = min(dp[12], y);
//
//		cout << "#" << test_case + 1 << " " << result << endl;
//
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int month[13][2];
//int Answer = 0;
//int d, m, m3, y;
//
//int m_d;
//
//int st(int x) {
//	/*
//		일일 권을 끊는게 낫다면, '그 달 이용횟수' * 1일권 금액
//		한달 권을 끊는게 낫다면, 
//	*/
//	if (x < m_d) { //하루씩 끊는게 낫다면
//		return x * d;
//	}
//	else {
//		return m;
//	}
//}
//
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false); cin.tie(0);
//	int T, test_case;
//
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//
//
//	for (test_case = 0; test_case < T; test_case++)
//	{
//
//		cin >> d >> m >> m3 >> y;
//
//		int tmp;
//		int sum_workout_day = 0;
//		m_d = m / d; //자주 쓰이는 기준이 된다. 일일권을 끊을 지, 한달 권을 끊을 지 판단하는 기준이 되는 이용횟수
//		                 //이 값 이상이면 한달 권을 끊는 것이 낫다. 
//		for (int i = 1; i <= 12; i++) {
//			cin >> tmp;
//			month[i][0] = tmp;
//			if (tmp < (m / d)) {//한달 가격 지불 하는 것 보다 1일 권 지불하는 것이 더 나은 경우
//				month[1][1] = 1;
//			}
//			sum_workout_day += tmp;
//		}
//
//		int cnt = 0;
//		for (int i = 1; i <= 12; i++) {
//			if (month[i] != 0)
//				cnt++;
//
//			if (cnt == 3) {
//				st(month[i - 2][0]) + st(month[i - 1][0]) + st(month[i][0]);
//			}
//
//		}
//
//		if (sum_workout_day <= m / d) { //만약 1년 동안 운동한 날이 할인 받을 정도도 아니면 (전체 일수 * 1일 금액)
//			Answer = d * sum_workout_day;
//		}
//
//
//		printf("#%d ", test_case + 1);
//		printf("%d\n", Answer);
//	}
//
//	return 0;
//}
