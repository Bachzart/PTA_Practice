#include <stdio.h>

int main() {
	double sum = 0.0, item, i, j;
	int n, k;
	scanf("%d", &n);
	for(i = 1.0, j = 2.0, k = 1; k <= n; ++k) {
		item = j / i;
		sum += item;
		item = j;
		j = j + i;
		i = item;
	}
	printf("%.2f", sum);
	return 0;
}
