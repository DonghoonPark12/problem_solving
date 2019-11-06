#include <iostream>  
#include <vector>  
using namespace std;

class _heap {
	vector<int> heap;
	void Swap(int a, int b);
public:
	void Push(int data);
	void Pop();
	int Top();
	bool IsEmpty();
};

void _heap::Swap(int a, int b) {
	int tmp = heap[a];
	heap[a] = heap[b];
	heap[b] = tmp;
}

int _heap::Top() {
	return heap[0];
}

bool _heap::IsEmpty() {
	return (heap.size() == 0);
}

void _heap::Push(int data) {
	heap.push_back(data);
	int idx = heap.size() - 1;
	while (1) {
		int pidx = (idx - 1) / 2; //idx/2 해도 됨
		if (heap[pidx] >= heap[idx]) break;
		Swap(pidx, idx);
		idx = pidx;
	}

}

void _heap::Pop() {
	if (IsEmpty()) return;

	heap[0] = heap.back();
	heap.pop_back();

	int pidx = 0;

	while (1) {
		int next = pidx;
		int left = pidx * 2 + 1, right = pidx * 2 + 2; //벡터의 0번 요소 부터 사용할 때, 왼쪽 자식은 i*2 +1
		int size = heap.size();                        //                                오른쪽 자식은 i*2 + 2

		if (left >= size) break; //자식 노드가 없다면 종료.

		if (heap[pidx] < heap[left]) next = left; //부모 노드 < 왼쪽 자식 노드, 

		if (right < size && heap[next] < heap[right]) next = right; //오른쪽 노드가 존재하며, 부모 노드 < 오른쪽 자식 노드

		if (next == pidx) break; //부모 노드가 왼쪽, 오른쪽 자식보다 크므로 종료.

		Swap(pidx, next);
		pidx = next;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		_heap hp;
		int n; cin >> n;
		int order;
		cout << "#" << t;
		while (n--) {
			cin >> order;
			if (order == 1) {
				int num; cin >> num;
				hp.Push(num);
			}
			else {
				int ret = hp.IsEmpty() ? -1 : hp.Top();
				cout <<" "<< ret;

				if (ret != -1) hp.Pop();
			}
		}
		cout << '\n';
		//cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}
