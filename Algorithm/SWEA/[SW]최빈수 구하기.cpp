#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>

int arr[101]; //0점 부터 ~ 100점까지

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);


	for(int tc=0;tc<10;tc++)
	{
		int n;
		scanf("%d", &n);
		int tmp = 0;
		//int Ans = 0;

		for (int i = 0; i <= 100; i++) 	arr[i] = 0;//배열 초기화

		for (int i = 0; i < 1000; i++)
		{
			scanf(" %d", &tmp); //41을 받으면
			arr[tmp]++;//받은 숫자의 인덱스를 ++
		}

		int max = 0;//가장 많이 나타난 수가 몇번 나타났는지
		int idx = 0;//가장 많이 나타난 수가 어느 번째에 위치 하는지
		for (int i = 0; i <= 100; i++)
		{
			//인덱스가 같지만, 숫자가 더 크면 최빈수
			if (arr[i] >= max) {//가 가장 크면 최빈수
				max = arr[i];
				idx = i;
			}
		}

		printf("#%d %d\n", n, idx);
	}

	return 0;
}



//최빈수가 여러개일 경우 가장 큰 점수 출력