#include <stdio.h>
#include <stdbool.h>
int n, board[25][25] = {0};
bool judge(int i, int j, int *x, int *y) {
	bool flag1, flag2, flag3, flag4;
	flag1 = flag2 = flag3 = flag4 = false;
	// upright
	if(!(i - 2 < 0 || i + 2 > n - 1)) {
		if(board[i - 1][j] == -1 && board[i - 2][j] == -1 &&
		    board[i + 1][j] == -1 && board[i + 2][j] == -1) {
			*x = j, *y = i - 2;
			flag1 = true;
		}
	}
	// lateral
	if(!(j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i][j - 1] == -1 && board[i][j - 2] == -1 &&
		    board[i][j + 1] == -1 && board[i][j + 2] == -1) {
			*x = j - 2, *y = i;
			flag2 = true;
		}
	}
	// left diagonal
	if(!(i - 2 < 0 || i + 2 > n - 1 || j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i - 2][j - 2] == -1 && board[i - 1][j - 1] == -1 &&
			board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1) {
			*x = j - 2, *y = i - 2;
			flag3 = true;
		}
	}
	// right diagonal
	if(!(i - 2 < 0 || i + 2 > n - 1 || j - 2 < 0 || j + 2 > n - 1)) {
		if(board[i - 2][j + 2] == -1 && board[i - 1][j + 1] == -1 &&
		    board[i + 1][j - 1] == -1 && board[i + 2][j - 2] == -1) {
			*x = j - 2, *y = i + 2;
			flag4 = true;
		}
	}
	if(flag1 || flag2 || flag3 || flag4) return true;
	else return false;
}
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	getchar();
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			board[i][j] = getchar() == '*' ? -1 : 0;
		}
		getchar();
	}
	bool flag = false;
	int x, y; 
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(board[i][j] == -1) flag = judge(i, j, &x, &y);
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) printf("Win %d %d", x, y);
	else printf("Not yet");
	return 0;
}
