#include <stdio.h>

typedef struct point
{
	int x;
	int y;
}POINT;

/*
POINT func()
{
	POINT s = { 10,10 }; //����ü ����
	
	return s;
}
*/
/*
POINT *func() //C������ �Լ� �����ε� ��� ���� �����Ƿ� ���� func() �Լ� �ּ� ó��
{			  //"��ȯ �������θ� ���еǴ� �Լ��� �����ε� �� �� �����ϴ�."
	static POINT s = { 10,10 };

	return &s; 
	//�Լ��� ������ ����ü ������ �������.
	//���� �ּ� �����ڷ� ����ü ������ �޸� �ּҸ� ��ȯ�ϸ� �ȵǴµ�... ���� �� ������??
}
*/
POINT *func()
{
	POINT *s = malloc(sizeof(POINT));//���� �޸� �Ҵ�

	s->x = 10;
	s->y = 10;
	
	return s; 
	//����ü �������� �ּҸ� ��ȯ
}

void main()
{
   //POINT p1;
	POINT *p1;

	p1 = func(); //��ȯ�� ����ü ���� ����ü p1�� ����.

	printf("%d %d\n", p1->x, p1->y);
}