#include <stdio.h>

int main() {
	int n, tmp, i, cnt = 1;
	scanf("%d", &n);
	tmp = n;
	for(i = 1; cnt < 2; i++) {
		int digit_sum = 0; 
		while(tmp) {
			digit_sum += tmp % 10;
			tmp /= 10;
		}
		tmp = digit_sum * 3 + 1; 
		printf("%d:%d\n", i, tmp);
		if(n == tmp) cnt++;
		n = tmp;
	}
	return 0;
} 
