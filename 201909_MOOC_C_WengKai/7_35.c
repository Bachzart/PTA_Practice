#include <stdio.h>

int main() {
	int i, n, peach = 1;
	scanf("%d", &n);
	for(i = 1; i < n; i++) {
		peach = 2 * (peach + 1);
	}
	printf("%d", peach);
	return 0;
}
