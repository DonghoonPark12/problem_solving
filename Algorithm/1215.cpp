#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

int Answer;

char tmp[100];
char arr[100][100];
int isPalindrome(char arr[][100]) {
	int l;
	int i, j;//여기에 선언해야 i,j를 for문 밖에서도 사용할 수 있다. 
	int max = 0;
	int cnt = 0;//회문 갯수를 측정하던 변수에서 회문 길이를 측정하는 변수로 바뀜
	for (l = 0; l < 100; l++) {
		for (i = 0; i<100; i++) {
			if (max > 100 - i) break;
			for (int cen = 0; cen < i + 1; cen++) {//i가 1일 결우 0, 1 // i가 99일 경우 0, 1, .. 99 위치에서 검사
				cnt = 0;
				/* --------------- */

				for (j = 0; j < (100 - i) / 2; j++) { //i가 1이면 팰린드롬 검사는 99/2가 된다. 
				//if (*((arr + i) + j) != *((arr + i) + n - 1 - j))
					if (arr[l][cen + j] != arr[l][cen + (100 - i) - 1 - j]) break;
				}
				if (j == (100 - i) / 2)  //팰린드롬 일 경우
					if (max < 100 - i)   //길이가 길 경우 
						max = 100 - i;
			}
			
			for (int cen = 0; cen < i + 1; cen++) {//i가 1일 결우 0, 1 // i가 99일 경우 0, 1, .. 99 위치에서 검사
				cnt = 0;
				/* --------------- */

				for (j = 0; j < (100 - i) / 2; j++) { //i가 1이면 팰린드롬 검사는 99/2가 된다. 
													  //if (*((arr + i) + j) != *((arr + i) + n - 1 - j))
					if (arr[cen + j][l] != arr[cen + (100 - i) -1 -j][l]) break;
					else cnt++;
				}
				if (j == (100 - i) / 2)   //팰린드롬 일 경우
					if (max < 100 - i)    //길이가 길 경우 
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