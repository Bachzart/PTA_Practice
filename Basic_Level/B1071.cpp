#include <stdio.h>
#define MAXK 100

int main(int argc, char const *argv[]) {
	int T, K, n1, b, t, n2, x, system_result;
	scanf("%d %d", &T, &K);
	x = T;
	while(K-- && x) {
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if(t > x) {
			printf("Not enough tokens.  Total = %d.\n", x);
			continue;
		}
		if(n2 > n1) {
			system_result = 1;
		} else {
			system_result = 0;
		}
		if(system_result == b) {
			x += t;
			printf("Win %d!  Total = %d.\n", t, x);
		} else {
			x -= t;
			printf("Lose %d.  Total = %d.\n", t, x);
		}
	}
	if(x <= 0) {
		printf("Game Over.\n");
	}
	return 0;
}
