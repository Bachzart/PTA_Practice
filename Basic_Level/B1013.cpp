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
