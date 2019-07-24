#include <cstdio>
#include <cmath>
const int MAXM = 10005;
bool isPrime(int n) {
	if(n <= 1 || (n != 2 && n % 2 == 0)) {
		return false;
	} else {
		for(int i = 3; i <= sqrt(n); i += 2) {
			if(n % i == 0) return false;
		}
	}
	return true;
}

int nearPrime(int n) {
	while(!isPrime(n)) n++;
	return n;
}
int hashTable[MAXM] = {0}; 

int main(int argc, char const *argv[]) {
	int m, n, temp, index;
	scanf("%d %d", &m, &n);
	m = nearPrime(m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		index = temp % m;
		if(hashTable[index] == 0) {
			hashTable[index] = temp;
			printf("%d", index);
		} else {
			int step;
			for(step = 1; step < m; step++) {
				index = (temp + step * step) % m;
				if(hashTable[index] == 0) {
					hashTable[index] = temp;
					printf("%d", index);
					break;
				}
			}
			if(step >= m) {
				printf("-");
			}
		}
		if(i < n - 1) putchar(' ');
	}
	return 0;
}
