#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

vector<int> pick;
vector<int> num;
bool pick[8] = { false, };

//	15649: ���� ����. ���� �������� pick �迭�� �ʿ��ϴ�. dfs(i)�� ��͸� ���� �ȴ�(pos������ ���� �ʿ����� �ʴ�.)

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


//15650 : ����
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

// 15651 : �ߺ� ���� 
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

//15652: ���� ���ڸ� �� ��� ������, ���ڸ� ���ں��� ���ų� Ŀ�� �Ѵ�. (4)
//     : pos�� ������ ������ �Ѵ�. i�� pos���ٴ� ���ų� ũ�� ������ �Ѵ�.
//     : ������ ����

//
//void dfs(int pos) {
//	if (pick.size() == m) {
//		for (int i = 0; i < m; i++) cout << pick[i] << " ";
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < n; i++) { // i = pos�� �ٲٸ� �ȴ�. 
//		if (i >= pos) { // ��� �Ǵ� ����. 
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

//	15654: ����. N���� num ���Ϳ� �ް�, ������ �� ���� Ǯ���� �ϸ� �ǰڴ�.(5)
//       : ������ pick�迭�� �ʿ����� ���� ����.
//       : ����� �Է�

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

//15655 : ����� �Է� ����
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


//15656 : ����� �Է� �ߺ� ����
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

//15657 : ����� �Է� ���� ����
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

//15663 : �ߺ� ���Ұ� ���Ե� ������ ���� ����. 
//      : �ߺ� ���Ҹ� ���Ϳ� ���, �̹� ����ߴ� ������ �� ����ϸ� �ȵȴ�. 
//      : �ذ��: pick ���͸� set�� ��´�. 
//      : set<vector<int>> s ��¿� ����

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
//	//sort(num.begin(), num.end()); //<-- sort�� �ʿ� ����.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size() ; i++) { //In this case, (*it) is pointer of it. ��
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

//15664: �ߺ� ���Ұ� ���Ե� ������ ���� ����
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
//	//sort(num.begin(), num.end()); //<-- sort�� �ʿ� �ϴ�.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ��
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//15665: �ߺ� ���Ұ� ���Ե� ������ �ߺ� ���� ����
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
//	//sort(num.begin(), num.end());  //<-- sort�� �ʿ� ����.
//	dfs();
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ��
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//15666: �ߺ� ���Ұ� ���Ե� ����� �Է� ���� ����
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
//	sort(num.begin(), num.end()); //<-- sort�� �ʿ� �ϴ�.
//	dfs(0);
//	for (auto it = s.begin(); it != s.end(); it++) { //In this case, it is pointer of set. ->. set is act like 2D array.
//		for (int i = 0; i <(*it).size(); i++) { //In this case, (*it) is pointer of it. ��
//			cout << (*it)[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}
