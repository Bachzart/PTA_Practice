#include <stdio.h>

int main() {
	int n, sum = 0, digits = 0;;
	scanf("%d", &n);
	do{
		sum += n % 10;
		n /= 10;
		digits++;
	} while(n);
	printf("%d %d", digits, sum); 
	return 0;
}
