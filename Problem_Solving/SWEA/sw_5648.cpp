#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int sum_e = 0;
		int n; //원자 갯수
		int _x, _y, _dir, _e;//하나의 원자가 가지고 있는 위치, 방향, 에너지
		cin >> n;
		vector<vector<int>> arr(4002, vector<int> (4002));
		for (int i = 0; i < n; i++) {
			cin >> _x >> _y >> _dir >> _e;
			arr[_y*2 + 2000][_x*2 + 2000] = 10000 + _dir * 1000 + _e;
		}
		while (1) {
			// 원자의 이동
			for (int y = 1; y <= 4000;  y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					int tmp=0;
					if (arr[y][x] != 0) {
							tmp = arr[y][x];
							//우측 이동
							if ( ((arr[y][x]-10000) / 1000 == 3) && (x != 4000)) {
								arr[y][x + 1] += tmp;
							}
							//좌측 이동
							else if ( ((arr[y][x]-10000) / 1000 == 2) && (x != 1)) {
								arr[y][x - 1] += tmp;
							}
							//아래 이동
							else if ( ((arr[y][x]-10000) / 1000 == 1) && (y != 4000)) {
								arr[y + 1][x] += tmp;
							}
							//위로 이동
							else if( ((arr[y][x]-10000) / 1000 == 0) && (y != 1)){
								arr[y - 1][x] += tmp;
							}
							else { }
							arr[y][x] = 0;
					}
				}
			}
			//두개 이상이 출동하였다면, 소멸.
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] / 10000 > 1) { // % -> /
						sum_e += arr[y][x] % 1000;
						arr[y][x] = 0;
					}
				}
			}

			int end_flag = 1;
			//원소가 남아 있는지 여부 확인
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] != 0)
						end_flag = 0;
				}
			}
			if (end_flag)
				break;
		}
		printf("#%d %d\n", t+1, sum_e);
	}
	return 0;
}



#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> atom(1000, vector<int>(4));
vector<vector<int>> visit(4005, vector<int>(4005));
vector<vector<bool>> collided(4005, vector<bool>(4005));

//마지막 값을 삭제하는 원자의 자리로 옮긴다.
//충돌한 원자는 어차피 더이상 사용하지 않으므로 무시한다.
void RemoveAtom(int n, int *pnsize) {
	int nLastIndex = (*pnsize) - 1;
	atom[n][0] = atom[nLastIndex][0];
	atom[n][1] = atom[nLastIndex][1];
	atom[n][2] = atom[nLastIndex][2];
	atom[n][3] = atom[nLastIndex][3];
	(*pnsize)--;//원자의 수를 1개 줄임
}

int solution(int N) {
	int nRest = N;
	int ans = 0;

	//좌표계 2배로 늘림
	for (int j = 0; j < nRest; ++j) {//원자의 갯수, 4
		atom[j][0] = atom[j][0] * 2;//원소의 위치를 두배씩 늘려주고
		atom[j][1] = atom[j][1] * 2;
		visit[atom[j][0]][atom[j][1]]++;//해당 위치에 visit 표시
	}

	int n_maxLoop = 4002;
	for (int i = 0; i < n_maxLoop; ++i) {

		//원자 이동
		for (int j = 0; j< nRest; ++j) { //원자의 갯수, 4
			int &x = atom[j][0];
			int &y = atom[j][1];
			int d = atom[j][2];
			visit[x][y]--;      //해당 위치 원자 제거.
			if (d == 0) y++;//up
			else if (d == 1) y--;//down
			else if (d == 2) x--;//left
			else if (d == 3) x++;//right

								 //범위 0 ~4000, 0~4000 벗어나면 제거.
			if (atom[j][0] < 0 || atom[j][0]>4000 || atom[j][1] < 0 || atom[j][1]>4000) {
				RemoveAtom(j, &nRest);
				j--;
			}
			else {
				visit[x][y]++;
				if (visit[x][y] > 1) collided[x][y] = true;
			}
		}

		//모든 원자를 이동시켰으면, 다시 원자들을 순회하면서 원자가 현재 자리한 위치에
		//충돌이 있었는지 확인. 충돌이 있었으면 해당 원자를 제거하고, 원자가 분출하는
		//에너지 계산.
		for (int j = 0; j < nRest; ++j) {
			int x = atom[j][0]; int y = atom[j][1];
			if (collided[x][y] == 1) {

				if (visit[x][y] == 1) collided[x][y] = false;

				visit[x][y]--;
				ans += atom[j][3];
				//충돌 되었으므로 해당 원자 삭제
				RemoveAtom(j, &nRest);
				j--;
			}
		}
		if (nRest == 0) break;
	}
	return ans;
}

void main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		N = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
			atom[i][0] += 1000;
			atom[i][1] += 1000;
		}
		int nRes = solution(N);
		cout << "#" << t << ' ' << nRes << endl;
	}
}