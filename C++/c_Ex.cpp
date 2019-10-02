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
	//printf("빛의 속도는 %fkm/s \n", light_speed);
	//printf("지구와 태양사이 거리 %fkm \n", distance);
	//printf("도달 시간은 %d분 %1f초 \n", min, sec);

	//int color = 0x00380000;
	//int red = color & 0x00ff0000;
	//red = red >> 16;

	//printf("픽셀의 색상: %#08x\n", color);
	//printf("추출된 빨간색: %#08x\n", red);

	//float round_earth = (360) / 7.2 * 900;
	//printf("지구 전체 둘레 길이: %fkm \n", round_earth);//약 45000.00km
	//float radius = round_earth / (2*3.141592) ;
	//printf("지구 반지름: %fkm \n", radius);//약 7161.974121km

	//char a, b, c, d;
	//unsigned int res = 0x00000000;//32bit
	//printf("첫번째 문자: ");
	//scanf(" %c", &a);//2bit
	//res = res | a; 

	//printf("두번째 문자: ");
	//scanf(" %c", &b);
	////b = 'b';
	//res = res | b << 8;

	//printf("세번째 문자: ");
	//scanf(" %c", &c);
	////c = 'c';
	//res = res | c << 16;

	//printf("네번째 문자: ");
	//scanf(" %c", &d);
	////d = 'd';
	//res = res | d << 24;
	//
	////printf("%d", res);

	//printf("결과 값: %#x", res);

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