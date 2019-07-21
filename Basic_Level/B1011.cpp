#include <cstdio>

int main(int argc, char const *argv[]) {
	int T, i=1;
	scanf("%d", &T);
	long long a, b, c;
	while(T--) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a + b > c) {
			printf("Case #%d: true\n", i++);
		} else {
			printf("Case #%d: false\n", i++);
		}
	}
	return 0;
}
