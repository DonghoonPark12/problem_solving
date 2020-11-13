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
	[False] �߰��� break�ؾ� ���� ������ (y,x)�� �������� �˻��� �� �ִ�.
		--> ���� for������ �� for���� ���� �����Ƿ� �ǹ̾���.
	[False] 2�� for�� �ۿ��� -1 �ѹ��� �˻��Ѵ�.
		-> ������ -1�Ǿ� �ִ� ���� ���� �������´�
	[True]
		-> ��¿�� ����. �߰� y,x ���� ���� �ξ� �����Ѵ�.
	*/

	if (ord >= 5)
	{
		bin_total += check_row(y, x); //y
		bin_total += check_col(y, x); //x

		/*
		[Insight]
		���� �̻� �׾����� �����̹Ƿ�, �˻� ������ �ѷ� ������� �Ѵ�. 
		���� ����( (2.2) ����) �� �ִٸ�, �ι� �� �˻��ϰ� �Ѵ�. 

		����, ���� �ߴ� ���� ���� �� �� �־�� �ϹǷ� ���������� �δ� �� �´�.
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