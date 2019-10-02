#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

vector<int> pick;
vector<int> num;
bool pick[8] = { false, };

//	15649: 순열 문제. 순열 문제에는 pick 배열이 필요하다. dfs(i)로 재귀를 들어가도 된다(pos역할이 딱히 필요하지 않다.)

//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++)
//			cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		if (!pick[num[i]]) {
//			pick.push_back(num[i]);
//			pick[num[i]] = true;
//
//			dfs(i);
//
//			pick.pop_back();
//			pick[num[i]] = false;
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i<n; i++) {
//		num.push_back(i + 1);
//	}
//
//	dfs(0);
//	return 0;
//}


//15650 : 조합
//         dfs(pos)
//	    for	i  pos
//      dfs(i+1)

//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int v = 0; v<pick.size(); v++) cout << pick[v] << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = pos; i<num.size(); i++) {
//		pick.push_back(num[i]);
//
//		dfs(i + 1);
//
//		pick.pop_back();
//	}
//	return;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i<n; i++) { num.push_back(i + 1); }
//	dfs(0);
//	return 0;
//}

// 15651 : 중복 순열 
//void dfs() {
//	if (pick.size() == m) {
//		for (int v = 0; v<pick.size(); v++)
//			cout << pick[v] << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i<num.size(); i++) {
//		pick.push_back(num[i]);
//		dfs();
//		pick.pop_back();
//
//	}
//	return;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n >> m;
//
//	for (int i = 0; i<n; i++) {
//		num.push_back(i + 1);
//	}
//	dfs();
//	return 0;
//}

//15652: 같은 숫자를 또 골라도 되지만, 앞자리 숫자보다 같거나 커야 한다. (4)
//     : pos가 기준의 역할을 한다. i는 pos보다는 같거나 크게 뽑혀야 한다.
//     : 조합의 변형

//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) { // i = pos로 바꾸면 된다. 
//		if (i >= pos) { // 없어도 되는 구나. 
//			pick.push_back(num[i]);
//			dfs(i);
//			pick.pop_back();
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) num.push_back(i);
//	dfs(0);
//	return 0;
//}

/* ---------------------------------------------------------------------------- */

//	15654: 순열. N개를 num 벡터에 받고, 정렬한 후 순열 풀듯이 하면 되겠다.(5)
//       : 순열은 pick배열이 필요함을 잊지 말자.
//       : 사용자 입력

//#include <algorithm>
//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		if (!pick[i]) {
//			pick.push_back(num[i]);
//			pick[i] = true;
//			dfs(i);
//			pick.pop_back();
//			pick[i] = false;
//		}
//	}
//}
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 1; i <= n; i++) { cin >> tmp; num.push_back(tmp); }
//	sort(num.begin(), num.end());
//	dfs(0);
//	return 0;
//}

//15655 : 사용자 입력 조합
//#include <algorithm>
//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = pos; i < n; i++) {
//		pick.push_back(num[i]);
//		dfs(i+1);
//		pick.pop_back();
//	}
//}
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 1; i <= n; i++) { cin >> tmp; num.push_back(tmp); }
//	sort(num.begin(), num.end());
//	dfs(0);
//	return 0;
//}


//15656 : 사용자 입력 중복 순열
//#include <algorithm>
//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		pick.push_back(num[i]);
//		dfs(i + 1);
//		pick.pop_back();
//	}
//}
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 1; i <= n; i++) { cin >> tmp; num.push_back(tmp); }
//	sort(num.begin(), num.end());
//	dfs(0);
//	return 0;
//}

//15657 : 사용자 입력 조합 변형
//#include <algorithm>
//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = pos; i < n; i++) {
//		pick.push_back(num[i]);
//		dfs(i);
//		pick.pop_back();
//	}
//}
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 1; i <= n; i++) { cin >> tmp; num.push_back(tmp); }
//	sort(num.begin(), num.end());
//	dfs(0);
//	return 0;
//}
/* ---------------------------------------------------------------------------- */

//15663 : 중복 원소가 포함된 수열의 순열 문제. 
//      : 중복 원소를 벡터에 담되, 이미 출력했던 수열은 또 출력하면 안된다. 
//      : 해결법: pick 벡터를 set에 담는다. 
//      : set<vector<int>> s 출력에 유의

//#include <set>
//set<vector<int>> s;
//void dfs(int pos) {
//	if (pick.size() == m) {
//		s.insert(pick);
//		return;
//	}
//	for (int i = 0; i < num.size(); i++) {
//		if (!pick[i]) {
//			pick.push_back(num[i]);
//			pick[i] = true;
//			dfs(i);
//			pick.pop_back();
//			pick[i] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 0; i < n; i++) { cin >> tmp; num.push_back(tmp); }
//	//sort(num.begin(), num.end()); //<-- sort가 필요 없다.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size() ; i++) { //In this case, (*it) is pointer of it. ↑
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	/*
//	for (int i = 0; i < s.size(); i++) { //set is associate container, so can't print using for loop.
//		cout<<s.
//	}
//	*/
//	return 0;
//}

//15664: 중복 원소가 포함된 수열의 조합 문제
//#include <set>
//set<vector<int>> s;
//void dfs(int pos) {
//	if (pick.size() == m) {
//		s.insert(pick);
//		return;
//	}
//	for (int i = pos; i < num.size(); i++) {
//		pick.push_back(num[i]);
//		dfs(i+1);
//		pick.pop_back();
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 0; i < n; i++) { cin >> tmp; num.push_back(tmp); }
//	//sort(num.begin(), num.end()); //<-- sort가 필요 하다.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ↑
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//15665: 중복 원소가 포함된 수열의 중복 순열 문제
//#include <set>
//set<vector<int>> s;
//void dfs() {
//	if (pick.size() == m) {
//		s.insert(pick);
//		return;
//	}
//	for (int i = 0; i < num.size(); i++) {
//		pick.push_back(num[i]);
//		dfs();
//		pick.pop_back();
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 0; i < n; i++) { cin >> tmp; num.push_back(tmp); }
//	//sort(num.begin(), num.end());  //<-- sort가 필요 없다.
//	dfs();
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ↑
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//15666: 중복 원소가 포함된 사용자 입력 조합 변형
//#include <set>
//set<vector<int>> s;
//void dfs(int pos) {
//	if (pick.size() == m) {
//		s.insert(pick);
//		return;
//	}
//	for (int i = pos; i < num.size(); i++) {
//		pick.push_back(num[i]);
//		dfs(i);
//		pick.pop_back();
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int tmp;
//	for (int i = 0; i < n; i++) { cin >> tmp; num.push_back(tmp); }
//	sort(num.begin(), num.end()); //<-- sort가 필요 하다.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ↑
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}
