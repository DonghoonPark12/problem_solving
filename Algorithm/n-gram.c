/* n-gram은 문자열에서 N개의 연속된 요소(Charater든 Token이든)를 추출하는 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	//char text[30] = "Hello";
	//int length;

	//length = strlen(text);

	/* 글자 단위 */
	/*
	// 2-gram 
	for (int i = 0; i < length - 1; i++)
	{
		printf("%c%c\n", text[i], text[i + 1]);
	}

	// 3-gram 
	for (int i = 0; i < length - 2; i++)
	{
		printf("%c%c%c\n", text[i], text[i + 1], text[i + 2]);
	}
	*/

	/* 단어 단위 */
	char text[100] = "This is C language";
	char *tokens[30] = { NULL, }; // 자른 문자열의 포인터를 보관할 배열
	int count = 0;

	char *ptr = strtok(text, " "); // text문자열을 자름. 공백 문자를 기분으로 

	while (ptr != NULL) // NULL이 나오지 않을 때 까지 반복
	{
		tokens[count] = ptr; // 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장 

		count++; //총 Token의 갯수 만큼 카운트 

		ptr = strtok(NULL, " "); //  다음 문자열을 잘라서 포인터 반환 
		// 문자열의 인덱스를 다루는 방법만 신경쓰면 된다.
	}

	// 2-gram이므로 배열의 마지막에서 요소 한 개 앞까지만 반복함
	for (int i = 0; i < count - 1; i++)
	{
		printf("%s %s\n", tokens[i], tokens[i + 1]);    // 현재 문자열과 그다음 문자열 출력(배열에는 토큰을 가리키는 포인터 주소가 저장)
	}

	/* Palindrom 판별 */


	return 0;
}