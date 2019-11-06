#include <ctime>
#include <cstdlib>
#include <vector>

class Word
{

};

int main()
{
	int ans;
	vector<Word> v;
	v.push_back('human');
	v.push_back('society');
	v.push_back('dall');
	v.push_back('emotion');
	v.pus_back('painting');
	v.push_back('trade');

	srand((unsigned)time(0));
	int n = rand(); // 0 ~ 32767

	a = v.size(); //참조 변수

	printf("영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다.");
	while (1)
	{
		printf("%s?\n", v.at());
		printf("(1) %s (2) %s (3) %s (4) %s :>\n", );//정답을 포함, 램덤한 단어 출력

		scanf("%d", &ans);
		if (ans != 1 || ans != 2 || ans != 3 || ans != 4)
		{
			break;
		}
		else if (ans = )//입력한 번호와 나온 단어의 인덱스가 일치하면
		{
			printf("Excellent !!");
		}
		else
		{
			printf("No. !!");
		}
	}

	return 0;

}