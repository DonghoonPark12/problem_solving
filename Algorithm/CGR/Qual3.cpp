#include <iostream>
#include <vector>
using namespace std;

int x[4] = { -1, 1,0, 0 };
int y[4] = { 0, 0, -1 , 1 };
int x2[8] = { -1, 1,0, 0 , -1, 1, -1, 1};
int y2[8] = { 0, 0, -1 , 1, -1, 1, 1, -1 };

vector<int> solution(vector<vector<int> > image)
{
	vector<int> answer;



	return answer;
}
int h, w;
//bool is_boundary(int x, int y) {
//	if(image)
//}
void dfs(int i, int j, vector<vector<int>> &image) {
	image[i][j] = 2;
	for (int d = 0; d < 4; d++) {
		int nx = i + x[d]; //À§, ¾Æ·¡, ¿Þ, ¿À
		int ny = j + y[d];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && image[nx][ny] == 1) {
			dfs(nx, ny, image);
		}
	}
}

void dfs2(int i, int j, vector<vector<int>> &image) {
	image[i][j] = 1;
	for (int d = 0; d < 8; d++) {
		int nx = i + x2[d]; //À§, ¾Æ·¡, ¿Þ, ¿À
		int ny = j + y2[d];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && image[nx][ny] == 2) {
			dfs2(nx, ny, image);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> image(50, vector<int>(50));
	//vector<vector<int>> visited(50, vector<int>(50));

	vector<int> answer;

	//h = image.size();
	//w = image[0].size();
	h = 5;
	w = 4;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> image[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			if (image[i][j] == 1) {
				dfs(i, j, image);
				cnt++;
			}
		}
	}
	answer.push_back(cnt);

	cnt = 0;
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			if (image[i][j] == 2) {
				dfs2(i, j, image);
				cnt++;
			}
		}
	}
	answer.push_back(cnt);

	//solution(image);

	return 0;
}