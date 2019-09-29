#include <stdio.h>

int main() {
	int sum, t;
	while(scanf("%d", &t) != EOF && t > 0) {
		if(t % 2) sum += t;
	}
	printf("%d", sum);
	return 0;
}
