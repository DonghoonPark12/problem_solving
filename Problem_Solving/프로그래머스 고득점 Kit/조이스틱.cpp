// ������ ����Ǿ����ϴ�. �̷� ���� �Լ� �����̳� �׽�Ʈ���̽��� ����Ǿ�, ������ �ڵ�� �������� ���� �� �ֽ��ϴ�.
// ���ο� �Լ� ������ �����Ϸ��� [�ڵ� �ʱ�ȭ] ��ư�� ��������. ��, [�ڵ� �ʱ�ȭ] ��ư�� ������ �ۼ� ���� �ڵ�� ������ϴ�.
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ans = 1e9;

void solve(int curr, string name, int value) { //solve(0, name, 0); "JEROEN"
    if (value > name.length())
        return;
    bool pass = true;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A') {
            pass = false;
            break;
        }
    }
    if (pass) { //End Condition
        ans = (ans > value) ? value : ans;
        return;
    }
    name[curr] = 'A';
    int next = curr + 1;
    if (next == name.length())
        next = 0;
    solve(next, name, value + 1);

    next = curr - 1;
    if (next < 0) 
        next = name.length() - 1;
    solve(next, name, value + 1);
}

int solution(string name) {
    int answer = 0;

    for (int i = 0; i < name.length(); i++) {
        int curr = (name[i] - 'A'); // A~N : 0~13, Z~O : 1~12
        if (curr > 13)
            curr = 26 - curr;
        answer += curr;
    } 
    name[0] = 'A';
    solve(0, name, 0);
    answer += ans - 1;
    return answer;
}

int main()
{
    cout << solution("JEROEN");
    return 0;
}