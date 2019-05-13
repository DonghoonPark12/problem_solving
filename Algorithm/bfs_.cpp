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

// 하지만 하노이의 탑과 같은 알고리즘이 등장하면 숨이 막히기 시작한다.
// 꼬리재귀(tail recursion)가 왜 효율적인지, 일반적인 재귀 알고리즘을 어떻게 꼬리재귀 알고리즘으로 변환할 수 있는지 등을
// 이야기하다보면 한계를 느낀다.이런 사람들은 개발자가 되어서 실전에 배치되어도 
// 운영체제의 루프백(loopback) 주소라는 개념을 이해하지 못해서 애를 먹는다.재귀라는 알고리즘의 작동방식이 머릿속에서 그려지지 않는 탓이다.