//#define	_CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//using namespace std;
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int N;
//	int Answer = 0;

//	//freopen("input.txt", "r", stdin);
//	cin >> N;
//
//
//	return 0;
//
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
////int op[4];//+, -, *, /
//int num[12];
//vector<char> op2;
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
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int Answer = 0;
//		int n; cin >> n;
//		op2.clear();
//
//
//
//		for (int i = 0; i < 4; i++) {
//			int num;
//			cin >> num;
//			if (i == 0) { while (num--) op2.push_back('+'); }
//			if (i == 1) { while (num--) op2.push_back('-'); }
//			if (i == 2) { while (num--) op2.push_back('*'); }
//			if (i == 3) { while (num--) op2.push_back('/'); }
//		}
//
//		memset(num, 0, sizeof(num));
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//
//		int sum;
//		int _min = 100000000;
//		int _max = -100000000;
//		do {
//		 	sum = 0;
//		/*	for (int i = 0; i < op2.size(); i++) {
//				cout << op2[i] << ' ';
//			}*/
//			//cout << endl;
//			for (int i = 0; i < op2.size(); i++) {
//				if (op2[i] == '+') {
//					if(i==0) sum += num[i] + num[i+1];
//					else sum += num[i+1];
//				}
//				else if (op2[i] == '-') {
//					if(i==0) sum += num[i] - num[i + 1];
//					else sum -= num[i+1];
//				}
//				else if (op2[i] == '*') {
//					if(i==0) sum += num[i] * num[i + 1];
//					else sum *= num[i+1];
//				}
//				else { //'/'
//					if(i==0) sum += num[i] / num[i + 1];
//					else sum /= num[i+1];
//				}
//			}
//			if (sum > _max)
//				_max = sum;
//			if (sum < _min)
//				_min = sum;
//			cout << "Max: " << _max << " " << "Min: " << _min << endl;
//		} while (next_permutation(op2.begin(), op2.end()));
//
//		printf("#%d ", test_case + 1);
//		printf("%d\n", _max - _min);
//	}
//
//	return 0;
//
//}

//#define	_CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void)
//{
//  ios_base::sync_with_stdio(false); cin.tie(0);
//	int N, Answer = 0;
//	setbuf(stdout, NULL);
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	int arr[100000] = { 0 };
//	scanf("%d\n", &N);
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d ", arr[i]);
//	}
//
//	printf("%d\n", Answer);
//	return 0;
//
//}

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제 
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////


