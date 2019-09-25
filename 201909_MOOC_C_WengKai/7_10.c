#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = ", a, b);
	if(a % b == 0) printf("%d", a / b);
	else printf("%.2f", 1.0 * a / b);
	return 0;
}
