#include <cstdio>
#include <cmath>
bool isprime(int a) {
	if(a <= 1) return false;
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0) return false;
	}
	return true;
}
char num[1005];

int main() {
	int l, k;
	scanf("%d %d%*c", &l, &k);
	scanf("%s", num);
	bool flag = false;
	for(int i = 0; i + k <= l; i++) {
		int number = 0;
		for(int j = i; j < i + k; j++) {
			number = number * 10 + num[j] - '0';
		}
		if(isprime(number)) {
			for(int j = i; j < i + k; j++) {
				printf("%c", num[j]);
			}
			flag = true;
			break;
		}
	}
	if(!flag) printf("404");
	return 0;
}
