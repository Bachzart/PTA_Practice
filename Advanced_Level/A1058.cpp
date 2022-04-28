#include <cstdio>

struct money{
	int g, k, s;
} A, B, Result;

int main(int argc, char const *argv[]) {
	scanf("%d.%d.%d %d.%d.%d", &A.g, &A.s, &A.k, &B.g, &B.s, &B.k);
	Result.g = A.g + B.g;
	Result.k = A.k + B.k;
	Result.s = A.s + B.s;
	if(Result.k >= 29) {
		Result.s += (Result.k / 29);
		Result.k %= 29;
	}
	if(Result.s >= 17) {
		Result.g += (Result.s / 17);
		Result.s %= 17;
	}
	printf("%d.%d.%d\n", Result.g, Result.s, Result.k);
	return 0;
}

/* simplification */
#include <cstdio>

int main() {
	long long g1, s1, k1, g2, s2, k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
	k1 += s1 * 29 + g1 * 29 * 17;
	k2 += s2 * 29 + g2 * 29 * 17;
	k1 += k2;
	g1 = k1 / 29 / 17;
	s1 = k1 / 29 % 17;
	k1 = k1 % 29;
	printf("%lld.%lld.%lld\n", g1, s1, k1);
	return 0;
} 
