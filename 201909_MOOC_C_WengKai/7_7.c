#include <stdio.h>

int main() {
	int c, f;
	scanf("%d", &f);
	c = 5 * (f - 32) / 9;
	printf("Celsius = %d", c);
	return 0;
} 
