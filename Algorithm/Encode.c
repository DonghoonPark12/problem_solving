#include <stdio.h>
//매크로 선언은 헤더파일에 
int main()
{
	int key;
	char *str;

	// 8bits 끼리 연산할 것.
	printf("키 값을 입력하시오: ");
	scanf("%d", &key);

	printf("암호화할 값을 입력 하시오: ");
	scanf("%s", str);

	printf("%s: ", str);
	while (*str != NULL) //Encoding
	{
		XOR_BIT(*str, key); //8bits씩 순차적으로 XOR 연산 된다.
		str++;
	}

	printf("%s로 엔코딩 됨\n", str);

	printf("%s: ", str);
	while (*str != NULL) // 다시 수행하면 Decoding이 되는 걸까
	{
		XOR_BIT(*str, key); //8bits씩 순차적으로 XOR 연산 된다.
		str++;
	}

	printf("%s로 디코딩 됨\n", str);

	return 0;

}