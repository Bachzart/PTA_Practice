#include <stdio.h>

int main() {
	int n, a1 = 1, a2 = 1, sum = 0;
	scanf("%d", &n);
	int i = 3;
	while(sum < n) {
		sum = a1 + a2;
		a1 = a2;
		a2 = sum;
		i++;
	}
	if(n <= 1) printf("1");
	else printf("%d", i - 1);
	return 0;
}
/*
fibonacci sequence:
   1  2  3  4  5  6  7  8  9
   1  1  2  3  5  8  13  21  34
   
*/

