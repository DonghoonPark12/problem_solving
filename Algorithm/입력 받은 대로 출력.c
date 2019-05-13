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
	/* 
	입력
	Hello
	Baekjoon
	Online Judge
	*/
	char str[100];
	/*
	while (scanf("%[^\n]\n", str) == 1) 
	{
		printf("%s\n", str);
	}
	//줄바꿈을 입력 받지 않아, 뒤에 개행문자 붙여준다.
	//따라서, 빈줄을 입력 받을 수 없다. 
	//또, 공백으로 시작하는 경우 공백을 무시하고 문자부터 입력 받게 된다. 
	*/
	/*
	입력
		Hello

	Baekjoon
			Online Judge
	*/
	/*
	char c;

	while ((c = getchar()) && c != EOF)
	{
		printf("%c", c);
	}
	printf("\n");
	*/

	/*
	입력
	5
	12345
	*/
	/*
	int n;
	int sum = 0;
	int x;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%1d", &x);
		sum += x;
	}
	printf("%d\n", sum);
	*/

	//%s의 경우도 개수를 지정해서 입력 받을 수 있다. 
	//입력 받을 수 있는 갯수가 지정한 개수보다 적으면 그만큼 입력 받는다. 
	char a[100];
	while (scanf("%10s", a) == 1) // 
	{
		printf("%s\n", a);
	}

	/* 원치 않는 값은 입력 받지 않을 때 */
	int x, y;
	scanf("%d %*d %d", &x, &y);
	printf("%d %d\n", x, y);
	return 0;
}