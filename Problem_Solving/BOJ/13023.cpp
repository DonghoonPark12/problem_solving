#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
	//ABCDE

	//Ʋ�� ����
	dfs�� (0,1,2,3)���� ����Ͽ� (1,2,3,4)�� ���� �ִ��� �ľ��ؾ� �Ǵ� ����.
	0���� ����Ͽ� 1�� �� �� �ִ���, 
	1���� ����Ͽ� 2�� �� �� �ִ���,
	2���� ����Ͽ� 3�� �� �� �ִ���,
	3���� ����Ͽ� 4�� �� �� �ִ��� Ȯ������.

	//�������� ���ϴ� ��
	��� �������� ����ص� ��� ������ �湮���� ���� ������ �̾ ���̰� 5�� �� �� �ִ��� ���� ����.
	��Ʈ��ŷ ������� �̷� ã��� �ؼ� ���� 5�̻� ��� �� �� �ִ��� Ȯ���Ѵ�.

	�׷��� dfs : visited Ȯ���� for���� ��(for�� �ۿ�).
	�׷��� ��Ʈ��ŷ : visited Ȯ�� for�� ��/��.
*/
vector<int> node[2000];
bool visited[2000];
int n, m;
int possible;
void dfs(int s, int cnt) {
	if (cnt == 4) {
		possible = 1;
		return;
	}
	visited[s] = true;            //�׷������� dfs�� for�� �� ��/�ڿ� visited Ȯ���� �Ѵ�. �迭�� ��Ʈ��ŷ�� for�� �ȿ� visited ǥ�ø� �Ѵ�.(1181�� �κ� ������ �� ����)
	for (int i = 0; i < node[s].size(); i++) {
		int next = node[s][i];    //���� ����, �����δ� �迭 ó�� ������ �� �ִ�.
		if (!visited[next]) {     //�湮���� �ʾҴٸ�
			dfs(next, cnt+1);
			if (possible) return; //�̺κ��� �ð��� ���� �������ش�.
		}
	}
	visited[s] = false;
}
int main() {
	cin >> n >> m;
	
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		node[v1].push_back(v2);
		node[v2].push_back(v1);
	}

	for (int i = 0; i < n; i++) { //��� �������� ���� �����ؼ� ���̰� 5��
		//memset(visited, false, sizeof(visited));//��Ʈ��ŷ ��Ŀ����� visited �ʱ�ȭ ���� �ʿ� ����. 
		dfs(i, 0);
		if (possible) break;
	}
	cout << possible;
	return 0;
}