#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����� ������ ������ ���� �׽�Ʈ ���̽����� ����� ���� �״�� ���� ������. 
//int size_L[100] = { 0 };
//int size_R[100] = { 0 };
int desti = 0;
//int visited[100] = { 0 }; // 1~98
int bfs(int n,int size_L[],int size_R[])
{
	//static int desti = 0; //�̰� ���� ������ �����ϴ�, TestCase ���� ���� ������ ����.
	 //�׷��ٰ� ���� ������ �ƴϸ� �Լ� �б⸦ Ż ������ �ʱ�ȭ�� �ȴ�...���� ��� ��� �����ϴµ�... �̸� ���� �ذ� �ұ�..

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
	return desti == 1 ? 1:0; // �� �������� desti���� 1�̸� 1 ��ȯ ����
	//���߿� 1 ��ȯ �Ǿ ��� ����. ��¥�� ���α׷� ���� �Ǵϱ�.
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
		desti = 0; //desti�� ���� ������ ������ ����, �Լ� �б⸦ Ÿ�� ���� �Ⱥ��ϰ� �ѵ�, 
		//�׽�Ʈ ���̽��� ������ ���� �ʱ�ȭ �� �־���. 
		printf("#%d ", T);
		printf("%d\n", Answer);

		/////////////////////////////////////////////////////////////////////////////////////////////////
	}



	return 0;

}
