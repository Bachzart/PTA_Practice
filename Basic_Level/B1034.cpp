#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Fraction {
	ll up, down;
} f1, f2;

ll gcd(ll a, ll b) {
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
		int d = gcd(abs(result.up), abs(result.down));
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

Fraction Minu(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return Reduction(result);
}

Fraction Mult(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return Reduction(result);
}

Fraction Divide(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return Reduction(result);
}

void printResult(Fraction r) {
	r = Reduction(r);
	if(r.up < 0) printf("(");
	if(r.down == 1) printf("%lld", r.up);
	else if(abs(r.up) > r.down) {
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%lld/%lld", r.up, r.down);
	}
	if(r.up < 0) printf(")");
}

int main(int argc, char const *argv[]) {
	scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
	//add
	printResult(f1);
	printf(" + ");
	printResult(f2);
	printf(" = ");
	printResult(Add(f1, f2));
	putchar('\n');
	
	//minu
	printResult(f1);
	printf(" - ");
	printResult(f2);
	printf(" = ");
	printResult(Minu(f1, f2));
	putchar('\n');

	//mult
	printResult(f1);
	printf(" * ");
	printResult(f2);
	printf(" = ");
	printResult(Mult(f1, f2));
	putchar('\n');
	
	//divide
	printResult(f1);
	printf(" / ");
	printResult(f2);
	printf(" = ");
	if(f2.up == 0) printf("Inf");
	else printResult(Divide(f1, f2));
	return 0;
}
