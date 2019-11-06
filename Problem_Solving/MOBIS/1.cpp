#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(int y, int x, vector<string> &board, int n) {
	char st = board[y][x];
	int len = 1;
	bool poss = true;
	while (1) {
		if (y + len >= n || x + len >= n || y - len < 0 || x - len < 0) {
			break;
		}
		if (board[y + len][x + len] != st) poss = false;
		if (board[y + len][x - len] != st) poss = false;
		if (board[y - len][x + len] != st) poss = false;
		if (board[y - len][x - len] != st) poss = false;

		if (poss)
			len += 1;
		else {
			len -= 1; break;
		}
	}

	return len;
}

int solution(vector<string> board) {
	int answer = 0;
	int board_len = board.size();
	// for(int i=0;i<board_len; i++){
	//    for(int j=0;j<board_len; j++){
	//         cout<<board[i][j]<<" ";
	//    }
	//     cout<<"\n";
	// }
	int _max = 0;

	for (int y = 1; y<board_len - 1; y++) {
		for (int x = 1; x<board_len - 1; x++) {
			/* -------------------------------------------------------------------- */
			int _len = check(y, x, board, board_len);
			_max = max(_len, _max);
			/* -------------------------------------------------------------------- */
			//            char st = board[y][x];
			//            int len = 1;
			//            bool poss = true;
			//            while(1){
			//                 if(y + len >= board_len || x + len >= board_len || y - len < 0 || x - len < 0) break;
			//                 if(board[y+len][x+len] != st) poss = false;
			//                 if(board[y+len][x-len] != st) poss = false;
			//                 if(board[y-len][x+len] != st) poss = false;
			//                 if(board[y-len][x-len] != st) poss = false;

			//                 if(poss) len += 1;
			//                 else{
			//                     len -= 1; break;
			//                 }
			//            }
			//            _max = max(len, _max);
			/* -------------------------------------------------------------------- */
		}
	}
	return _max;
}


int main() {
	freopen("input.txt", "r", stdin);
	vector<string> arr;
	int board_len = 3;
	string str;
	for (int i = 0; i < board_len; i++) {
		//for (int j = 0; j < board_len; j++) {
		//	scanf("%1c", &arr[i][j]);
		//}
		cin >> str;
		arr.push_back(str);
	}
	cout << solution(arr);
	
	return 0;
}