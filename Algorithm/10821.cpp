#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string s;
	//getline(cin, s);
	char c;
	int cnt = 0;

	while ((c = getchar()) != EOF) { // while( ~(c = getchar()) ) 
		if(c == ',')
			cnt++;
	}
	printf("%d", cnt+1);
	return	0;
}

#include<cstdio>
int r = 1;
char c;
int main() {
	while ((scanf("%c", &c)) != 0) //���ڰ� �ƴ� ���� ������ 0 ��ȯ.    
		r += (c == ',');           //���ڰ� ��� ���� �� ��� ����. 
	printf("%d", r);
	
	//printf("%d", EOF);  // -1
	//printf("%d", ~(-1));// 0
	//printf("%d", ~(0)); // -1	
	//printf("%d", ~(1)); // -2
	return 0;
}
// �׷� while (!scanf("%c", &c))�� �� �ȵɱ�.
// ���ڰ� ������ !1 �� 0�� �ǹǷ� while�� ���� �����Ƿ� �������� �ʴ�. 

// while ( ~(scanf("%c", &c)) )�� �� �Ǵ� ���ϱ�...

#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int cnt = 0;
	while (getline(cin, s, ',')) { // getline�� ����° ���ڴ� ������
		cnt += 1;
	}
	cout << cnt << '\n';
	return 0;
}