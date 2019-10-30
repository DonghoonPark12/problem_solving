#include <iostream>
#include <cstring>
using namespace std;
/* http://melonicedlatte.com/algorithm/2018/03/04/022437.html */

float ripen[21] = { 0, 1.53, 1.97, 2.39, 2.68, 2.94, 3.17, 3.21, 3.09, 2.75, 2.43, 2.02, 1.51, 1.19, 0.76, 0.43, 0.21, 0.17, 0.13, 0.11 };
//int num_fish[1001][2];
int num_fish[1001];
//int num_fish2[1001];
int qua_fish[1001];
/*
	(주의)
	최대 L일, L일 이하로도 사용가능
	일러도 8일 부터 상품화 하는게 상식. 그 이전에는 의미 없음
	N + 7일 까지 상품화 최대 기간.

*/
double R(int s, int j) {
	double sum = 0;
	for (int d = s; d < j; d++) { // i==3일 이면 1, 2일날 잡아들인 것만 상품화 가능. '그날 잡아 숙성지로 이동시킨 꽁치 제외' 따라서 등호 안들어 간다.
		//if (num_fish[d][1] != 1 && (i - d >= 20)) { //현재 일수와 숙성 시작 날짜가 20일 이상 차이나면.
		//	sum += num_fish[d][0] * qua_fish[d] * 0.1100; //현재일 - 잡아들인 날 : 숙성된 일 수
		//	//cout << num_fish[d] * qua_fish[d] * 0.1100 << ' ';
		//}
		//else if(num_fish[d][1] != 1) {
		//	sum += num_fish[d][0] * qua_fish[d] * ripen[i - d]; //현재일 - 잡아들인 날 : 숙성된 일 수
		//	//cout << num_fish[d] * qua_fish[d] * ripen[i - d] << ' ';
		//}
		//num_fish[d][1] = 1;//상품화 함

		if (j - d >= 20) { //현재 일수와 숙성 시작 날짜가 20일 이상 차이나면.
			sum += num_fish[d] * qua_fish[d] * 0.1100; //현재일 - 잡아들인 날 : 숙성된 일 수
														  //cout << num_fish[d] * qua_fish[d] * 0.1100 << ' ';
		}
		else {
			sum += num_fish[d] * qua_fish[d] * ripen[j - d]; //현재일 - 잡아들인 날 : 숙성된 일 수
																//cout << num_fish[d] * qua_fish[d] * ripen[i - d] << ' ';
		}
	}
	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		double Answer = 0.0000;
		int n, l; cin >> n >> l; //꽁치 잡이 하는 기간, 과메기 상품화 작업 일수
		memset(num_fish, 0, sizeof(num_fish));
		memset(qua_fish, 0, sizeof(qua_fish));
		for (int i = 1; i <= n; i++) {
			//cin >> num_fish[i][0]; //N일에 걸쳐 잡은 꽁치 어획량
			cin >> num_fish[i]; //N일에 걸쳐 잡은 꽁치 어획량
			//num_fish2[i] = num_fish[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> qua_fish[i]; //N일에 걸쳐 잡은 꽁치 품질
		}

		//double prev = 0;
		double _max = 0;


		if (l == 2 && n > 7) {//ㅣ이 2이상 이더라도, n이 7이하면 두번 상품화 할 필요 없다. 
			for (int i = 8; i <= 8 + n; i++) { //둘째날 부터 상품화가 가능하고, n일 이후 7일까지는 최대 값이 나올 가능성이 있다. 그 이후는 의미 없음. 
				for (int j = i; j <= 8 + n; j++) { //한번만 상품화 한다면 j=i로 즉 두번째 상품화 날짜랑 첫번째 상품화 날짜가 동일하게 잡으면 한번만 상품화 하는 것을 표현할 수 있다. 
						Answer = R(1, i);                //하지만, 두번째 상품화 날짜는 i보다는 같거나 커야 한다. 
						Answer += R(i, j);

						//if (Answer <= _max) {
						//	for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
						//	break;
						//}
						if (_max < Answer) {
							_max = Answer;
							//cout << "★" << "(i, j, k) : " << i << ", " << j;
						}
						//cout << "  Day :" << i << " --> " << Answer << endl;
						//for (int i = 1; i <= n; i++) { num_fish[i][1] = 0; }

						//if (Answer < prev)
						//	break;
						//prev = Answer;
				}
			}
		}
		else if (l == 3 && n > 7) {
			for (int i = 8; i <= 8 + n; i++) {
				for (int j = i; j <= 8 + n; j++) { 
					for (int k = j; k <= 8 + n; k++) {
						Answer = R(1, i);            
						Answer += R(i, j);
						Answer += R(j, k);

						//if (Answer <= _max) {
						//	for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
						//	break;
						//}
						if (_max < Answer) {
							_max = Answer;
							//cout << "★" << "(i, j, k) : " << i << ", " << j << ", " << k<<" "<<Answer<<endl;
						}
						//cout << "  Day :" << i << " --> " << Answer << endl;

						//for (int i = 1; i <= n; i++) { num_fish[i][1] = 0; }

						//if (Answer < prev)
						//	break;
						//prev = Answer;
					}
				}
			}
		}
		else if (l == 4 && n > 7) {
			for (int i = 8; i <= 8 + n; i++) { 
				for (int j = i; j <= 8 + n; j++) { 
					for (int k = j; k <= 8 + n; k++) {
						for (int m = k; m <= 8 + n; m++) {
							Answer = R(1, i);               
							Answer += R(i, j);
							Answer += R(j, k);
							Answer += R(k, m);
							//if (Answer <= _max) {
							//	for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
							//	break;
							//}
							if (_max < Answer) {
								_max = Answer;
								//cout << "★" << "(i, j, k) : " << i << ", " << j << ", " << k;
							}
						    //	cout << "  Day :" << i << " --> " << Answer << endl;
							
						}
					}
				}
			}
		}
		else if (l == 5 && n > 7) {
			for (int i = 8; i <= 8 + n; i++) { 
				for (int j = i; j <= 8 + n; j++) { 
					for (int k = j; k <= 8 + n; k++) {
						for (int m = k; m <= 8 + n; m++) {
							for (int o = m; o <= 8 + n; o++) {
								Answer = R(1, i); 
								Answer += R(i, j);
								Answer += R(j, k);
								Answer += R(k, m);
								Answer += R(m, o);

								//if (Answer <= _max) {
								//	for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
								//	break;
								//}
								if (_max < Answer) {
									_max = Answer;
								//	cout << "★" << "(i, j, k) : " << i << ", " << j << ", " << k;
								}
								//cout << "  Day :" << i << " --> " << Answer << endl;

								//for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
							}
						}
					}
				}
			}
		}
		else {
			for (int i = 8; i <= 7 + n; i++) {
				Answer = R(1, i);
				if (_max < Answer) {
					_max = Answer;
					//cout << "★";
				}
				//cout << "  Day :" << i << " --> " << Answer << endl;
				//for (int i = 1; i <= n; i++) { num_fish[i][1] = 0; }

				//if (Answer < prev)
				//	break;
				//prev = Answer;
			}
		}

		printf("#%d ", test_case + 1);
		printf("%.2f\n", _max);
	}

	return 0;
}
