#include <cstdio>
#include <cmath>
const int maxn = 100010;

bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = sqrt(n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int prime[maxn], pNum = 0;
void filterPrime() {
	for(int i = 1; i < maxn; i++) {
		if(isPrime(i) == true) {
			prime[pNum++] = i;
		}
	}
}
struct factor{
	int x, cnt;
} fac[11];

int main(int argc, char const *argv[]) {
	filterPrime();
	int n, num = 0;
	scanf("%d", &n);
	if(n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = sqrt(n);
		for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
			if(n % prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n % prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if(n == 1) break;
		}
		if(n != 1) {
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for(int i = 0; i < num; i++) {
			if(i > 0) putchar('*');
			printf("%d", fac[i].x);
			if(fac[i].cnt > 1) {
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}

/* C++ */
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
map<long long, int> factors;
bool isprime(long long n) {
	if(n <= 1) return false;
	else {
		for(long long i = 2; i <= sqrt(n); i++) {
			if(n % i == 0) return false;
		}
		return true;
	}
}
int main() {
	long long n, tmp, sqr;
	scanf("%lld", &n);
	printf("%lld=", n);
	if(n == 1) printf("%lld", n);
	else {
		tmp = n;
		sqr = sqrt(n);
		for(long long fa = 2; fa <= sqr; fa++) {
			if(tmp == 1) break;
			if(isprime(fa)) {
				while(tmp % fa == 0) {
					factors[fa]++;
					tmp /= fa;
				}
			}
		}
		if(factors.size() == 0) printf("%lld", n);
		else {
			auto it = factors.begin();
			while(it != factors.end()) {
				printf("%lld", it->first);
				if(it->second != 1) printf("^%d", it->second);
				it++;
				if(it != factors.end()) printf("*");
			}
		}
	}
	return 0;
}