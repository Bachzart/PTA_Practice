#include <cstdio>

int main(int argc, char const *argv[]) {
	long long i, T, A, B, C, Sum;
	scanf("%lld", &T);
	for(i = 1; i <= T; i++) {
		scanf("%lld %lld %lld", &A, &B, &C);
		Sum = A + B;
		bool flag = true;
		printf("Case #");
		if(A > 0 && B > 0 && Sum < 0) {
			flag = true;	//positive overflow 
		} else if(A < 0 && B < 0 && Sum >= 0) {
			flag = false;	//negative overflow
		} else if(Sum > C) {
			flag = true;	//normal 
		} else {
			flag = false;	// A + B <= C
		}
		if(flag) {
			printf("%d: true\n", i);
		} else {
			printf("%d: false\n", i);
		}
	}
	return 0;
}

