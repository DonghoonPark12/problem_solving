#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> prices){
    int INF = 1000000001;
    int tmp = INF;
    int answer = -INF;
    for(int price : prices){
        if(tmp != INF)
            answer = max(answer, tmp - price);
        tmp = min(tmp, price);
    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    vector<int> prices1 = {1, 2, 3};
    int ret1 = solution(prices1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    vector<int> prices2 = {3, 1};
    int ret2 = solution(prices2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}