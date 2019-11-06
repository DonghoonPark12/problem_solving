#include <iostream>
#include <cstring>
using namespace std;
class _heap {
public:
	int numofdata;
	int heapArr[100001];
	void init();
	int GetHiPriChildIdx(int);
	void push(int);
	int pop();
	void Swap(int, int);
};
int _heap::GetHiPriChildIdx(int idx) {
	if (idx * 2 > numofdata) //자식 노드가 없다면
		return 0;
	else if (idx * 2 == numofdata) //왼쪽 자식노드 하나만 존재한다면
		return idx * 2;
	else {
		if (heapArr[idx * 2] < heapArr[idx * 2 + 1]) // < : 값이 크면 우선순위 높다.
			return idx * 2 + 1;
		else
			return idx * 2;
	}
}

void _heap::Swap(int a, int b) {
	int tmp = heapArr[a];
	heapArr[a] = heapArr[b];
	heapArr[b] = tmp;
}

void _heap::init() {
	numofdata = 0;
	memset(heapArr, -1, sizeof(heapArr));
}

void _heap::push(int data) {
	int idx = numofdata + 1;
	
	//1
	//while (idx != 1) {
	//	if (data > heapArr[idx/2]) { //> 하면 maxheap
	//		heapArr[idx] = heapArr[idx / 2];
	//		idx = idx / 2;
	//	}
	//	else
	//		break;
	//}

	//heapArr[idx] = data;
	//numofdata += 1;


	//2
	heapArr[idx] = data;
	while (1) {
		int pidx = idx / 2;
		if (heapArr[pidx] >= heapArr[idx]) break;
		Swap(pidx, idx);
		idx = pidx;
	}
	numofdata += 1;
}

int _heap::pop() {
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
				hp.push(num);
			}
			else {
				cout << hp.pop() << " ";
			}
		}
		cout << '\n';
		//cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}

//
//#include <cstdio>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	for (int t = 1; t <= T; t++)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("#%d", t);
//
//		priority_queue<int> pq;
//		for (int i = 0; i < n; i++) {
//			int order;
//			scanf("%d", &order);
//			if (order == 1) {
//				int num;
//				scanf("%d", &num);
//				pq.push(num);
//			}
//			else if (order == 2) {
//				if (pq.empty()) {
//					printf(" -1");
//				}
//				else {
//					printf(" %d", pq.top());
//					pq.pop();
//				}
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
