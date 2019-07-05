#include <cstdio>
const int MAXN = 10;

int main(int argc, char const *argv[]) {
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum < 0) {
		putchar('-');
		sum = -sum;
	}
	int len = 0, num[MAXN];
	if(sum == 0) {
		num[len++] = sum;
	}
	while(sum) {
		num[len++] = sum % 10;
		sum /= 10;
	}
	for(int i = len - 1; i >= 0; i--) {
		printf("%d", num[i]);
		if(i > 0 && i % 3 == 0) {
			putchar(',');
		}
	}
	return 0;
}
