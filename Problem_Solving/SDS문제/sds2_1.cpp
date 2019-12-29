#include <iostream>
using namespace std;
int backup[6][3][3];
int rubi[6][3][3] = { {
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
					   },
					  {
						{10,11,12},
						{13,14,15},
						{16,17,18}
					  },
					  {
						{19,20,21},
						{22,23,24},
						{25,26,27}
					  },
					  {
						{28,29,30},
						{31,32,33},
						{34,35,36}
					  },
					  {
						{37,38,39},
						{40,41,42},
						{43,44,45}
					  },
					  {
						{46,47,48},
						{49,50,51},
						{52,53,54}
					  }
};

void rot(int muun, int cnt) {
	int backup[3][3];
	for (int c = 0; c < cnt; c++) {
		//for (int i = 0; i < 3; i++)
		//{
		//	for (int j = 0; j < 3; j++)
		//	{
		//		rubi[muun][i][j] = rubi[muun][3 - j - 1][i];
		//	}
		//}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//rubi[muun][j][2 - i] = rubi[muun][i][j];
				backup[j][2 - i] = rubi[muun][i][j];
			}
		}
		memcpy(rubi[muun], backup, sizeof(rubi[muun]));
	}
}

void solve(int rota) {
	int t1, t2, t3;
	switch (rota) {
	case 1:
		t1 = rubi[0][0][0];
		t2 = rubi[0][1][0];
		t3 = rubi[0][2][0];

		rubi[0][0][0] = rubi[1][0][0];
		rubi[0][1][0] = rubi[1][1][0];
		rubi[0][2][0] = rubi[1][2][0];

		rubi[1][0][0] = rubi[2][0][0];
		rubi[1][1][0] = rubi[2][1][0];
		rubi[1][2][0] = rubi[2][2][0];

		rubi[2][0][0] = rubi[3][0][0];
		rubi[2][1][0] = rubi[3][1][0];
		rubi[2][2][0] = rubi[3][2][0];

		rubi[3][0][0] = t1;
		rubi[3][1][0] = t2;
		rubi[3][2][0] = t3;

		rot(4, 3);
		break;
	case 2:
		t1 = rubi[0][0][1];
		t2 = rubi[0][1][1];
		t3 = rubi[0][2][1];

		rubi[0][0][1] = rubi[1][0][1];
		rubi[0][1][1] = rubi[1][1][1];
		rubi[0][2][1] = rubi[1][2][1];

		rubi[1][0][1] = rubi[2][0][1];
		rubi[1][1][1] = rubi[2][1][1];
		rubi[1][2][1] = rubi[2][2][1];

		rubi[2][0][1] = rubi[3][0][1];
		rubi[2][1][1] = rubi[3][1][1];
		rubi[2][2][1] = rubi[3][2][1];

		rubi[3][0][1] = t1;
		rubi[3][1][1] = t2;
		rubi[3][2][1] = t3;
		break;
	case 3:
		t1 = rubi[0][0][2];
		t2 = rubi[0][1][2];
		t3 = rubi[0][2][2];

		rubi[0][0][2] = rubi[1][0][2];
		rubi[0][1][2] = rubi[1][1][2];
		rubi[0][2][2] = rubi[1][2][2];

		rubi[1][0][2] = rubi[2][0][2];
		rubi[1][1][2] = rubi[2][1][2];
		rubi[1][2][2] = rubi[2][2][2];

		rubi[2][0][2] = rubi[3][0][2];
		rubi[2][1][2] = rubi[3][1][2];
		rubi[2][2][2] = rubi[3][2][2];

		rubi[3][0][2] = t1;
		rubi[3][1][2] = t2;
		rubi[3][2][2] = t3;

		rot(5, 1);
		break;
	case 4:
		t1 = rubi[0][0][0];
		t2 = rubi[0][1][0];
		t3 = rubi[0][2][0];

		rubi[0][0][0] = rubi[3][0][0];
		rubi[0][1][0] = rubi[3][1][0];
		rubi[0][2][0] = rubi[3][2][0];

		rubi[3][0][0] = rubi[2][0][0];
		rubi[3][1][0] = rubi[2][1][0];
		rubi[3][2][0] = rubi[2][2][0];

		rubi[2][0][0] = rubi[1][0][0];
		rubi[2][1][0] = rubi[1][1][0];
		rubi[2][2][0] = rubi[1][2][0];

		rubi[1][0][0] = t1;
		rubi[1][1][0] = t2;
		rubi[1][2][0] = t3;

		rot(4, 1);
		break;
	case 5:
		t1 = rubi[0][0][1];
		t2 = rubi[0][1][1];
		t3 = rubi[0][2][1];

		rubi[0][0][1] = rubi[3][0][1];
		rubi[0][1][1] = rubi[3][1][1];
		rubi[0][2][1] = rubi[3][2][1];

		rubi[3][0][1] = rubi[2][0][1];
		rubi[3][1][1] = rubi[2][1][1];
		rubi[3][2][1] = rubi[2][2][1];

		rubi[2][0][1] = rubi[1][0][1];
		rubi[2][1][1] = rubi[1][1][1];
		rubi[2][2][1] = rubi[1][2][1];

		rubi[1][0][1] = t1;
		rubi[1][1][1] = t2;
		rubi[1][2][1] = t3;
		break;
	case 6:
		t1 = rubi[0][0][2];
		t2 = rubi[0][1][2];
		t3 = rubi[0][2][2];

		rubi[0][0][2] = rubi[3][0][2];
		rubi[0][1][2] = rubi[3][1][2];
		rubi[0][2][2] = rubi[3][2][2];

		rubi[3][0][2] = rubi[2][0][2];
		rubi[3][1][2] = rubi[2][1][2];
		rubi[3][2][2] = rubi[2][2][2];

		rubi[2][0][2] = rubi[1][0][2];
		rubi[2][1][2] = rubi[1][1][2];
		rubi[2][2][2] = rubi[1][2][2];

		rubi[1][0][2] = t1;
		rubi[1][1][2] = t2;
		rubi[1][2][2] = t3;

		rot(5, 3);
		break;
	case 7:
		t1 = rubi[1][0][0];
		t2 = rubi[1][0][1];
		t3 = rubi[1][0][2];

		rubi[1][0][0] = rubi[5][0][0];
		rubi[1][0][1] = rubi[5][0][1];
		rubi[1][0][2] = rubi[5][0][2];

		rubi[5][0][0] = rubi[3][2][2];
		rubi[5][0][1] = rubi[3][2][1];
		rubi[5][0][2] = rubi[3][2][0];

		rubi[3][2][2] = rubi[4][0][0];
		rubi[3][2][1] = rubi[4][0][1];
		rubi[3][2][0] = rubi[4][0][2];

		rubi[4][0][0] = t1;
		rubi[4][0][1] = t2;
		rubi[4][0][2] = t3;

		rot(0, 1);
		break;
	case 8:
		t1 = rubi[1][1][0];
		t2 = rubi[1][1][1];
		t3 = rubi[1][1][2];

		rubi[1][1][0] = rubi[5][1][0];
		rubi[1][1][1] = rubi[5][1][1];
		rubi[1][1][2] = rubi[5][1][2];

		rubi[5][1][0] = rubi[3][1][2];
		rubi[5][1][1] = rubi[3][1][1];
		rubi[5][1][2] = rubi[3][1][0];

		rubi[3][1][2] = rubi[4][1][0];
		rubi[3][1][1] = rubi[4][1][1];
		rubi[3][1][0] = rubi[4][1][2];

		rubi[4][1][0] = t1;
		rubi[4][1][1] = t2;
		rubi[4][1][2] = t3;
		break;
	case 9:
		t1 = rubi[1][2][0];
		t2 = rubi[1][2][1];
		t3 = rubi[1][2][2];

		rubi[1][2][0] = rubi[5][2][0];
		rubi[1][2][1] = rubi[5][2][1];
		rubi[1][2][2] = rubi[5][2][2];

		rubi[5][2][0] = rubi[3][0][2];
		rubi[5][2][1] = rubi[3][0][1];
		rubi[5][2][2] = rubi[3][0][0];

		rubi[3][0][2] = rubi[4][2][0];
		rubi[3][0][1] = rubi[4][2][1];
		rubi[3][0][0] = rubi[4][2][2];

		rubi[4][2][0] = t1;
		rubi[4][2][1] = t2;
		rubi[4][2][2] = t3;
		rot(2, 3);
		break;
	case 10:
		t1 = rubi[1][0][0];
		t2 = rubi[1][0][1];
		t3 = rubi[1][0][2];

		rubi[1][0][0] = rubi[4][0][0];
		rubi[1][0][1] = rubi[4][0][1];
		rubi[1][0][2] = rubi[4][0][2];

		rubi[4][0][0] = rubi[3][2][2];
		rubi[4][0][1] = rubi[3][2][1];
		rubi[4][0][2] = rubi[3][2][0];

		rubi[3][2][2] = rubi[5][0][0];
		rubi[3][2][1] = rubi[5][0][1];
		rubi[3][2][0] = rubi[5][0][2];

		rubi[5][0][0] = t1;
		rubi[5][0][1] = t2;
		rubi[5][0][2] = t3;
		rot(0, 3);
		break;
	case 11:
		t1 = rubi[1][1][0];
		t2 = rubi[1][1][1];
		t3 = rubi[1][1][2];

		rubi[1][1][0] = rubi[4][1][0];
		rubi[1][1][1] = rubi[4][1][1];
		rubi[1][1][2] = rubi[4][1][2];

		rubi[4][1][0] = rubi[3][1][2];
		rubi[4][1][1] = rubi[3][1][1];
		rubi[4][1][2] = rubi[3][1][0];

		rubi[3][1][2] = rubi[5][1][0];
		rubi[3][1][1] = rubi[5][1][1];
		rubi[3][1][0] = rubi[5][1][2];

		rubi[5][1][0] = t1;
		rubi[5][1][1] = t2;
		rubi[5][1][2] = t3;
		break;
	case 12:
		t1 = rubi[1][2][0];
		t2 = rubi[1][2][1];
		t3 = rubi[1][2][2];

		rubi[1][2][0] = rubi[4][2][0];
		rubi[1][2][1] = rubi[4][2][1];
		rubi[1][2][2] = rubi[4][2][2];

		rubi[4][2][0] = rubi[3][0][2];
		rubi[4][2][1] = rubi[3][0][1];
		rubi[4][2][2] = rubi[3][0][0];

		rubi[3][0][0] = rubi[5][2][2];
		rubi[3][0][1] = rubi[5][2][1];
		rubi[3][0][2] = rubi[5][2][0];

		rubi[5][2][0] = t1;
		rubi[5][2][1] = t2;
		rubi[5][2][2] = t3;
		rot(2, 1);
		break;
	}
}


int main() {
	int rota, muun;
	int tc; cin >> tc;
	memcpy(backup, rubi, sizeof(rubi));
	for (int i = 1; i <= tc; ++i) {
		memcpy(rubi, backup, sizeof(backup));
		int ord; cin>>ord;
		for (int j = 0; j < ord; j++) {
			cin >> rota; solve(rota);

			//cout << "\n";
			//for (int m = 0; m < 6; m++) {
			//	for (int h = 0; h < 3; h++) {
			//		for (int w = 0; w < 3; w++) {
			//			cout << ' ' << rubi[m][h][w];
			//		}
			//	}
			//	cout << "\n";
			//}
			//cout << "\n";
		}

		cin >> muun;
		cout << "#" << i;
		for (int h = 0; h < 3; h++) {
			for (int w = 0; w < 3; w++) {
				cout<<' '<<rubi[muun-1][h][w];
			}
		}
		cout << '\n';
	}

	//while (1) {
	//	memcpy(rubi, backup, sizeof(backup));
	//	cin >> rota; solve(rota);

	//	cout << "\n";
	//	for (int m = 0; m < 6; m++) {
	//		for (int h = 0; h < 3; h++) {
	//			for (int w = 0; w < 3; w++) {
	//				cout << ' ' << rubi[m][h][w];
	//			}
	//			cout << "\n";
	//		}
	//		cout << "\n";
	//	}
	//	cout << "\n";
	//}

	return 0;
}