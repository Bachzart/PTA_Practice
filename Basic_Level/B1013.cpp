// method 1: use Eratosthenes
#include <cstdio>
const int MAXN = 1000001;
int prime[MAXN], pNum = 0;
bool p[MAXN] = {false};

void filterPrime(int n) {
	for(int i = 2; i < MAXN; i++) {
		if(p[i] == false) {
			prime[pNum++] = i;
			if(pNum >= n) break;
			for(int j = i + i; j < MAXN; j += i) {
				p[j] = true;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int m, n, count = 0;
	scanf("%d %d", &m, &n);
	filterPrime(n);
	for(int i = m; i <= n; i++) {
		printf("%d", prime[i - 1]);
		count++;
		if(count % 10 != 0 && i < n) putchar(' ');
		else putchar('\n');
	}
	return 0;
}

/* method 2: normal ways
#include <cstdio>
#include <cmath>
#define MAX 15000

bool IsPrime(int number);

int main(int argc, char const *argv[]) {
	int M, N, Prime[MAX];
	scanf("%d %d", &M, &N);
	int i, count = 2;
	Prime[1] = 2;
	for(i = 3; i <= 105000; i++) {
		if( IsPrime(i) ) {
			Prime[count++] = i;
		}
	}
	count = 0;
	for(; M < N; M++) {
		printf("%d", Prime[M]);
		count++;
		if(count % 10 == 0) {
			putchar('\n');
		} else {
			putchar(' ');
		}
	}
	printf("%d\n", Prime[M]);
	return 0;
} 

bool IsPrime(int number) {
	bool flag = true;
	if(number <= 1 || number % 2 == 0) {
		flag = false;
	} else {
		int i;
		for(i = 3; i <= (int)sqrt(number); i+=2) {
			if(number % i == 0) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
*/
