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
	(����)
	�ִ� L��, L�� ���Ϸε� ��밡��
	�Ϸ��� 8�� ���� ��ǰȭ �ϴ°� ���. �� �������� �ǹ� ����
	N + 7�� ���� ��ǰȭ �ִ� �Ⱓ.

*/
double R(int s, int j) {
	double sum = 0;
	for (int d = s; d < j; d++) { // i==3�� �̸� 1, 2�ϳ� ��Ƶ��� �͸� ��ǰȭ ����. '�׳� ��� �������� �̵���Ų ��ġ ����' ���� ��ȣ �ȵ�� ����.
		//if (num_fish[d][1] != 1 && (i - d >= 20)) { //���� �ϼ��� ���� ���� ��¥�� 20�� �̻� ���̳���.
		//	sum += num_fish[d][0] * qua_fish[d] * 0.1100; //������ - ��Ƶ��� �� : ������ �� ��
		//	//cout << num_fish[d] * qua_fish[d] * 0.1100 << ' ';
		//}
		//else if(num_fish[d][1] != 1) {
		//	sum += num_fish[d][0] * qua_fish[d] * ripen[i - d]; //������ - ��Ƶ��� �� : ������ �� ��
		//	//cout << num_fish[d] * qua_fish[d] * ripen[i - d] << ' ';
		//}
		//num_fish[d][1] = 1;//��ǰȭ ��

		if (j - d >= 20) { //���� �ϼ��� ���� ���� ��¥�� 20�� �̻� ���̳���.
			sum += num_fish[d] * qua_fish[d] * 0.1100; //������ - ��Ƶ��� �� : ������ �� ��
														  //cout << num_fish[d] * qua_fish[d] * 0.1100 << ' ';
		}
		else {
			sum += num_fish[d] * qua_fish[d] * ripen[j - d]; //������ - ��Ƶ��� �� : ������ �� ��
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
		int n, l; cin >> n >> l; //��ġ ���� �ϴ� �Ⱓ, ���ޱ� ��ǰȭ �۾� �ϼ�
		memset(num_fish, 0, sizeof(num_fish));
		memset(qua_fish, 0, sizeof(qua_fish));
		for (int i = 1; i <= n; i++) {
			//cin >> num_fish[i][0]; //N�Ͽ� ���� ���� ��ġ ��ȹ��
			cin >> num_fish[i]; //N�Ͽ� ���� ���� ��ġ ��ȹ��
			//num_fish2[i] = num_fish[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> qua_fish[i]; //N�Ͽ� ���� ���� ��ġ ǰ��
		}

		//double prev = 0;
		double _max = 0;


		if (l == 2 && n > 7) {//���� 2�̻� �̴���, n�� 7���ϸ� �ι� ��ǰȭ �� �ʿ� ����. 
			for (int i = 8; i <= 8 + n; i++) { //��°�� ���� ��ǰȭ�� �����ϰ�, n�� ���� 7�ϱ����� �ִ� ���� ���� ���ɼ��� �ִ�. �� ���Ĵ� �ǹ� ����. 
				for (int j = i; j <= 8 + n; j++) { //�ѹ��� ��ǰȭ �Ѵٸ� j=i�� �� �ι�° ��ǰȭ ��¥�� ù��° ��ǰȭ ��¥�� �����ϰ� ������ �ѹ��� ��ǰȭ �ϴ� ���� ǥ���� �� �ִ�. 
						Answer = R(1, i);                //������, �ι�° ��ǰȭ ��¥�� i���ٴ� ���ų� Ŀ�� �Ѵ�. 
						Answer += R(i, j);

						//if (Answer <= _max) {
						//	for (int i = 1; i <= n; i++) { num_fish[i] = num_fish2[i]; }
						//	break;
						//}
						if (_max < Answer) {
							_max = Answer;
							//cout << "��" << "(i, j, k) : " << i << ", " << j;
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
							//cout << "��" << "(i, j, k) : " << i << ", " << j << ", " << k<<" "<<Answer<<endl;
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
								//cout << "��" << "(i, j, k) : " << i << ", " << j << ", " << k;
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
								//	cout << "��" << "(i, j, k) : " << i << ", " << j << ", " << k;
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
					//cout << "��";
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
