#include <cstdio>

int main(int argc, char const *argv[]) {
	long long A, B, D, digit[50] = {0}, count = 0;
	scanf("%lld %lld %lld", &A, &B, &D);
	A += B;
	while(A) {
		digit[count++] = A % D;
		A /= D;
	}
	if(count) {
		for(count--; count >= 0; count--) {
			printf("%lld", digit[count]);
		}
	} else {
		printf("0");
	}
	putchar('\n');
	return 0;
}
