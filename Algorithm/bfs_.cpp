int bfs(int n, int size_L[], int size_R[])
{
	int result = (size_L[n] == 99 || size_R[n] == 99);

	if (result) return 1;
	if (size_L[n]> 0)
		result = Tree(size_L[n], size_R[n]);

	if (result == 1) return 1;
	if (size_R[n]> 0)
		result = Tree(size_R[n], size_L, size_R);

	return result == 1 ? 1 : 0;
}

// ������ �ϳ����� ž�� ���� �˰����� �����ϸ� ���� ������ �����Ѵ�.
// �������(tail recursion)�� �� ȿ��������, �Ϲ����� ��� �˰����� ��� ������� �˰������� ��ȯ�� �� �ִ��� ����
// �̾߱��ϴٺ��� �Ѱ踦 ������.�̷� ������� �����ڰ� �Ǿ ������ ��ġ�Ǿ 
// �ü���� ������(loopback) �ּҶ�� ������ �������� ���ؼ� �ָ� �Դ´�.��Ͷ�� �˰����� �۵������ �Ӹ��ӿ��� �׷����� �ʴ� ſ�̴�.