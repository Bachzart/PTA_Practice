#include <cstdio>

int main(int argc, char const *argv[]) {
	int T, K, n1, b, t, n2, remains;
	scanf("%d %d", &T, &K);
	remains = T;
	while(K--) {
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if(remains <= 0) {
			printf("Game Over.\n");
			break;
		}
		if(t > remains) {
			printf("Not enough tokens.  Total = %d.\n", remains);
			continue;
		}
		if((n1 > n2 && b == 0) || (n1 < n2 && b == 1)) {
			remains += t;
			printf("Win %d!  ", t);
		} else {
			remains -= t;
			printf("Lose %d.  ", t);
		}
		printf("Total = %d.\n", remains);
	}
	return 0;
}
