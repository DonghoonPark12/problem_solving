#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//scanf의 리턴값: 성공적으로 입력 받은 인자 갯수
//따라서, 파일 끝까지 입력 받아야 하는 경우에는 
//while(scanf("%d %d", &a, &b) == 2)와 같이 사용할 수 있다.
//scanf는 공백과 줄바꿈은 무시한다. 
//%c 입력 받는건 주의. 공백, 줄바꿈도 문자.
int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
//nt T, test_case;
//scanf("%d", &T);
	int a, b;
	int n;
	/*
	while (scanf("%d %d\n", &a, &b) == 2)
	{
			printf("%d", a + b);

	}
	*/
	/*
	while (1)
	{
		scanf("%d %d", &a, &b);
		printf("%d", a + b);
	}
	*/
	//scanf("%d", &n);

	/*
	입력
	3
	A B C
	D E F
	G H I
	*/
	/*
	scanf("%d\n", &n); //개행문자(10)을 같이 받음으로써, x가 개행문자를 받지 않도록 한다. 
	while (n--)
	{
		char x, y, z;
		scanf("%c %c %c\n", &x, &y, &z);
		printf("%d %d %d\n", x, y, z);
	}
	*/
	scanf("%d", &n);  
	while (n--)
	{
		char x, y, z;
		scanf(" %c %c %c", &x, &y, &z); //혹은 개행 문자를 무시하려면 앞에 빈칸' '을 두는 방법도 많이 사용된다. 
		printf("%d %d %d\n", x, y, z);
	}
	return 0;
}
