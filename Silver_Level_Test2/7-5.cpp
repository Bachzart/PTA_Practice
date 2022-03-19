#include <cstdio>

int main() {
	int a, b, sum = 0, i;
	scanf("%d %d", &a, &b);
	for(i = 0; a <= b; a++) {
		printf("%5d", a);
		sum += a;
		i++;
		if(i == 5) {
			printf("\n");
			i = 0;
		}
	}
	
	if(i != 0) printf("\n");
	printf("Sum = %d\n", sum);
	return 0;
}
