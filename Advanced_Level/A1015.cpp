#include <cstdio>
#include <cmath>

int Reverse(int number, int radix) {
	int a[32], temp = number, count = 0, ret = 0;
	while(temp) {
		a[count++] = temp % radix;
		temp /= radix;
	}
	for(int i = 0; i < count; i++) {
		ret = ret * radix + a[i];
	}
	return ret;
}

bool isPrime(int n) {
	if(n <= 1 || (n % 2 == 0 && n != 2)) {
		return false;
	} else {
		for(int i = 3; i <= sqrt(n); i += 2) {
			if(n % i == 0) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int n, d;
	while(1) {
		scanf("%d", &n);
		if(n < 0) break;
		scanf("%d", &d);
		if(isPrime(n) && isPrime(Reverse(n, d))) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
