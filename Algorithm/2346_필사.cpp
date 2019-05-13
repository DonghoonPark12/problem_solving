#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>
using namespace std;
/*
한 바퀴를 돌면, 원래 자리로 돌아와야 하므로
자료형 List를 사용할 필요가 있다.
*/

int main() {
	int n;
	//list<pair<int, int>> a;//짝을 가진 값을 원소로 가지는 List
	list<pair<int, int>> v;
	scanf("%d", &n);

	int tmp;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &tmp);
		v.push_back({ tmp,i });
	}

	auto it = v.begin(); //변수 타입이 컴파일 시에 결정

	for (int i = 0; i < n - 1; i++) {
		//printf("%d ", it->second);
		cout << (it->second) << ' ';
		int step = it->first;// 몇번을 돌 것인지
		if (step > 0) { //오른쪽으로 돈다면
			auto temp = it; //주고

			++temp;
			if (temp == v.end())
				temp = v.begin();

			v.erase(it); //지운다.
			it = temp;  //다시 돌려 받고
			for (int i = 1; i < step; i++) {
				++it; //vector일때는 에러가 난다. 왜?..
				if (it == v.end())
					it = v.begin();
			}
		}
		//v.erase(it);를 미리 하면, --it을 할 수 없다.
		//따라서, temp에게 넘겨주고, temp를 한번 이동 시킨 뒤
		// v.erase(it), it에게 temp가 넘겨주고, 한번 덜 돈다.
		//list는 end()가 마지막 원소 다음 원소 즉, NULL값인 탓에 step -/+ 에 따라 순서가 다르다.
		else {
			step = -step;
			auto temp = it; //주고

			if (temp == v.begin())
				temp = v.end();
			--temp;

			v.erase(it); //지운다.
			it = temp; //다시 돌려 받고
			for (int i = 1; i < step; i++) {
				if (it == v.begin()) {
					it = v.end();
				}
				--it;
			}
		}
	}

	printf("%d\n", v.front().second);

	return 0;
}