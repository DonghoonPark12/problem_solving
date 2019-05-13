#define	_CRT_SECURE_NO_WARNINGS
#include  <string>
#include  <iostream>
#define max(x,y) ((x) < (y) ? (y) : (x))
using namespace std;
int D[1111][1111];

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	string A, B;
	cin >> A >> B;

	D[0][0] = (A[0] == B[0]);
	for (int i = 1; i < A.length(); ++i)
		D[i][0] = max(D[i - 1][0], (A[i] == B[0]));
	for (int i = 1; i < B.length(); ++i)
		D[0][i] = max(D[0][i - 1], (A[0] == B[i]));
	for (int i = 1; i < A.length(); ++i)
	{
		for (int j = 1; j < B.length(); ++j)
		{
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
		}
	}

	cout << D[A.length() - 1][B.length() - 1] << endl;
	
	string LCS = "";
	int i = A.length() - 1;  int j = B.length() - 1; //6 6
	while (D[i][j] != 0) {
		if ((D[i - 1][j] == D[i][j] - 1) && (D[i][j - 1] == D[i][j] - 1)) { //둘다 만족시키면
			LCS += A[i];//D[i][j];
			i--; j--;
			if (i == 0 || j == 0) { //별로다. 
				LCS += A[i];
				break;
			}
		}
		else if (D[i - 1][j] >= D[i][j-1]) { //위의 것이 더크다.
			i--;
		}
		else if (D[i - 1][j] < D[i][j - 1]) {
			j--;
		}
	}

	string reversed_string = LCS; //복사생성자 호출
	reverse(reversed_string.begin(), reversed_string.end());
	cout << reversed_string << endl;;
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//int Max(int a, int b) { return a > b ? a : b; }
//int main(void)
//{
//	int Answer = 0;
//	freopen("input.txt", "r", stdin);
//	int LCS[100][100] = { 0 }; // <------------------------- 1001, 1001로 하니 왜 에러가 생기는지 모르겠다. 
//
//	string s1, s2;
//	cin >> s1; cin >> s2;
//
//	for (int i = 1; i <= s1.length(); i++) {
//		for (int j = 1; j <= s2.length(); j++) {
//			if (j == 1) LCS[i][j] = LCS[i - 1][j]; //첫번째 열 값은 바로 위의 행에서 가져온다.
//
//			if ((s1[i-1] == s2[j-1]) && (LCS[i][j-1] < i) ) //현재 열보다 숫자가 클 순 없다. 
//				LCS[i][j] = LCS[i-1][j-1] + 1;                
//			else LCS[i][j] = Max(LCS[i][j - 1], LCS[i-1][j]);
//		}
//	}
//	cout << LCS[s1.length()][s2.length()];
//	return 0;
//}