#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/* ���� ��ģ ��
* 1. ���๮�ڵ� ���ڷ� ��޵ȴ�.
* �ƽ�Ű�� 10����:10, 16����:0x0A
* ���� ������ ������ �־�������, ���� �Է��� ������ ������ �������� ������ �ȴ�. 
* ���๮�� \n�� ���ڷ� ��޵ȴٴ� ���� ������ ���� ���ڿ��� �ϳ��� �޾Ҵ�.
* ������, EOF���� ���ڷ� �����ϰ� �����ϸ�...
* while (scanf("%c", &c) != EOF) Ȥ�� while (~(c = getchar())) 
* while�� �ϳ��� Ǯ �� �ִ�. 

* 2. EOF�� ���ڰ� �ƴϴ�. -1��.
* ���Ϸ� �˻��ϴ� �¶��� �˻�� ������ �׽�Ʈ ���̽� ���� (���ڰ� �ƴ�)EOF�� �ٴ´�. 
* �㳪, ���� ���� �ڵ�� EOF�Է��� (��������)��ٸ���. �׷��� ��ٸ���. ���� �´�.

* 3. !�� �� ������,  ~�� ��Ʈ ������ 
* while ( !(c = getchar()) ) �� ����. 
* (���� ����) while ( !** ) �̸� **�� ������ ���� �ȴ�. 
* 
* while ( (c = getchar()) != EOF ) ��, ���� �������� �ƴ� �� ���� ���ڸ� ��� �Է� �޴°� ���.
* while (~(c = getchar()) ) �̰� �� �����ұ�......
* 
*/

int main() {
	string s;
	int S, D, N, B;
	int i;
	while (getline(cin, s)) { //ǥ�� �� ������� ����
		//S = 0, D = 0, N = 0, B = 0;
		S = D = N = B = 0;
		i = 0;
		while (s[i]) {  
			if (s[i]>='a' && s[i]<='z') //�ҹ���
				S++;
			else if (s[i]>='A' && s[i]<='Z')//�빮��
				D++;
			else if (s[i]>='0' && s[i]<='9')//����
				N++;
			else
				B++;
			i++;
		}
		printf("%d %d %d %d\n", S, D, N, B);
	}
	return 0;
}

// ��Ű
// C ǥ�� ���̺귯������ getchar�� ���� ���� �Է� �Լ��� ������ ���� �������� �˸��� ����
// ��ũ�η� ���ǵ� EOF ���� �����Ѵ�. 
// EOF�� ���� ���� �ý��ۿ� ���� �ٸ��� (�׷��� ���� -1�� ���ǵȴ�) 
// ��� ��ȿ�� ������ ������ ��ġ�� �ʴ´�. 

#include <cstdio> // �����ڵ� 
int a, A, n, s;
char c;
int main() {
	  while( (c = getchar()) != EOF ) {   // while ( ~(c = getchar()) ) 
		if (c >= 'a' && c <= 'z') a++;
		if (c >= 'A' && c <= 'Z') A++;
		if (c >= '0' && c <= '9') n++;
		if (c == ' ') s++;
		if (c == '\n') printf("%d %d %d %d\n", a, A, n, s), a = A = n = s = 0;
	}
	return 0;
}


#include <stdio.h>
int main()
{
	char lineFeed = '\n';    // ���� ���� \n �Ҵ�
	printf("%d %c 0x%x\n", lineFeed, lineFeed, lineFeed);    // 10 0xa: ���� ������ ASCII �ڵ� ���
	return 0;
}
// 10 (�� �ٲ� ���ڸ� %c�� ����ϸ� �ٹٲ��� �ȴ�.)
// 0xa 


//#include <stdio.h> // getchar()����
//
//int main()
//{
//	int c;
//	puts("Enter text. Include a dot ('.') in a sentence to exit:");
//	do {
//		c = getchar();
//		putchar(c); //��ħǥ ���� �Էµǰ� do ~ while() �̶� 
//	} while (c != '.'); //�ԷµǸ� ���� 
//	return 0;
//}
	
