#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

char str[16] = { 0 }; //���!
int arr[16][16] = { 0 };
int visited[16][16] = { 0 };
int flag = 0;
int dfs(int x,int y)
{
	int temp = 0;
	if (arr[x][y] == 1 || visited[x][y] == 1) 
		return 0; //���̰ų�, �湮 �ߴٸ� ���α׷� ����. 

	else if (arr[x][y] == 3){
		return 1; //������ �����ϴٸ� flag '1'
	}
	else{//�湮 ���� �ʾҴٸ�, �湮 �� '1'
		visited[x][y] = 1;
		//return 0;
		temp += dfs(x, y + 1);// ��+1 ��� ��ͷ� �ϸ� ������ �ʹ� ���δ�. 
		temp += dfs(x + 1, y);// ��+1
		temp += dfs(x, y - 1);// ��-1
		temp += dfs(x - 1, y);// ��-1

		visited[x][y] = 0;

		return temp;
		//return flag;
	}
}


int main() 
{	
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int n, Ans;
	for(int tc=0; tc<10; tc++)
	{
		//arr[16][16] = { 0 };
		//visited[16][16] = { 0 };
		for (int i = 0; i < 16; i++){
			for (int j = 0; j < 16; j++){
				arr[i][j] = 0;
				visited[i][j] = 0;
			}
		}


		flag = 0;
		scanf("%d", &n);
		for (int i = 0; i < 16; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = str[j] - '0'; //���!
			}
		}

		if (dfs(1, 1))
			Ans = 1;
		else
			Ans = 0;
		printf("#%d %d\n", tc + 1, Ans);


	}

	return 0;
}
