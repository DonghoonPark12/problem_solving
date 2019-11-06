#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution2(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	vector<int> bridge(bridge_length, 0);
	int on_bridge_weight = 0;

	// 처리
	bridge.erase(bridge.begin(), bridge.begin() + 1);
	bridge.push_back(truck_weights.front());
	on_bridge_weight = truck_weights.front();
	truck_weights.erase(truck_weights.begin(), truck_weights.begin() + 1);
	truck_weights.push_back(0);
	answer++;

	while (true)
	{

		if (on_bridge_weight == 0)
			break;

		if (truck_weights.front() + on_bridge_weight - bridge.front() <= weight)//다리 한계보다 클경우
		{
			//cout <<endl<< "루트if" << endl;
			bridge.push_back(truck_weights.front());
			on_bridge_weight += truck_weights.front();
			truck_weights.erase(truck_weights.begin(), truck_weights.begin() + 1);
		}
		else
		{
			//cout << endl << "루트else" << endl;
			bridge.push_back(0);
		}

		on_bridge_weight -= bridge.front();
		//cout << "on_bridge_weight= " << on_bridge_weight << endl;

		bridge.erase(bridge.begin(), bridge.begin() + 1);
		truck_weights.push_back(0);
		answer++;

	}
	return answer;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time_ = 0;
	int b_w = 0;//bridge weight
				//queue<int> bridge(bridge_length);
	int bridge[10000] = { -1 };
	int len = truck_weights.size();

	int tmp = 0;
	int front_;
	for (int i = 0; i<len / 2; i++) {
		tmp = truck_weights[len - 1 - i];
		truck_weights[len - 1 - i] = truck_weights[i];
		truck_weights[i] = tmp;
	}
	for (int i = 0; i<bridge_length; i++) {
		bridge[i] = 0;
	}
	for (;;) {
		if (truck_weights.empty() && b_w == 0) {
			time_++;
			break;
		}

		/*
		(b_w + truck_weight.front() > weight)로 했었다. 들어올 값을 다리 적재된 무게와 미리 더해서
		새로운 차를 더할 수 있을지 알아보고자 함이었는데, 마지막 무게 6인 차를 다리에 올려 보낸 후가
		문제되었다.

		*/
		if (!truck_weights.empty())
			front_ = truck_weights.back();
		else
			front_ = 0;

		if (b_w + front_ > weight) { //다리에 있는 차만 이동 시킨다.
			for (int i = bridge_length - 1; i >= 0; i--) {
				int tmp;
				if (bridge[i] != 0 && i == bridge_length - 1) { //다리의 끝
					b_w -= bridge[i];
					bridge[i] = 0;
				}
				else if (bridge[i] != 0) {
					tmp = bridge[i];
					bridge[i + 1] = bridge[i];
					bridge[i] = 0;
				}
				else {}
			}
		}
		else {
			if (!truck_weights.empty()) {
				bridge[0] = truck_weights.back();
				truck_weights.pop_back();
				b_w += bridge[0];
			}
			if (b_w != 0) {//다리에 아무도 없을 경우 이동은 안해도 된다. 
				for (int i = bridge_length - 1; i >= 0; i--) {
					int tmp;
					if (bridge[i] != 0 && i == bridge_length - 1) { //다리의 끝
						b_w -= bridge[i];
						bridge[i] = 0;
					}
					else if (bridge[i] != 0) {
						tmp = bridge[i];
						bridge[i + 1] = bridge[i];
						bridge[i] = 0;
					}
					else {}
				}
			}

		}
		//else {}
		time_++;
	}
	return time_;
}

int main(void)
{
	int N;
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	int bridge_length;
	int weight; 
	vector<int> truck_weights;

	cin >> N;
	cin >> bridge_length;

	int tmp = 0;
	cin >> weight;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		truck_weights.push_back(tmp);
	}

	cout<< solution2(bridge_length,weight,truck_weights);


	return 0;

}