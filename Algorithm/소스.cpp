#include <stdio.h>

int main()
{
	char *str;
	int cnt = 0;

	printf("문자열을 입력하시오: ");
	gets("%s", str);

	while (*str != Null)
	{
		if (*str == 47)
			cnt++;
	}

	printf("공백 문자의 개수는 %d개 입니다.", cnt);

	return 0;
}