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

	int n;//괄호 갯수

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
		if (op_stack[i] == ')' || op_stack[i] == '}' || op_stack[i] == '>' || op_stack[i] == ']') //처음 부터 닫는 괄호가 등장하면(처음에 한번만 조사)
		{
			printf("#%d 0\n", test_case);
			continue; //바로 프로그램 종료
		}
		i++;
		top++;
		while (op[i] != '\0')
		{
			//if (op_stack[top] == '(' || op_stack[top] == '{' || op_stack[top] == '<' || op_stack[top] == '[')//여는 괄호 이면,
			if (op[i] == '(' || op[i] == '{' || op[i] == '<' || op[i] == '[')//여는 괄호 이면,
			{
				op_stack[top] = op[i]; // 
				i++; // 그다음으로 이동
				top++;
			}
			else //닫힌 괄호이면
			{
				//이전에 여는 괄호가 존재 했는지 조사
				if (f(op[i], op_stack[top - 1]) == 1)
					top--;
				else
				{
					break;
				}
				i++;
			}
		}

		if (top != 0) //괄호가 남았다면
			printf("#%d 0\n", test_case);
		else
			printf("#%d 1\n", test_case);


	}
	return 0;

}

