#include <stdio.h>

int main() {
	int i, sum = 0, temp;
	for(i = 0; i < 4; i++) {
		scanf("%d", &temp);
		sum += temp;
	}
	printf("Sum = %d; Average = %.1f", sum, sum / 4.0);
	return 0;
} 
