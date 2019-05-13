/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
// -30000 <= x, y <= 30000  x, y �� int(2^32 or -2^16 +1 ~ 2^16)���� Ŀ�� ����. ��, Char ���� ���� �ȵȴ�.
// x,y ���� �׷��� ũ�� �־��� ���� �ֳİ�?? Ȥ�� �𸥴�. 10^-3 M ������ �׽�Ʈ ���̽��� ���� ���� ������

//double atan2(double y, double x);

struct polar //�� ��ǥ ����ü ����
{
	float R;
	float rad; // 0 ~ 2^64 or -2^32 + 1 ~ 2^32
};

struct polar XYtoPOLAR(int x, int y) //����ü�� ��ȯ�ϴ� �Լ�
{
	//Rrad* temp = (Rrad*)malloc(sizeof(Rrad) * N); s
	struct polar temp; //temp��� R�� rad�� ���� ������ ������ ����ü ����.

	temp.R = sqrt(x*x + y*y);
	temp.rad = atan2(y, x); //double�� ���� �� ��ȯ
	
	return temp;
}

int main(void)
{
	int T, test_case;

	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	 freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		float pi = 3.141593; //�Ҽ��� 15�ڸ� ���� ǥ�� ���� �ϴ���.
		int Answer = 0; // ���� �ʱ�ȭ�Ͽ� �� �׽�Ʈ ���̽� ���� �ٽ� ���
		int	r1, r2, r3, r4, r5;
		int x, y;
		int n;//�߻� ����
		scanf("%d %d %d %d %d", &r1, &r2, &r3, &r4, &r5);
		scanf("%d", &n);
		/////////////////////////////////////////////////////////////////////////////////////////////
		struct polar str; // ����ü ����
		
		printf("%f", (float)(5 * pi / 20)); 
		printf("%f", (float)(7 * pi / 20));
		for (int i = 0; i < n; i++)
		{
			int score = 0;//�� �� ���� �� ���� ����ϱ� ���� ����
			
			scanf("%d", &x); scanf("%d", &y); //
			str = XYtoPOLAR(x, y); //

			/* BULL + Rad ���� ���� ī��Ʈ */
				if (str.R > r5) 
			{
				score = 0;
			} //����� ���� OUT, �׻� �� ���� ��Ȳ�� �� �켱������ �Ÿ� �� �ֵ��� ����. 
			else if (str.R < r1)
			{
				score = 50;
			} //BULL�� �ֿ켱 ������ �ξ���. �׷��� ������ ���ǹ��� (BULL������ �ƴ� ���)������ ���� �Ǵ�.
			else if ( -(float)pi/20 < str.rad < (float)pi/20 )//-0.15 ~ 0.15
			{
				score = 6;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if ( (float)pi / 20 < str.rad < 3 * (float)pi / 20)
			{
				score = 13;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (3 * (float)pi / 20 < str.rad < 5 * (float)pi / 20) // 0.47 ~ 0.78
			{
				score = 4;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if ((float)(5 * pi / 20) < str.rad < (float)(7 * pi / 20)) //0.78 ~ 1.09
			{
				score = 18;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (7 * (float)(pi / 20) < str.rad < 9 * (float)(pi / 20))
			{
				score = 1;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (9 * (float)pi / 20 < str.rad < 11 * (float)pi / 20)
			{
				score = 20;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (11 * (float)pi / 20 < str.rad < 13 * (float)pi / 20)
			{
				score = 5;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (13 * (float)pi / 20 < str.rad < 15 * (float)pi / 20)
			{
				score = 12;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (15 * (float)pi / 20 < str.rad < 17 * (float)pi / 20)
			{
				score = 9;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (17 * (float)pi / 20 < str.rad < 19 * (float)pi / 20)
			{
				score = 14;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if ((19 * (float)pi / 20 < str.rad <  (float)pi) || (-(float)pi < str.rad < -19 * (float)pi/20))
			{
				score = 11;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (-19 * (float)pi / 20 < str.rad < -17 * (float)pi / 20)
			{
				score = 8;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (-17 * (float)pi / 20 < str.rad < -15 * (float)pi / 20)
			{
				score = 16;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (-15 * (float)pi / 20 < str.rad < -13 * (float)pi / 20)
			{
				score = 7;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (-13 * (float)pi / 20 < str.rad < -11 * (float)pi / 20)
			{
				score = 19;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (-11 * (float)pi / 20 < str.rad < -9 * (float)pi / 20)
			{
				score = 3;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (-9 * (float)pi / 20 < str.rad < -7 * (float)pi / 20)
			{
				score = 17;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else if (-7 * (float)pi / 20 < str.rad < -5 * (float)pi / 20)
			{
				score = 2;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
			}
			else if (-5 * (float)pi / 20 < str.rad < -3 * (float)pi / 20)
			{
				score = 15;
				if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 3; }
			}
			else 
			{
				if (-3 * (float)pi / 20 < str.rad < -(float)pi / 20)
				{
					score = 10;
					if ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) { score *= 2; }
				}
			}
			
			/* ���� ��� ������ ��� */
			/*
			if ( (( 0 < str.rad < (float)pi / 20) || (39 * (float)pi / 20 < str.rad < 40 * (float)pi / 20) || (3* (float)pi / 20 <= str.rad <=5* (float)pi / 20)|| (7* (float)pi / 20 <= str.rad <=9* (float)pi / 20)|| (11* (float)pi / 20 <= str.rad <=13* (float)pi / 20)|| (15* (float)pi / 20 <= str.rad <=17* (float)pi / 20)||
				(19*(float)pi / 20 <= str.rad <=21* (float)pi / 20)|| (23* (float)pi / 20 <= str.rad <=25* (float)pi / 20)|| (27* (float)pi / 20 <= str.rad <=29* (float)pi / 20)|| (31* (float)pi / 20 <= str.rad <=33* (float)pi / 20)|| (35* (float)pi / 20 <= str.rad <=37* (float)pi / 20) )
				&& ((r2 <= str.R <= r3) || (r4 <= str.R <= r5)) )
			{
				score *= 2;
			}
			else if ( ( ((float)pi / 20 <= str.rad <=2* (float)pi / 20) || (4* (float)pi / 20 <= str.rad <=6* (float)pi / 20) || (8* (float)pi / 20 <= str.rad <=10* (float)pi / 20) || (12* (float)pi / 20 <= str.rad <=14* (float)pi / 20) || (16* (float)pi / 20 <= str.rad <=18* (float)pi / 20) ||
				(20* (float)pi / 20 <= str.rad <=22* (float)pi / 20) || (24* (float)pi / 20 <= str.rad <=26* (float)pi / 20) || (28* (float)pi / 20 <= str.rad <=30* (float)pi / 20) || (32* (float)pi / 20 <= str.rad <=34* (float)pi / 20) || (36* (float)pi / 20 <= str.rad <=38* (float)pi / 20))
				&& ((r2 <= str.R <= r3) || (r4 <= str.R <= r5) ) )
			{
				score *= 3;
			}
			else
			{
				score *= 1;
			}
			*/
			Answer += score;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}