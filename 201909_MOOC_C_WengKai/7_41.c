#include <stdio.h>

long long factorial(long long n) {
	if(n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main() {
	long long i, n, sum = 0;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++) {
		sum += factorial(i);
	}
	printf("%lld", sum);
	return 0;
}
