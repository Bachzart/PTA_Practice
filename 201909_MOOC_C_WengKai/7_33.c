#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isprime(int n) {
	if(n <= 1) return false;
	else {
		int i, sqr = sqrt(n);
		bool flag = true;
		for(i = 2; i <= sqr; ++i) {
			if(n % i == 0) {
				flag = false;
				break;
			}
		}
		return flag;
	}
}
int main() {
	int m, n, sum = 0, count = 0;
	scanf("%d %d", &m, &n);
	while(m <= n) {
		if(isprime(m)) {
			sum += m;
			count++;
		}
		m++;
	}
	printf("%d %d", count, sum);
	return 0;
}
