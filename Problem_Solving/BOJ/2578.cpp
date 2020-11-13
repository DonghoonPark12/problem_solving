#include <cstdio>
#include <iostream>
using namespace std;

int bingo[5][5];
int bin_total = 0;

int check_row(int y, int x)
{
	int bin = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[y][i] != -1) {
			bin = 0; break;
		}
	}
	return bin;
}
int check_col(int y, int x)
{
	int bin = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][x] != -1) {
			bin = 0; break;
		}
	}
	return bin;
}
int check_diag_down(int y, int x)
{
	int bin = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i] != -1){
			bin = 0; break;
		}
	}
	return bin;
}

int check_diag_up(int y, int x)
{
	int bin = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4 - i] != -1) {
			bin = 0; break;
		}
	}
	return bin;
}

int bingo_check(int num, int ord)
{
	int y, x;
	for (int i = 0; i < 5; i++)	{
		for (int j = 0; j < 5; j++)		{
			if (bingo[i][j] == num) {
				bingo[i][j] = -1;  y = i; x = j;
			}
		}
	}
	/*
	[False] 중간에 break해야 멈춘 지점의 (y,x)을 기준으로 검사할 수 있다.
		--> 이중 for문에서 한 for문만 빠져 나오므로 의미없다.
	[False] 2차 for문 밖에서 -1 한번더 검사한다.
		-> 기존에 -1되어 있는 것을 보고 빠져나온다
	[True]
		-> 어쩔수 없다. 중간 y,x 따로 변수 두어 저장한다.
	*/

	if (ord >= 5)
	{
		bin_total += check_row(y, x); //y
		bin_total += check_col(y, x); //x

		/*
		[Insight]
		세번 이상 그어지는 순간이므로, 검사 조건을 둘로 나누어야 한다. 
		따라서 중점( (2.2) 지점) 에 있다면, 두번 다 검사하게 한다. 

		또한, 줄을 긋는 경우는 누적 될 수 있어야 하므로 전역변수로 두는 게 맞다.
		*/
		if(y == x)
			bin_total += check_diag_down(y, x);
		if ((y + x) == 4)
			bin_total += check_diag_up(y, x);
	}
	return bin_total;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> bingo[i][j];
		}
	}
	int num;
	int cnt = 0;
	for(int i=1; i<=25; i++)
	{
		scanf("%d ", &num);
		bingo_check(num, i);
		cnt++;
		if (bin_total >= 3)
			break;
	}
	cout << cnt;
	return 0;
}