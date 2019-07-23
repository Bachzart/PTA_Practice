#include <cstdio>
#include <cstdlib>

typedef struct fraction {
	long long up, down;
} Fraction;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

Fraction Reduction(Fraction result) {
	if(result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0) {
		result.down = 1;
	} else {
		long long d = gcd(abs(result.up), result.down);
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction Add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return Reduction(result);
}

void printResult(Fraction result) {
	Fraction r = Reduction(result);
	if(r.down == 1) printf("%lld", r.up);
	else if(abs(r.up) > r.down) {
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%lld/%lld", r.up, r.down);
	}
}

int main(int argc, char const *argv[]) {
	int N;
	scanf("%d", &N);
	Fraction ans, temp;
	ans.up = 0;
	ans.down = 1;
	while(N--) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		ans = Add(ans, temp);
	}
	printResult(ans);
	return 0;
}
