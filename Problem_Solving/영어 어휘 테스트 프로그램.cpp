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

	a = v.size(); //���� ����

	printf("���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� �����մϴ�.");
	while (1)
	{
		printf("%s?\n", v.at());
		printf("(1) %s (2) %s (3) %s (4) %s :>\n", );//������ ����, ������ �ܾ� ���

		scanf("%d", &ans);
		if (ans != 1 || ans != 2 || ans != 3 || ans != 4)
		{
			break;
		}
		else if (ans = )//�Է��� ��ȣ�� ���� �ܾ��� �ε����� ��ġ�ϸ�
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