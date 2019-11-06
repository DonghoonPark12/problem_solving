#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//여기다 선언해 버리면 그전 테스트 케이스에서 저장된 값이 그대로 사용되 버린다. 
//int size_L[100] = { 0 };
//int size_R[100] = { 0 };
int desti = 0;
//int visited[100] = { 0 }; // 1~98
int bfs(int n,int size_L[],int size_R[])
{
	//static int desti = 0; //이걸 정적 변수로 선언하니, TestCase 마다 값이 동일해 진다.
	 //그렇다고 정적 변수가 아니면 함수 분기를 탈 때마다 초기화가 된다...값을 계속 들고 가야하는데... 이를 어찌 해결 할까..

	if (n == 99) desti=1;

	//if (visited[n] == 0 && size_L[n] != 0)
	if (size_L[n] != 0)
	{
		//visited[n] = 1;
		bfs(size_L[n], size_L, size_R);
	}
	//if (visited[n] == 0 && size_R[n] != 0)
	if (size_R[n] != 0)
	{
		//visited[n] = 1;
		bfs(size_R[n], size_L, size_R);
	}
	//visited[n] = 0;
	return desti == 1 ? 1:0; // 맨 마지막에 desti값이 1이면 1 반환 역할
	//도중에 1 반환 되어도 상관 없다. 어짜피 프로그램 종료 되니까.
}


int main(void)
{
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);


	for (test_case = 0; test_case < 10; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int Answer = 0;
		int n;
		scanf("%d ", &T);
		scanf("%d\n", &n);
		int size_L[100] = { 0 };
		int size_R[100] = { 0 };
		

		for (int i = 0; i < n; i++)
		{
			int idx;
			scanf("%d ", &idx); //0 //1 //4

			int data; 
			scanf("%d ", &data); //1 //2 //3
			if (size_L[idx] == 0) 
			{
				size_L[idx] = data; //1 //3
				}
			else
			{
				size_R[idx] = data; //2 //4
			}
		}
		Answer = bfs(0, size_L, size_R);
		desti = 0; //desti를 전역 변수로 선언해 놓고, 함수 분기를 타도 값이 안변하게 한뒤, 
		//테스트 케이스가 끝나면 값을 초기화 해 주었다. 
		printf("#%d ", T);
		printf("%d\n", Answer);

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}



	return 0;

}
