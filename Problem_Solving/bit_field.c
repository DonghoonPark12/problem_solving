/* Chap.15 전처리 및 비트필드 */
/* 연습문제5번, 6번, 7번, 8번 */
/* Unsigned : 3 - unsigned 자료형이 32 비트로 표현 되고 그 중 3 비트를 사용하겠다는 뜻. 
하위 비트에서 순차적으로 저장. 컴퓨터에 연결되는 하드웨어 들은 메모리 주소에 매핑되는 하드웨어 포트를 이용하는 경우가 많기에
하드웨어 장치들은 비트 단위로 제어하도록 되어 있다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SET_BIT(n,pos) ( (n) |= (1 << pos) ) //변수 n 안에 있는 pos 번째 비트를 1로 설정. 
#define CLR_BIT(n,pos) ( (n) &= (~1<< pos) ) //변수 n 안에 있는 pos 번째 비트를 0으로 설정.
#define GET_BIT(n,pos) ( (n) & (1 << pos) ) //변수 n 안에 있는 pos 번째 비트를 반환

#define SET_BIT_OFF(n,pos)  ( n &= ~(1<<pos) )
#define XOR_BIT(n,pos) ( n ^= ( 1 << pos) )
#define GET_BIT2(n,pos) ( ( n >> pos ) & 1 )

#define IS_SPACE(c)	((c == '\t') || (c == ' ') || (c == '\n')) // {}로 감싸니 에러가 떴다.   

struct product {
	unsigned style : 3;
	unsigned size : 2;
	unsigned color : 1;
};

struct bit_char {
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
	unsigned char bit8 : 1;
};

void display_bit(int value);
int two_square(int value);

int main(void)
{ 
	/* 5번 */
	/*
	int i = 0;
	int cnt = 0;
	char sen[100];
	//char *ptr;

	printf("문자열을 입력하시오: ");
	gets(sen);
	//ptr = &sen[0];
	
	while ( sen[i] != 0 ) // NULL(0)을 하거나 '\0'
	{
		if ( IS_SPACE(sen[i]) )
		{
			cnt++;
		}
		i++;
	}

	printf("공백 문자의 개수는 %d개 입니다.\n", cnt);
	*/

	/* 6번 확인 */
	/*
	int data = 0;
	int value = 0;

	SET_BIT(data,2);
	printf("%08X\n",data); // 8자리 16진수 형태  00 00 00 04 
	display_bit(data); printf("\n");// 00000000 00000000 00000000 00000100

	// printf("%d\n",GET_BIT(data,2)); // 00000100 ^ 00000100 하면 4가 나와 버린다.
	value = GET_BIT2(data, 2);
	printf("%d\n",value);   //구하고자 하는 자리수 만큼 LSB로 밀어서 1과 곱한다.
	display_bit(data);printf("\n"); //GET_BIT가 데이터 값을 변경하진 않는다. 

	CLR_BIT(data, 2); // &= (11111111 11111111 11111111 11111011)
	display_bit(data); printf("\n");

	printf("%d\n",SET_BIT_OFF(data,2)); // 32bit에서 4번째 비트와  &= ~(1<<pos) : &= ~(00000000 00000000 00000000 00000100)
	display_bit(data); printf("\n");    // 00000000 00000000 00000000 00000000
	*/

	/*
	struct product p1;
	p1.style = 0; //000
	p1.size = 3;  //11
	p1.color = 0; //0

	struct bit_char p2;
	p2.bit1 = 1;

	printf("sizeof(p1)=%d \n", sizeof(p1));
	printf("p1 = %x\n", p1); // cc cc cc(1100 1100) d8(1101 1000)
	
	printf("sizeof(p2)=%d \n", sizeof(p2));
	printf("p2 = %x\n", p2); // cd(1100 1101)
	*/

	/* 8번 */
	/*
	int n,sel,sel_num;
	
	printf("정수 값을 입력하시오: ");
	scanf("%d", &n);
	printf("\n왼쪽 이동은 0, 오른쪽 이동은 1을 입력하시오: ");
	scanf("%d", &sel);
	printf("\n이동시킬 거리: ");
	scanf("%d", &sel_num);

	printf("\n이동 전: ");
	display_bit(n); //10을 넣으면 비트 연산에 의해 2진수로 연산된다.
	
	if (sel == 0)
		n = n * two_square(sel_num);
	else
		n = n / two_square(sel_num);

	printf("\n이동 후: ");
	display_bit(n);
	*/

	/* 9번 */
	/*
	int i = 0;
	char sen[100];

	printf("문자열을 입력하시오: ");
	scanf("%s", sen);

	while (sen[i] != '\0')
	{
		XOR_BIT(sen[i], 5); //8bits가 00100000과 연산되어서 6번째 bit가 바뀐다.
		i++;
	}

	printf("결과 문자열: %s\n", sen);
	*/
	/* 10번 */
	int i = 0;
	int key=200;
	char sen[100];

	printf("문자열을 입력하시오: ");
	gets(sen);

	//scanf("%s\n",sen); // 이렇게 하니 I am a boy 에서 I 밖에 입력이 안되었다. 
//	printf("키 값을 입력하시오: ");
//	scanf("%c", &key); // 8bits
	//	fflush(stdin);

	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char형 끼리 XOR 연산 즉, 8bits가 한꺼번에 XOR 연산된다.
		i++;
	}
	printf("%s로 엔코딩 됨\n", sen);

	i = 0;
	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char형 끼리 XOR 연산 즉, 8bits가 한꺼번에 XOR 연산된다.
		i++;
	}
	printf("%s로 디코딩 됨\n", sen);

	return 0;
}




void display_bit(int value) // 정수 값을 받아서 (32bit)2진수 형태로 출력하는 함수.
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if (GET_BIT(value, i)) //변수 n 안에 있는 i번째 비트를 반환
			printf("1");
		else
			printf("0");
	}
	//printf("\n");

	return;
}

int two_square(int value)
{
	if (value == 0)
		return 1;
	else
		return 2 * two_square(value - 1);
}