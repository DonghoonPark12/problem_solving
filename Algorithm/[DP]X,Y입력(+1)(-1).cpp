#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* �Է� : X, Y
* ���: X���� (+1�̻�)�� �Ͽ� y�� ������ �� �ִ� �ּ� �ܰ�
* ����: ó���� ������ �ܰ�� +1�̾�� �Ѵ�.
*
* (����)
* ((�Է�) X:45, Y:50
* 45 46 48 49 50 -> (���: 4)
*
* (�Է�) X:45, Y:49
* 45 46 48 49 (���: 3)
*
* (�Է�) X:45, Y:48
* 45 46 47 48 (���: 3)
*/
int cnt = 0;
int flag = 0;
int f(int num, int a)
{
	if (num == 0)
	{
		if (a != 1)
			return 0;
		else
			flag = 1;
	}
	
	return cnt;
}

int main(void)
{
	int x, y;
	int Answer = 0;
	
	scanf("%d %d\n", &x, &y);

	//printf("%d\n", f(x, y));
	printf("%d\n", f(y-x,1));
	return 0;
}