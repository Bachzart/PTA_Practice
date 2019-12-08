#include <stdio.h>

int main() {
	int n, tmp, max, index = 0;
	scanf("%d%d", &n, &max);
	for(int i = 1; i < n; i++) {
		scanf("%d", &tmp);
		if(tmp > max) {
			index = i;
			max = tmp;
		}
	}
	printf("%d %d", max, index);
	return 0;
} 
