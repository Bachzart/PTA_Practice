#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[]) {
	ll n;
	scanf("%lld", &n);
	ll sqr = sqrt(n), ansI = 0, ansLen = 0;
	for(ll i = 2; i <= sqr; i++) {
		ll temp = 1, j = i;
		while(1) {
			temp *= j;
			if(n % temp != 0) break;
			if(j - i + 1 > ansLen) {
				ansI = i;
				ansLen = j - i + 1;
			}
			j++;
		}
	}
	if(ansLen == 0) {
		printf("1\n%lld\n", n);
	} else {
		printf("%lld\n", ansLen);
		for(ll i = 0; i < ansLen; i++) {
			printf("%lld", ansI + i);
			if(i < ansLen - 1) putchar('*');
		}
	}
	return 0;
}
