#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int sum_e = 0;
		int n; //���� ����
		int _x, _y, _dir, _e;//�ϳ��� ���ڰ� ������ �ִ� ��ġ, ����, ������
		cin >> n;
		vector<vector<int>> arr(4002, vector<int> (4002));
		for (int i = 0; i < n; i++) {
			cin >> _x >> _y >> _dir >> _e;
			arr[_y*2 + 2000][_x*2 + 2000] = 10000 + _dir * 1000 + _e;
		}
		while (1) {
			// ������ �̵�
			for (int y = 1; y <= 4000;  y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					int tmp=0;
					if (arr[y][x] != 0) {
							tmp = arr[y][x];
							//���� �̵�
							if ( ((arr[y][x]-10000) / 1000 == 3) && (x != 4000)) {
								arr[y][x + 1] += tmp;
							}
							//���� �̵�
							else if ( ((arr[y][x]-10000) / 1000 == 2) && (x != 1)) {
								arr[y][x - 1] += tmp;
							}
							//�Ʒ� �̵�
							else if ( ((arr[y][x]-10000) / 1000 == 1) && (y != 4000)) {
								arr[y + 1][x] += tmp;
							}
							//���� �̵�
							else if( ((arr[y][x]-10000) / 1000 == 0) && (y != 1)){
								arr[y - 1][x] += tmp;
							}
							else { }
							arr[y][x] = 0;
					}
				}
			}
			//�ΰ� �̻��� �⵿�Ͽ��ٸ�, �Ҹ�.
			for (int y = 1; y <= 4000; y++) { //16,000,000
				for (int x = 1; x <= 4000; x++) {
					if (arr[y][x] / 10000 > 1) { // % -> /
						sum_e += arr[y][x] % 1000;
						arr[y][x] = 0;
					}
				}
			}

			int end_flag = 1;
			//���Ұ� ���� �ִ��� ���� Ȯ��
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

//������ ���� �����ϴ� ������ �ڸ��� �ű��.
//�浹�� ���ڴ� ������ ���̻� ������� �����Ƿ� �����Ѵ�.
void RemoveAtom(int n, int *pnsize) {
	int nLastIndex = (*pnsize) - 1;
	atom[n][0] = atom[nLastIndex][0];
	atom[n][1] = atom[nLastIndex][1];
	atom[n][2] = atom[nLastIndex][2];
	atom[n][3] = atom[nLastIndex][3];
	(*pnsize)--;//������ ���� 1�� ����
}

int solution(int N) {
	int nRest = N;
	int ans = 0;

	//��ǥ�� 2��� �ø�
	for (int j = 0; j < nRest; ++j) {//������ ����, 4
		atom[j][0] = atom[j][0] * 2;//������ ��ġ�� �ι辿 �÷��ְ�
		atom[j][1] = atom[j][1] * 2;
		visit[atom[j][0]][atom[j][1]]++;//�ش� ��ġ�� visit ǥ��
	}

	int n_maxLoop = 4002;
	for (int i = 0; i < n_maxLoop; ++i) {

		//���� �̵�
		for (int j = 0; j< nRest; ++j) { //������ ����, 4
			int &x = atom[j][0];
			int &y = atom[j][1];
			int d = atom[j][2];
			visit[x][y]--;      //�ش� ��ġ ���� ����.
			if (d == 0) y++;//up
			else if (d == 1) y--;//down
			else if (d == 2) x--;//left
			else if (d == 3) x++;//right

								 //���� 0 ~4000, 0~4000 ����� ����.
			if (atom[j][0] < 0 || atom[j][0]>4000 || atom[j][1] < 0 || atom[j][1]>4000) {
				RemoveAtom(j, &nRest);
				j--;
			}
			else {
				visit[x][y]++;
				if (visit[x][y] > 1) collided[x][y] = true;
			}
		}

		//��� ���ڸ� �̵���������, �ٽ� ���ڵ��� ��ȸ�ϸ鼭 ���ڰ� ���� �ڸ��� ��ġ��
		//�浹�� �־����� Ȯ��. �浹�� �־����� �ش� ���ڸ� �����ϰ�, ���ڰ� �����ϴ�
		//������ ���.
		for (int j = 0; j < nRest; ++j) {
			int x = atom[j][0]; int y = atom[j][1];
			if (collided[x][y] == 1) {

				if (visit[x][y] == 1) collided[x][y] = false;

				visit[x][y]--;
				ans += atom[j][3];
				//�浹 �Ǿ����Ƿ� �ش� ���� ����
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