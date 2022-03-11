#include <cstdio>
#include <cmath>
bool isprime(int a) {
	if(a <= 1) return false;
	else {
		for(int i = 2; i <= sqrt(a); i++) {
			if(a % i == 0) return false;
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	if(isprime(n) && isprime(n - 6)) printf("Yes\n%d", n - 6);
	else if(isprime(n) && isprime(n + 6)) printf("Yes\n%d", n);
	else {
		while(n++) {
			if(isprime(n) && isprime(n - 6) || isprime(n) && isprime(n + 6)) break;
		}
		printf("No\n%d", n);
	}
	return 0;
}
