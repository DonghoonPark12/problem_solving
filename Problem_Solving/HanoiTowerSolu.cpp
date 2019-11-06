#include <iostream>

void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1)
		printf("원반 마지막 1개를 %c에서 %c로 이동\n", from, to);
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d개 %c에서 %c로 이동\n",num-1, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main() {
	//막대A, 막대B, 막대C
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}