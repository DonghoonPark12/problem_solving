#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string str;
	int sum = 0;
	int num;

	//getline(cin, str);
	//number = stoi(str);

	//while (getline(cin, str, ','))//','(������) �ձ��� str�� �ִ´�.
	//	sum += stoi(str);         // �������� ������ �����ϰ�(!!) ���� ���ڿ� ���´�. 
	//printf("%d\n", sum);
	
	while(scanf("%d", &num) != -1) //scanf�� ������ ���� ���� ���� ��ŭ Return
		sum += num;				   // EOF�̸� -1 �����ϳ� ����. 
	 printf("%d\n", sum);          // EOF(-1)�� �ƴϸ� �� �Է� �޴� ���п� 10,20,30,50,110 �� �Է� ���� 
								   // while(~scanf("%d",&num)) Ȥ�� while(scanf("%d", &num) != EOF )
	 return 0;
}

//#include <stdio.h>
//char s[110];
//int k, r;
//int main() {
//	scanf("%s", s);
//	for (int i = 0; s[i]; i++)
//		if (s[i] == ',') r += k, k = 0;
//		else k = 10 * k + s[i] - '0'; //���ڴ� �������� '0'��ŭ ���� ũ��. 
//
//	printf("%d", r + k);
//	return 0;
//}