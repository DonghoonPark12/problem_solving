#include <iostream>
#include <string>
using namespace std;
//int main(void)
//{
//	char str[100];
//	while (scanf("%[^\n]\n", str) == 1)
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}

int main() {
	freopen("input.txt", "r", stdin);
	char a;
	while(a!=-1){ //È¤Àº a!=EOF
		putchar(a);
		a = getchar();
	}
	return 0;
}
