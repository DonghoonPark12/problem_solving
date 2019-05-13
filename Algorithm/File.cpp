/*
* 형식화 된 입,출력
* 정수나 실수 데이터는 화면에 문자열로 변환되어 출력되는 것 처럼
* 파일에서도 문자열로 바꾸어서 저장하는 것이 보통.
* ex) 정수 10은 문자열 "10"으로 출력 되듯이, 파일에서도 "10"으로 저장시키는 것.
* 형식화된 입출력은 fscanf(), fprintf() 이용
*/

/*
* 쓰기모드로 작업 수행을 하고, 읽기 모드로 작업을 시작하기 전에 파일을 종료 시킨다.
* fprintf는 출력의 대상이 화면이 아니고, 파일. 파일에 출력이 된다. (저장 역할)
* fprintf는 문자열로 변환한 후(서식화 한 후) 파일에 쓴다.
* 1 2 3 4 5 6 -> '1','2','3','4','5','6' 
*
* fscanf는 파일에서 (문자로 변환 된)숫자를 읽어 숫자로 변환한다. 
* '1','2','3','4','5','6' -> 1 2 3 4 5 6
*/

/*
* 이진 파일은 데이터가 직접 저장되어 있는 파일.
* 1 2 3 4 5 6 -> 이진수 형태로 그대로 파일에 기록
* 문자 데이터가 아니므로, 모니터나 프린터로 출력이 불가능. 대신, 저장공간이 적다.
* 
* 텍스트 파일은 아스키 코드로 되어 있기 때문에(?) 이식성이 좋다. 다른 컴퓨터에서 읽을 수 있다.
* 반면, 이진 파일은 정수, 실수 데이터를 표현하는 방식이 컴퓨터 시스템 마다 다르기 때문에 이식성 떨어진다.
* 이식성 중요하다면 텍스트 파일로, 데이터가 많고 실행 속도가 중요하다면 이진 파일로 한다. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	printf("성적 파일 이름을 입력하시오: ");
	scanf("%s", fname);

	/* 성적 파일을 쓰기 모드로 연다 */
	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (1)
	{
		printf("학번, 이름, 성적을 입력하시오: (음수이면 종료)");
		scanf("%d", &number);
		if (number < 0) break;
		scanf("%s %f", name, &score);//이름, 점수 저장
		fprintf(fp, "%d %s %f\n", number, name, score); // 이건 뭘까
		// 출력의 대상이 화면이 아닌, 파일!!!
		// 문자열로 변환된 후 파일에 쓰인다.
	}
	fclose(fp);

	/* 읽기 모드 */
	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr,"성적 파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}

	/* end of file이 아닌 조건에서는 계속 수행 */
	while (!feof(fp))
	{
		fscanf(fp, "%d, %s, %f", &number, name, &score);
		// 입력의 대상이 사용자가 아닌 파일!!!
		// 파일에서 숫자를 읽을 때, 파일의 문자를 읽어서 숫자로 변환한다. 
		total += score;
		count++;
	}

	printf(" 평균: %f\n", total / count);
	fclose(fp);
	
	return 0;
}


