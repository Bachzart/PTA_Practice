#include <stdio.h>

int main() {
	double sum = 1.0, item, sign = -1;
	int i, n;
	scanf("%d", &n);
	for(i = 2; i <= n; i++) {
		item = sign * i / (2 * i - 1);
		sum += item;
		sign = - sign;
	}
	printf("%.3f", sum);
	return 0;
}
