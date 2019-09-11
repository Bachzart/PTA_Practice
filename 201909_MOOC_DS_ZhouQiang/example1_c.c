#include <stdio.h>
int m, n, area[25][25];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
int outofrange(int x, int y) {
	if(x < 0 || x > m - 1 || y < 0 || y > n - 1) return 1;
	return 0;
}
int main(int argc, char const *argv[]) {
	scanf("%d %d", &m, &n);
	int i, j;
	getchar();
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			area[i][j] = getchar() == '0' ? 0 : 2;
		}
		getchar();
	}
	int k, x, y;
	scanf("%d", &k);
	while(k--) {
		scanf("%d %d", &x, &y);
		int count = 0;
		if(area[x][y] >= 1) {
			area[x][y] = 0;
			count++;
		}
		for(i = 0; i < 4; i++) {
			int newX = x + X[i];
			int newY = y + Y[i];
			if(area[newX][newY] && !outofrange(newX, newY)) {
				area[newX][newY]--;
				if(area[newX][newY] == 0) count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
