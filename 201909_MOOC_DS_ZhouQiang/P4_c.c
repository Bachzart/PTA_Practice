#include <stdio.h>
#include <stdbool.h>
int m, n;
char matrix[20][20];
int X[10] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Y[10] = {-1, -1, -1, 0, 0, 1, 1, 1};
char str[] = "DSWYBS";
bool outofrange(int x, int y) {
	if(x < 0 || x > m - 1 || y < 0 || y > n - 1) return 1;
	else return 0;
}
bool getpassword(int x, int y, int *x1, int *y1) {
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
			*x1 = newX;
			*y1 = newY;
			break;
		}
	}
	return flag;
}
int main() {
	scanf("%d %d%*c", &m, &n);
	int i, j;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			matrix[i][j] = getchar();
		}
		getchar();
	}
	int Sx, Sy;
	bool flag = false;
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			if(matrix[i][j] == 'D') flag = getpassword(i, j, &Sx, &Sy);
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) printf("%d %d\n%d %d\n%d", i, j, Sx, Sy, i + j + Sx + Sy);
	else printf("%s", str);
	return 0;
} 
