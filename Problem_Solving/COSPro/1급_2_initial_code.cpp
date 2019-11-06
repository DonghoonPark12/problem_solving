#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string func_a(string str, int len){
    string padZero = "";
    int padSize = @@@;
    for(int i = 0; i < padSize; i++)
        padZero += "0";
    return padZero + str;
}

int solution(string binaryA, string binaryB) {
    int max_length = max(binaryA.length(), binaryB.length());
    binaryA = func_a(binaryA, max_length);
    binaryB = func_a(binaryB, max_length);
    
    int hamming_distance = 0;
    for(int i = 0; i < max_length; i++)
        if(@@@)
            hamming_distance += 1;
    return hamming_distance;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string binaryA = "10010";
    string binaryB = "110";
    int ret = solution(binaryA, binaryB);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}