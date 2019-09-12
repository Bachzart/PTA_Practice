#include <iostream>
using namespace std;
int n, board[25][25] = {0};
bool judge(int i, int j, int &x, int &y) {
	bool flag1, flag2, flag3, flag4;
	flag1 = flag2 = flag3 = flag4 = false;
	// upright
	if(!(i - 2 < 0 || i + 2 > n - 1)) {
		if(board[i - 1][j] == -1 && board[i - 2][j] == -1 &&
		    board[i + 1][j] == -1 && board[i + 2][j] == -1) {
			x = j, y = i - 2;
			flag1 = true;
		}
	}
	// lateral
	if(!(j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i][j - 1] == -1 && board[i][j - 2] == -1 &&
		    board[i][j + 1] == -1 && board[i][j + 2] == -1) {
			x = j - 2, y = i;
			flag2 = true;
		}
	}
	// left diagonal
	if(!(i - 2 < 0 || i + 2 > n - 1 || j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i - 2][j - 2] == -1 && board[i - 1][j - 1] == -1 &&
			board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1) {
			x = j - 2, y = i - 2;
			flag3 = true;
		}
	}
	// right diagonal
	if(!(i - 2 < 0 || i + 2 > n - 1 || j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i - 2][j + 2] == -1 && board[i - 1][j + 1] == -1 &&
		    board[i + 1][j - 1] == -1 && board[i + 2][j - 2] == -1) {
			x = j - 2, y = i + 2;
			flag4 = true;
		}
	}
	if(flag1 || flag2 || flag3 || flag4) return true;
	else return false;
}
int main() {
	cin >> n;
	char temp;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> temp;
			if(temp == '*') board[i][j] = -1;
		}
	}
	int flag = false, x, y;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == -1) flag = judge(i, j, x, y);
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) cout << "Win" << ' ' << x << ' ' << y;
	else cout << "Not yet";
	return 0;
}

/*
some samples:

4
....
****
....
....

3
...
.*.
***

1
*

2
**
**

6
.*****
..#...
..#...
......
....*.
.....*

7
..*....
..*....
..*..#.
..*.#..
..*#...
..#..##
.#.****

5
*....
.*...
..*..
...*.
....*

5
....*
...*.
..*..
.*...
*....

*/
