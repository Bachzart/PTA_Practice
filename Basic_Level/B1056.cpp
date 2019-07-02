#include <stdio.h>
#define MAXN 10

int main(int argc, char const *argv[]) {
	int i, j, N, Array[MAXN], Sum = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &Array[i]);
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(i == j) {
				continue;
			} else {
				Sum += (Array[i] * 10 + Array[j]);
			}
		}
	}
	printf("%d\n", Sum);
	return 0;
}
