#include <cstdio>

struct money {
	int g, s, k;
} P, A, Result;

bool Bigger(money a, money b);
money Substract(money big, money small);

int main(int argc, char const *argv[]) {
	scanf("%d.%d.%d %d.%d.%d", &P.g, &P.k, &P.s, &A.g, &A.k, &A.s);
	if(Bigger(P, A)) {
		Result = Substract(P, A);
		if(!Result.g && !Result.k && !Result.s) printf("0.0.0\n");
		else printf("-%d.%d.%d\n", Result.g, Result.k, Result.s);
	} else {
		Result = Substract(A, P);
		printf("%d.%d.%d\n", Result.g, Result.k, Result.s);
	}
	return 0;
}

bool Bigger(money a, money b) {
	if(a.g != b.g) return a.g >= b.g;
	else if(a.k != b.k) return a.k >= b.k;
	else return a.s >= b.s;
}

money Substract(money big, money small) {
	money ret;
	if(big.s >= small.s) {
		ret.s = big.s - small.s;
	} else {
		ret.s = big.s + 29 - small.s;
		big.k--;
	}
	if(big.k >= small.k) {
		ret.k = big.k - small.k;
	} else {
		ret.k = big.k + 17 - small.k;
		big.g--;
	}
	ret.g = big.g - small.g;
	return ret;
}
