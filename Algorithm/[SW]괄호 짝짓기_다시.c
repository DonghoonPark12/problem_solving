#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define stack_size 300
int top = -1;

int f(char c, char d)
{
	if ((d=='(' && c ==')') || (d == '[' && c == ']') || (d == '{' && c == '}') || (d == '<' && c == '>'))
		return 1;
	else
		return 0;
}

int main(void)
{

	int n;//��ȣ ����

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	char op[stack_size] = { 0 };
	char op_stack[stack_size] = {0};
	
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		scanf("%d\n", &n);
		scanf("%s\n", op); // < { [ ] < > } >
		// < ] { [ ] < > } >

		int i = 0;
		int top = 0;

		//scanf("%1c", &op_stack[top]);
		op_stack[i] = op[i]; // <
		if (op_stack[i] == ')' || op_stack[i] == '}' || op_stack[i] == '>' || op_stack[i] == ']') //ó�� ���� �ݴ� ��ȣ�� �����ϸ�(ó���� �ѹ��� ����)
		{
			printf("#%d 0\n", test_case);
			continue; //�ٷ� ���α׷� ����
		}
		i++;
		top++;
		while (op[i] != '\0')
		{
			//if (op_stack[top] == '(' || op_stack[top] == '{' || op_stack[top] == '<' || op_stack[top] == '[')//���� ��ȣ �̸�,
			if (op[i] == '(' || op[i] == '{' || op[i] == '<' || op[i] == '[')//���� ��ȣ �̸�,
			{
				op_stack[top] = op[i]; // 
				i++; // �״������� �̵�
				top++;
			}
			else //���� ��ȣ�̸�
			{
				//������ ���� ��ȣ�� ���� �ߴ��� ����
				if (f(op[i], op_stack[top - 1]) == 1)
					top--;
				else
				{
					break;
				}
				i++;
			}
		}

		if (top != 0) //��ȣ�� ���Ҵٸ�
			printf("#%d 0\n", test_case);
		else
			printf("#%d 1\n", test_case);


	}
	return 0;

}

