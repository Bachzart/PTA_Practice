#include <cstdio>
int matrix[105][105] = {0}, n, k, x;;

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	int s = 1;
	for(int i = 1; i <= n; i+=2) {
		for(int j = n - s; j >= 1; j--) {
			matrix[i][j + s] = matrix[i][j];
		}
		for(int j = 1; j <= s; j++) {
			matrix[i][j] = x;
		}
		if(s == k) s = 1;
		else s++;
	}
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		for(int j = 1; j <= n; j++) {
			sum += matrix[j][i];
		}
		printf("%d", sum);
		if(i != n) printf(" ");
	}
	return 0;
}
