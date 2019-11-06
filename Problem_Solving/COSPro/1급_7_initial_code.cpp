#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arrA, vector<int> arrB){
    int arrA_idx = 0, arrB_idx = 0;
    int arrA_len = arrA.size();
    int arrB_len = arrB.size();
    vector<int> answer;
	while (arrA_idx < arrA_len && arrB_idx < arrB_len) {
		if (arrA[arrA_idx] < arrB[arrB_idx])
			answer.push_back(arrA[arrA_idx++]);
		else
			answer.push_back(arrB[arrB_idx++]);
	}
	while (arrA_idx < arrA_len)
		answer.push_back(arrA[arrA_idx++]);
	while (arrB_idx < arrB_len)
		answer.push_back(arrB[arrB_idx++]);
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<int> arrA = {-2, 3, 5, 9};
    vector<int> arrB = {0, 1, 5};
    vector<int> ret = solution(arrA, arrB);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}