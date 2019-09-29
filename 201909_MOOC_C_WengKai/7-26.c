#include <stdio.h>
int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d", gcd(a, b), a * b / gcd(a, b));
	return 0;
}
