// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string pos) {
	int dx[] = { 1,1,-1,-1,2,2,-2,-2 };//{1, 2, 2, 1,-1,-2, -2, -1};
	int dy[] = { 2,-2,-2,2,1,-1,-1,1 };//{2, 1,-1,-2,-2,-1, 1, 2};
	int cx = pos[0] - 'A';
	int cy = pos[1] - '0' - 1;
	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			ans++;
	}
	return ans;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string pos = "A7";
    int ret = solution(pos);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}