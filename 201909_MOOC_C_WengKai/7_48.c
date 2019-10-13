#include <stdio.h>

int main() {
	int n, m, i;
	scanf("%d %d", &m, &n);
	double result = 1.0;
	for(i = n; i >= n - m + 1; i--) {
		result *= i;
	}
	for(i = 2; i <= m; i++) {
		result /= i;
	}
	printf("result = %.0lf", result);
	return 0;
}
