// way 1
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int A, B, Product, temp, digit, result = 0;
	scanf("%d %d", &A, &B);
	Product = A * B;
	temp = Product;
	while(temp) {
		digit = temp % 10;
		temp /= 10;
		result = result * 10 + digit;
	}
	printf("%d\n", result);
	return 0;
} 

/*
// way 2

#include <cstdio>
char ans[10];

int main() {
	int A, B, C, len = 0;
	scanf("%d %d", &A, &B);
	C = A * B;
	do{
		ans[len++] = C % 10 + '0';
		C /= 10;
	} while(C != 0);
	ans[len] = '\0';
	char *p = ans;
	while(*p == '0') p++;
	puts(p);
	return 0;
}

*/
