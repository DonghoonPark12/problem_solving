#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 입력 : X, Y
* 출력: X에서 (+1이상)을 하여 y에 도달할 수 있는 최소 단계
* 조건: 처음과 마지막 단계는 +1이어야 한다.
*
* (예제)
* ((입력) X:45, Y:50
* 45 46 48 49 50 -> (출력: 4)
*
* (입력) X:45, Y:49
* 45 46 48 49 (출력: 3)
*
* (입력) X:45, Y:48
* 45 46 47 48 (출력: 3)
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