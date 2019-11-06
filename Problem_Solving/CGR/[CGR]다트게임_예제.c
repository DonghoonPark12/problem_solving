// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC, A, B, C, D, E, N;
	int test_case, i, score, tmp, x, y;
	double pos, angle;
	int dart[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };//내가 0~18도를 6으로 보니
	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		//read dart
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

		//calculate distance & angle
		scanf("%d", &N);
		score = 0;
		for (i = 0; i<N; i++) {
			scanf("%d %d", &x, &y);
			pos = x*x + y*y; //반지름이 
			angle = atan2(y, x); //-pi  ~  pi
			angle = angle * (double)180 / 3.14159265358979 + 9; // 나온 각도에서 9도를 더해줘야 배열과 순서가 맞다.

			if (angle < 0) angle += 360; // 0 ~ 180+9 ~ 360

			if (E*E < pos) { //OUT OF BOARD
							 //printf("%d : added  0\n", i);
			}
			else if (pos < A*A) { //BULL
								  //printf("%d : added 50\n", i);
				score += 50;
			}
			else {
				tmp = dart[(int)(angle / 18)]; // 18로 나눈 몫에만 관심이 있다. 정수가 올라가면 그다음 칸이겠지.
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

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, score);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}