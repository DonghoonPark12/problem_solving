#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

int Answer;

char tmp[100];
char arr[100][100];
int isPalindrome(char arr[][100]) {
	int l;
	int i, j;//���⿡ �����ؾ� i,j�� for�� �ۿ����� ����� �� �ִ�. 
	int max = 0;
	int cnt = 0;//ȸ�� ������ �����ϴ� �������� ȸ�� ���̸� �����ϴ� ������ �ٲ�
	for (l = 0; l < 100; l++) {
		for (i = 0; i<100; i++) {
			if (max > 100 - i) break;
			for (int cen = 0; cen < i + 1; cen++) {//i�� 1�� ��� 0, 1 // i�� 99�� ��� 0, 1, .. 99 ��ġ���� �˻�
				cnt = 0;
				/* --------------- */

				for (j = 0; j < (100 - i) / 2; j++) { //i�� 1�̸� �Ӹ���� �˻�� 99/2�� �ȴ�. 
				//if (*((arr + i) + j) != *((arr + i) + n - 1 - j))
					if (arr[l][cen + j] != arr[l][cen + (100 - i) - 1 - j]) break;
				}
				if (j == (100 - i) / 2)  //�Ӹ���� �� ���
					if (max < 100 - i)   //���̰� �� ��� 
						max = 100 - i;
			}
			
			for (int cen = 0; cen < i + 1; cen++) {//i�� 1�� ��� 0, 1 // i�� 99�� ��� 0, 1, .. 99 ��ġ���� �˻�
				cnt = 0;
				/* --------------- */

				for (j = 0; j < (100 - i) / 2; j++) { //i�� 1�̸� �Ӹ���� �˻�� 99/2�� �ȴ�. 
													  //if (*((arr + i) + j) != *((arr + i) + n - 1 - j))
					if (arr[cen + j][l] != arr[cen + (100 - i) -1 -j][l]) break;
					else cnt++;
				}
				if (j == (100 - i) / 2)   //�Ӹ���� �� ���
					if (max < 100 - i)    //���̰� �� ��� 
						max = 100 - i;
			}
		}	
	}
	return max;
}
int main()
{
	int T, test_case;
	clock_t start = clock();
	freopen("input.txt", "r", stdin);

	//cin >> T;
	for (test_case = 0; test_case < 10; test_case++)
	{
		Answer = 0;
		int n;
		scanf("%d", &n);

		int tmp;

		for (int i = 0; i < 100; i++) {
			scanf("%s\n", arr[i]);
		}

		Answer = isPalindrome(arr);
		cout <<"#"<<n<<' '<<Answer << endl;
	}
	printf("%0.5f\n", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}