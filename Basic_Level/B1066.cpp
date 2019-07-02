#include <stdio.h>
#define MAXN 500
#define MAXM 500

int main(int argc, char const *argv[]) {
	int r, c, M, N, A, B, gray_value;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &gray_value);
	int image_array[MAXM][MAXN];
	for(r = 0; r < M; r++) {
		for(c = 0; c < N; c++) {
			scanf("%d", &image_array[r][c]);
			if(A <= image_array[r][c] && image_array[r][c] <= B) {
				image_array[r][c] = gray_value;
			}
		}
	}
	for(r = 0; r < M; r++) {
		for(c = 0; c < N; c++) {
			printf("%03d", image_array[r][c]);
			if(c == N-1) {
				putchar('\n');
			} else {
				putchar(' ');
			}
		}
	}
	return 0;
}
