#include <iostream>
using namespace std;
int X[10] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Y[10] = {-1, -1, -1, 0, 0, 1, 1, 1};
int m, n;
char matrix[20][20];
char str[] = "DSWYBS";
bool outofrange(int x, int y) {
	if(x > m - 1 || x < 0 || y > n - 1 || y < 0) return 1;
	else return 0;
}
bool getpassword(int x, int y, int &x1, int &y1) {
	bool flag = false;
	int i, j, count = 1;
	for(i = 1; i < 6; i++) {
		int newX, newY;
		for(j = 0; j < 8; j++) {
			newX = x + X[j];
			newY = y + Y[j];
			if(matrix[newX][newY] == str[count] && !outofrange(newX, newY)) {
				x = newX;
				y = newY;
				count++;
				break;
			}
		}
		if(count == 6) {
			flag = true;
			x1 = newX;
			y1 = newY;
			break;
		}
	}
	return flag;
}
int main() {
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int Sx, Sy, i, j;
	bool flag = false;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			if(matrix[i][j] == 'D') flag = getpassword(i, j, Sx, Sy);
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) {
		cout << i << ' ' << j << endl;
		cout << Sx << ' ' << Sy << endl << Sx + Sy + i + j;
	} else cout << str;
}
