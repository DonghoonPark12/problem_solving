#include <iostream>
int main() {
	//double light_speed = 300000;//300000km/s
	//double distance = 149600000; //149600000km
	//double time;

	//time = distance / light_speed;
	//time /= 60;
	////printf("%f\n", time);
	//int min = int(time);
	//double sec = (time - min)*60;
	//printf("���� �ӵ��� %fkm/s \n", light_speed);
	//printf("������ �¾���� �Ÿ� %fkm \n", distance);
	//printf("���� �ð��� %d�� %1f�� \n", min, sec);

	//int color = 0x00380000;
	//int red = color & 0x00ff0000;
	//red = red >> 16;

	//printf("�ȼ��� ����: %#08x\n", color);
	//printf("����� ������: %#08x\n", red);

	//float round_earth = (360) / 7.2 * 900;
	//printf("���� ��ü �ѷ� ����: %fkm \n", round_earth);//�� 45000.00km
	//float radius = round_earth / (2*3.141592) ;
	//printf("���� ������: %fkm \n", radius);//�� 7161.974121km

	//char a, b, c, d;
	//unsigned int res = 0x00000000;//32bit
	//printf("ù��° ����: ");
	//scanf(" %c", &a);//2bit
	//res = res | a; 

	//printf("�ι�° ����: ");
	//scanf(" %c", &b);
	////b = 'b';
	//res = res | b << 8;

	//printf("����° ����: ");
	//scanf(" %c", &c);
	////c = 'c';
	//res = res | c << 16;

	//printf("�׹�° ����: ");
	//scanf(" %c", &d);
	////d = 'd';
	//res = res | d << 24;
	//
	////printf("%d", res);

	//printf("��� ��: %#x", res);

	//7
	int a, b, c;
	for (a = 1; a <= 100; a++) {
		for (b = 1; b <= 100; b++) {
			for (c = 1; c <= 100; c++) {
				if ((a*a + b*b) == c*c)
					printf("%d %d %d \n", a, b, c);
			}
		}
	}
	return 0;
}