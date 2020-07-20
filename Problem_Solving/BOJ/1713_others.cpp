#include <iostream> 
#include <map>
using namespace std;  
typedef pair<int, int> pii; 
map<int, pii> slot; //pii.first = vote , pii.second = age 

int main() 
{
	int n, k;
	int cnt = 0;
	cin >> n >> k;

	for (int t = 1; t <= k; t++) {
		int tmp; cin >> tmp;
		/*
			map 데이터 구조 쓰면, 다 채우든 안채우든 고려 사항이 아니다.
			후보가 이미 있었는지 없었는지로 먼저 생각할 수 있게 된다.
		*/
		//후보가 없다면
		if (slot.find(tmp) == slot.end()) {
			//사진 틀을 다 못채운 경우 --> 채운다 
			if (slot.size() < n) {
				slot[tmp].first = 1;
				slot[tmp].second = t;  // 현재 시간
			}
			//사진틀을 다 채운 경우, 가장 오래된 것 삭제
			else {
				int victim = slot.begin()->first; //초기화
				pii val = slot.begin()->second;   //초기화
				for (auto a : slot)
				{
					if (a.second < val) {  //가장 오래된 것 찾기
						val = a.second;    //시간
						victim = a.first;  //투표수
					}
				}
				//가장 오래된 것 제거하고 새로운 것 넣는다.
				slot.erase(victim); //map 은 삭제가 이렇게나 쉽다. Key로 바로 삭제 가능하다. 
				slot[tmp].first = 1;
				slot[tmp].second = t;
			}
		}
		//이미 후보가 있다면 
		else {
			//있는 경우 추천수만 추가
			slot[tmp].first = slot[tmp].first + 1;
		}
	}
	for (auto it : slot)
	{
		printf("%d ", it.first);
	}
	return 0;
}


