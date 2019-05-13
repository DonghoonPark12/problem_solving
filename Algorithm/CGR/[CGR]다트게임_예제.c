// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC, A, B, C, D, E, N;
	int test_case, i, score, tmp, x, y;
	double pos, angle;
	int dart[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };//���� 0~18���� 6���� ����
	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		//read dart
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

		//calculate distance & angle
		scanf("%d", &N);
		score = 0;
		for (i = 0; i<N; i++) {
			scanf("%d %d", &x, &y);
			pos = x*x + y*y; //�������� 
			angle = atan2(y, x); //-pi  ~  pi
			angle = angle * (double)180 / 3.14159265358979 + 9; // ���� �������� 9���� ������� �迭�� ������ �´�.

			if (angle < 0) angle += 360; // 0 ~ 180+9 ~ 360

			if (E*E < pos) { //OUT OF BOARD
							 //printf("%d : added  0\n", i);
			}
			else if (pos < A*A) { //BULL
								  //printf("%d : added 50\n", i);
				score += 50;
			}
			else {
				tmp = dart[(int)(angle / 18)]; // 18�� ���� �򿡸� ������ �ִ�. ������ �ö󰡸� �״��� ĭ�̰���.
				//multiple score
				if (B*B < pos && pos < C*C) { //TRIPLE
					score += tmp * 3;
					//printf("%d : added %2d\n", i, tmp*3);
					continue;
				}
				else if (D*D < pos && pos < E*E) { //DOUBLE
					score += tmp * 2;
					//printf("%d : added %2d\n", i, tmp*2);
					continue;
				}
				score += tmp;
				//printf("%d : added %2d\n", i, tmp);
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, score);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}