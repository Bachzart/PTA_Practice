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
