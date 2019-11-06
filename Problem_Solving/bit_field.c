/* Chap.15 ��ó�� �� ��Ʈ�ʵ� */
/* ��������5��, 6��, 7��, 8�� */
/* Unsigned : 3 - unsigned �ڷ����� 32 ��Ʈ�� ǥ�� �ǰ� �� �� 3 ��Ʈ�� ����ϰڴٴ� ��. 
���� ��Ʈ���� ���������� ����. ��ǻ�Ϳ� ����Ǵ� �ϵ���� ���� �޸� �ּҿ� ���εǴ� �ϵ���� ��Ʈ�� �̿��ϴ� ��찡 ���⿡
�ϵ���� ��ġ���� ��Ʈ ������ �����ϵ��� �Ǿ� �ִ�. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SET_BIT(n,pos) ( (n) |= (1 << pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� 1�� ����. 
#define CLR_BIT(n,pos) ( (n) &= (~1<< pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� 0���� ����.
#define GET_BIT(n,pos) ( (n) & (1 << pos) ) //���� n �ȿ� �ִ� pos ��° ��Ʈ�� ��ȯ

#define SET_BIT_OFF(n,pos)  ( n &= ~(1<<pos) )
#define XOR_BIT(n,pos) ( n ^= ( 1 << pos) )
#define GET_BIT2(n,pos) ( ( n >> pos ) & 1 )

#define IS_SPACE(c)	((c == '\t') || (c == ' ') || (c == '\n')) // {}�� ���δ� ������ ����.   

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
	/* 5�� */
	/*
	int i = 0;
	int cnt = 0;
	char sen[100];
	//char *ptr;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(sen);
	//ptr = &sen[0];
	
	while ( sen[i] != 0 ) // NULL(0)�� �ϰų� '\0'
	{
		if ( IS_SPACE(sen[i]) )
		{
			cnt++;
		}
		i++;
	}

	printf("���� ������ ������ %d�� �Դϴ�.\n", cnt);
	*/

	/* 6�� Ȯ�� */
	/*
	int data = 0;
	int value = 0;

	SET_BIT(data,2);
	printf("%08X\n",data); // 8�ڸ� 16���� ����  00 00 00 04 
	display_bit(data); printf("\n");// 00000000 00000000 00000000 00000100

	// printf("%d\n",GET_BIT(data,2)); // 00000100 ^ 00000100 �ϸ� 4�� ���� ������.
	value = GET_BIT2(data, 2);
	printf("%d\n",value);   //���ϰ��� �ϴ� �ڸ��� ��ŭ LSB�� �о 1�� ���Ѵ�.
	display_bit(data);printf("\n"); //GET_BIT�� ������ ���� �������� �ʴ´�. 

	CLR_BIT(data, 2); // &= (11111111 11111111 11111111 11111011)
	display_bit(data); printf("\n");

	printf("%d\n",SET_BIT_OFF(data,2)); // 32bit���� 4��° ��Ʈ��  &= ~(1<<pos) : &= ~(00000000 00000000 00000000 00000100)
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

	/* 8�� */
	/*
	int n,sel,sel_num;
	
	printf("���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	printf("\n���� �̵��� 0, ������ �̵��� 1�� �Է��Ͻÿ�: ");
	scanf("%d", &sel);
	printf("\n�̵���ų �Ÿ�: ");
	scanf("%d", &sel_num);

	printf("\n�̵� ��: ");
	display_bit(n); //10�� ������ ��Ʈ ���꿡 ���� 2������ ����ȴ�.
	
	if (sel == 0)
		n = n * two_square(sel_num);
	else
		n = n / two_square(sel_num);

	printf("\n�̵� ��: ");
	display_bit(n);
	*/

	/* 9�� */
	/*
	int i = 0;
	char sen[100];

	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", sen);

	while (sen[i] != '\0')
	{
		XOR_BIT(sen[i], 5); //8bits�� 00100000�� ����Ǿ 6��° bit�� �ٲ��.
		i++;
	}

	printf("��� ���ڿ�: %s\n", sen);
	*/
	/* 10�� */
	int i = 0;
	int key=200;
	char sen[100];

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(sen);

	//scanf("%s\n",sen); // �̷��� �ϴ� I am a boy ���� I �ۿ� �Է��� �ȵǾ���. 
//	printf("Ű ���� �Է��Ͻÿ�: ");
//	scanf("%c", &key); // 8bits
	//	fflush(stdin);

	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char�� ���� XOR ���� ��, 8bits�� �Ѳ����� XOR ����ȴ�.
		i++;
	}
	printf("%s�� ���ڵ� ��\n", sen);

	i = 0;
	while (sen[i] != '\0')
	{
		sen[i] ^= key; //char�� ���� XOR ���� ��, 8bits�� �Ѳ����� XOR ����ȴ�.
		i++;
	}
	printf("%s�� ���ڵ� ��\n", sen);

	return 0;
}




void display_bit(int value) // ���� ���� �޾Ƽ� (32bit)2���� ���·� ����ϴ� �Լ�.
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if (GET_BIT(value, i)) //���� n �ȿ� �ִ� i��° ��Ʈ�� ��ȯ
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