/* 문자열을 자르는 함수 */

#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h> 

int main()
{
	char s1[30] = "The Little Prince";
	//strtok(대상 문자열 + 기준 문자)

	char *ptr = strtok(s1, " "); //" " 직전 까지 문자열 자르고, 문자열의 주소를 포인터에 저장
	// strtok 함수는 잘린 문자열을 한번에 얻을 수 없어서 while 반복문으로 문자열을 계속 자르다가
	// 문자열이 나오지 않으면 반복문 종료.

	while (ptr != NULL)
	{
		printf("%s", ptr);//자른 문자열 출력
		// NULL을 넣으면 직전에 처리했던 (문자열 + 기준문자)이후로 이동한 뒤 주소 반환, L을 가리킨다. 
		// 총 4칸 이동
		ptr = strtok(NULL, " ");// 다음 문자열을 잘라서 포인터 반환. 왜 NULL이 들어가야 하는지 와닿지는 않지만.
		// '그다음 문자열을 출력하기 위한 방법' 일단 이렇게 이해하도록 하자. 
		// strtok 함수는 공백을 NULL문자로 바꾸기 때문에 기존 문자열을 변형하므로 조심해서 사용하도록 한다.
		// 마지막 단계에서는 기준 문자가 아닌 Prince + NULL문자가 존재.
		// (Prince + NULL문자)이후로 이동하면 ptr은 NULL을 가리킨다고 확신할 수 있나??? While문의 종료 조건으로 쓸 수 있나??
		// 이 부분도 이해가 되지 않지만, 기준문자(" ")대신 NULL이 왔으니 이때는 전체 문자열의 마지막까지만 가리키도록 ptr이 이동하나 보다
	}
}