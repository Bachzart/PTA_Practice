#include <cstdio>
#include <cmath>
typedef enum{ false, true} bool;

bool IsPrime(int n);

int main(int argc, char const *argv[]) {
	int i, N, count = 0;
	scanf("%d", &N);
	for(i = 2; i <= N - 2; i++) {
		if(IsPrime(i) && IsPrime(i + 2)) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}

bool IsPrime(int n) {
	bool flag = true;
	if(n <= 1 || n % 2 == 0) {
		flag = false;
	} else {
		int i;
		for(i = 3; i <= (int)sqrt(n); i+=2) {
			if(n % i == 0) {
				flag = false;
				break;
			}
		}
	} 
	return flag;
}
