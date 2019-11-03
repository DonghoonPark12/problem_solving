#include <iostream>
#include <cstring>
using namespace std;
class _heap {
public:
	int numofdata;
	int heapArr[100001];
	void init();
	int GetHiPriChildIdx(int);
	void enqueue(int);
	int dequeue();
};
int _heap::GetHiPriChildIdx(int idx) {
	if (idx * 2 > numofdata) //자식 노드가 없다면
		return 0;
	else if (idx * 2 == numofdata) //왼쪽 자식노드 하나만 존재한다면
		return idx * 2;
	else {
		if (heapArr[idx * 2] > heapArr[idx * 2 + 1])
			return idx * 2 + 1;
		else
			return idx * 2;
	}
}

void _heap::init() {
	numofdata = 0;
	memset(heapArr, -1, sizeof(heapArr));
}

void _heap::enqueue(int data) {
	int idx = numofdata + 1;
	while (idx != 1) {
		if (data > heapArr[idx/2]) { //> 하면 maxheap
			heapArr[idx] = heapArr[idx / 2];
			idx = idx / 2;
		}
		else
			break;
	}

	heapArr[idx] = data;
	numofdata++;
}

int _heap::dequeue() {
	if (numofdata == 0) return -1;

	int ret = heapArr[1];
	int lastElem = heapArr[numofdata];

	int parentIdx = 1;
	int childIdx;
	while (childIdx = GetHiPriChildIdx(parentIdx)) {
		if (lastElem <= heapArr[childIdx]) break;

		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
	}
	heapArr[parentIdx] = lastElem;
	numofdata -= 1;
	return ret;
}

int main() {
	int tc; cin >> tc;
	int ans;
	for (int t = 1; t <= tc; t++) {
		_heap hp;
		hp.init();
		int n; cin >> n ;
		int order ;
		cout << "#" << t << " ";
		while (n--) {
			cin >> order ;
			if (order == 1) {
				int num; cin >> num;
				hp.enqueue(num);
			}
			else {
				cout << hp.dequeue() << " ";
			}
		}
		cout << '\n';
		//cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}
