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
			map ������ ���� ����, �� ä��� ��ä��� ��� ������ �ƴϴ�.
			�ĺ��� �̹� �־����� ���������� ���� ������ �� �ְ� �ȴ�.
		*/
		//�ĺ��� ���ٸ�
		if (slot.find(tmp) == slot.end()) {
			//���� Ʋ�� �� ��ä�� ��� --> ä��� 
			if (slot.size() < n) {
				slot[tmp].first = 1;
				slot[tmp].second = t;  // ���� �ð�
			}
			//����Ʋ�� �� ä�� ���, ���� ������ �� ����
			else {
				int victim = slot.begin()->first; //�ʱ�ȭ
				pii val = slot.begin()->second;   //�ʱ�ȭ
				for (auto a : slot)
				{
					if (a.second < val) {  //���� ������ �� ã��
						val = a.second;    //�ð�
						victim = a.first;  //��ǥ��
					}
				}
				//���� ������ �� �����ϰ� ���ο� �� �ִ´�.
				slot.erase(victim); //map �� ������ �̷��Գ� ����. Key�� �ٷ� ���� �����ϴ�. 
				slot[tmp].first = 1;
				slot[tmp].second = t;
			}
		}
		//�̹� �ĺ��� �ִٸ� 
		else {
			//�ִ� ��� ��õ���� �߰�
			slot[tmp].first = slot[tmp].first + 1;
		}
	}
	for (auto it : slot)
	{
		printf("%d ", it.first);
	}
	return 0;
}


