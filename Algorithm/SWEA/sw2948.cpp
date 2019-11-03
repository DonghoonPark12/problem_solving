//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string> //<string>은 c++ string, 길이 출력은 .length()
//using namespace std;
//
//int main() {
//	vector<string> v1, v2;
//	int tc; cin >> tc;
//	int l1, l2;
//	int ans = 0;
//	for(int t=1;t<=tc;t++){
//		cin >> l1 >> l2;
//		string str; v1.clear(); v2.clear();
//		for (int i = 0; i < l1; i++) { cin >> str; v1.push_back(str); }
//		for (int i = 0; i < l2; i++) { cin >> str; v2.push_back(str); }
//		sort(v1.begin(), v1.end());
//		sort(v2.begin(), v2.end());
//
//		int count = 0;
//		while (1) {
//			if (v1.empty() || v2.empty()) 
//				break;
//
//			//int cmp = v2.back() < v1.back() ? 1 : 0;
//			int cmp = v1.back().compare(v2.back());
//			
//			if (cmp > 0) {
//				v1.pop_back(); continue;
//			}
//
//			if (cmp < 0) {
//				v2.pop_back(); continue;
//			}
//			
//			count++;
//			v1.pop_back(); v2.pop_back();
//		}
//		
//		cout << "#" << t << " " << count<< '\n';
//	}
//	return 0;
//}


// 아래의 우선순위 큐로 풀면 테케가 하나도 안맞는다. 왜??
#include <iostream>
#include <queue>
#include <functional>
#include <string> //<string>은 c++ string, 길이 출력은 .length()
using namespace std;

struct cmp {
	bool operator()(string t, string u) {
		return t < u;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<string, vector<string>, greater<string> > v1, v2; //#include <functional>
	int tc; cin >> tc;
	int l1, l2;
	int ans = 0;
	for (int t = 1; t <= tc; t++) {
		cin >> l1 >> l2;
		string str;
		while (!v1.empty()) v1.pop();
		while (!v2.empty()) v2.pop();
		for (int i = 0; i < l1; i++) { cin >> str; v1.push(str); }
		for (int i = 0; i < l2; i++) { cin >> str; v2.push(str); }

		int count = 0;
		while (1) {
			if (v1.empty() || v2.empty())
				break;
			int cmp = v1.top().compare(v2.top());

			if (cmp > 0) {
				v1.pop(); continue;
			}

			if (cmp < 0) {
				v2.pop(); continue;
			}

			count++;
			v1.pop(); v2.pop();
		}

		cout << "#" << t << " " << count << '\n';
	}
	return 0;
}