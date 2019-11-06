#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//https://jongnan.tistory.com/entry/SW-Expert-5644-%EB%AC%B4%EC%84%A0-%EC%B6%A9%EC%A0%84
class AP {
public:
	int x;
	int y;
	int c;
	int p;
};
int M, A;
//방향은 5개, 0일때가 추가됨.
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

//해당 위치에서 A,B의 파워 검색
int checkPoint(vector<AP> APs, int ax, int ay, int bx, int by) {
	//먼저 A,B가 전파를 받을 수 있는 곳에 충전 가능한 정도를 저장.
	vector<int> possibleA(A, 0);
	vector<int> possibleB(A, 0);

	for (int i = 0; i < A; i++) {
		int distA = abs(APs[i].x - ax) + abs(APs[i].y - ay);
		int distB = abs(APs[i].x - bx) + abs(APs[i].y - by);
		if (distA <= APs[i].c) possibleA[i] = APs[i].p;
		if (distB <= APs[i].c) possibleB[i] = APs[i].p;
	}
	//구해야 할 것은 해당 시간에서 A,B가 받을 수 있는 충전량을 모두 더하는 것.
	//따라서 미리 해당 시간에서 최대치를 저장해둔다.
	//만약 i == j 즉, 같은 AP에서 충전을 받을 경우 합계는 한개 값과 같다.(어차피 나누기하여 더해도 하나의 값)
	//또한 같은 위치에 있는 모든 수를 비교해야하므로 A가 클지 B가 클지 모르므로 다 비교.
	//같지 안을때는 무조건 더해서 비교하므로 나누기 2를하고 곱하기 2를 하고를 생각할 필요가 없음.
	int sum = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (i == j) {
				sum = _max(sum, possibleA[i]);
				sum = _max(sum, possibleB[i]);
			}
			else {
				sum = _max(sum, possibleA[i] + possibleB[j]);
			}
		}
	}
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> A;
		vector<int> routeA;
		vector<int> routeB;
		for (int i = 0; i < M; i++) {
			int a;
			cin >> a;
			routeA.push_back(a);
		}
		for (int i = 0; i < M; i++) {
			int a;
			cin >> a;
			routeB.push_back(a);
		}
		vector<AP> APs;
		for (int i = 0; i < A; i++) {
			AP ap;
			cin >> ap.x >> ap.y >> ap.c >> ap.p;
			APs.push_back(ap);
		}
		//초기 위치에서도 확인을 해야한다.
		int ax = 1, ay = 1;
		int bx = 10, by = 10;
		int ans = checkPoint(APs, ax, ay, bx, by);
		//그 후에 A,B의 경로를 따라 매번 확인해 주며, 제일 큰 값이 리턴되므로 계속해서 더해준다.
		for (int i = 0; i < M; i++) {
			ax += dx[routeA[i]];
			ay += dy[routeA[i]];
			bx += dx[routeB[i]];
			by += dy[routeB[i]];
			ans += checkPoint(APs, ax, ay, bx, by);
		}
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}

//#define	_CRT_SECURE_NO_WARNINGS
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//int dx[5] = { 0, 0, 1, 0, -1 };
//int dy[5] = { 0, -1, 0, 1, 0 };
//int main(void)
//{
//	int T, test_case;
//	int Answer = 0;
//	freopen("input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int A_x = 1; int A_y = 1;
//		int B_x = 10; int B_y = 10;
//		int M, bc;
//		cin >> M >> bc;
//		//vector<int> A(M);
//		//vector<int> B(M);
//		//for (int i = 0; i < M; i++) { cin >> A[i]; }
//		//for (int i = 0; i < M; i++) { cin >> B[i]; }
//		vector<int> A(M+1, 0);//21개 이동. 첫번째는 제자리
//		vector<int> B(M+1, 0);//index는 0 ~ 20
//		for (int i = 1; i <= M; i++) { cin >> A[i]; }
//		for (int i = 1; i <= M; i++) { cin >> B[i]; }
//
//		vector<vector<int>> BC(bc, vector<int>(4));
//		for (int i = 0; i < bc; i++) {
//			cin >> BC[i][0] >> BC[i][1] >> BC[i][2] >> BC[i][3];
//		}
//		//BC[0][0] : 4, BC[0][1] : 4, BC[0][2] : c1, BC[0][3] : p1
//		//BC[1][2] : c2, BC[1][3] : p2
//		/*
//			//A, B 둘다 1충전기 안에 들어오는지.
//			if (abs(A_x - BC[0][0]) +  abs(A_y - BC[0][1])) < BC[0][2] )
//				sum_A += BC[i][3];
//				cnt++;
//
//		    if (abs(B_x - BC[0][1]) + abs(B_y - BC[0][1])) < BC[0][2] )
//				sum_B += BC[i][3];
//				cnt+;
//
//			if(cnt==2)
//				sum = (sum_A + sum_B)/2
//
//			(abs(A_x - BC[1][0]) +  abs(A_y - BC[1][1])) < BC[1][2]
//			(abs(B_x - BC[1][1]) + abs(B_y - BC[1][1])) < BC[1][2] 
//			
//			sum_A += BC[i][3];
//			sum_B += BC[i][3];
//
//		*/
//		int sum_A = 0; int sum_B = 0; int sum_total = 0;
//		int cnt = 0;
//		for (int i = 0; i <= M; i++) {// 하...BS 처음 위치에서도 충전을 할 수 있으므로 i=0(이동 안할 때
//			vector<int> a(bc, 0), b(bc, 0);
//			for (int j = 0; j < bc; j++) {
//				if ((abs(A_x - BC[j][0]) + abs(A_y - BC[j][1])) <= BC[j][2]) {
//					//sum_A += BC[j][3];
//					//cnt++;
//					a[j] = BC[j][3];
//				}
//
//				if ((abs(B_x - BC[j][0]) + abs(B_y - BC[j][1])) <= BC[j][2]) {
//					//sum_B += BC[j][3];
//					//cnt++;
//					b[j] = BC[j][3];
//				}
//
//				//if (cnt == 2)
//				//	sum_total = sum_A/2 + sum_B/2;
//				//else
//				//	sum_total = sum_A + sum_B;
//			}
//			int sum = 0;
//			for (int k = 0; k < bc; k++) {
//				for (int l = 0; l < bc; l++) {
//					if (k == l) {
//						sum = _max(sum, a[k]);
//						sum = _max(sum, b[k]);
//					}
//					else
//						sum = _max(sum, a[k] + b[l]);
//				}
//			}
//
//			sum_total += sum;
//
//			A_x += dx[A[i]]; A_y += dy[A[i]];
//			B_x += dx[B[i]]; B_y += dy[B[i]];
//
//		}
//
//		printf("#%d ", test_case + 1);
//		printf("%d\n", sum_total);
//	}
//
//	return 0;
//
//}

//5644 - 무선충전
//https://charm-charm.postype.com/post/3437982
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define ABS(x) (x > 0 ? (x) : -(x))
//using namespace std;
//bool desc(pair<int, int> a, pair<int, int> b) {
//	return a > b;
//}
//typedef struct AP {
//	int x, y, c, p;
//}AP;
//
//int dx[5] = { 0,-1,0,1,0 };//정지,상,우,하,좌
//int dy[5] = { 0,0,1,0,-1 };//정지,상,우,하,좌
//
//AP ap[8];//충전기
//int M, A, move_A[100], move_B[100], x, y, c, p;
//int map[11][11] = { 0 };
//int eng = 0;
//int ax = 1, ay = 1;
//int bx = 10, by = 10;
//vector<pair<int, int>> v1, v2;
//
//void check(int ax, int ay, int bx, int by) {
//	for (int i = 0; i < A; i++) {//A,B에 대해 모든 충전기 검사
//		int dist_A = ABS(ax - ap[i].x) + ABS(ay - ap[i].y);
//		int dist_B = ABS(bx - ap[i].x) + ABS(by - ap[i].y);
//		if (dist_A <= ap[i].c) {
//			v1.push_back(make_pair(ap[i].p, i));
//		}
//		if (dist_B <= ap[i].c) {
//			v2.push_back(make_pair(ap[i].p, i));
//		}
//	}
//	sort(v1.begin(), v1.end(), desc);
//	sort(v2.begin(), v2.end(), desc);
//	if (v1.empty() && v2.empty()) return;//둘 다 0개
//	else if (v1.empty()) { eng += v2.front().first; return; }//A가 0개 B가 1개 이상
//	else if (v2.empty()) { eng += v1.front().first; return; }//A가 1개 이상 B가 0개
//	else {
//		if (v1.front() == v2.front()) {//최댓값이 같을 때, 같은 충전기에 충전될 때. 
//			if (v1.size() == 1 && v2.size() == 1) {// A가 1개, B가 1개씩만 겹치면. 
//				eng += v1.front().first;	
//			}
//			else if (v1.size() == 1) {//A가 1개, B가 2개 이상 겹칠때 
//				eng += v1[0].first;
//				eng += v2[1].first;
//			}
//			else if (v2.size() == 1) {//B가 1개, A가 2개 이상 겹칠때 
//				eng += v1[1].first;
//				eng += v2[0].first;
//			}
//			else {//A가 2개 이상, B가 2개 이상 겹칠때 : 둘다 겹치는 것을 가지고(가장 큰 충전량) + 둘중에 큰 것을 가진다.  
//				if (v1.front().second == v2.front().second) {
//					eng += v1.front().first;
//					eng += _max(v1[1].first, v2[1].first);
//				}
//			}
//		}
//		else {//최댓값이 다를 때, 둘다 다른 충전기에 충전될 때.
//			eng += v1.front().first;
//			eng += v2.front().first;
//		}
//	}
//}
//
//void move(int za, int zb) {
//	ax += dx[za];
//	ay += dy[za];
//	bx += dx[zb];
//	by += dy[zb];
//}
//
//int main(int argc, char** argv)
//{
//	freopen("input.txt", "r", stdin);
//	int test_case;
//	int T;
//	//freopen("iofile\\input.txt", "r", stdin);
//	//freopen("iofile\\output.txt", "w", stdout);
//	cin >> T;
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		ax = 1, ay = 1, bx = 10, by = 10;
//		eng = 0;
//		//이동시간, 충전기갯수
//		cin >> M >> A;
//
//		//이동정보
//		for (int i = 0; i < M; i++) {
//			cin >> move_A[i];
//		}
//		for (int i = 0; i < M; i++) {
//			cin >> move_B[i];
//		}
//
//		//충전기 정보
//		for (int j = 0; j < A; j++) {
//			cin >> x >> y >> c >> p;
//			ap[j] = { y,x,c,p };
//		}
//		for (int i = 0; i <= M; i++) {
//			check(ax, ay, bx, by);
//			v1.clear();
//			v2.clear();
//			move(move_A[i], move_B[i]);
//		}
//		cout << "#" << test_case << ' ' << eng << '\n';
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}