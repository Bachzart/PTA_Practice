#include <stdio.h>

int main(int argc, char const *argv[]) {
	int N, i, j;
	char C;
	scanf("%d %c", &N, &C);
	/*actually, you just need to find the place you want print */
	for(i = 0; i < (N + 1) / 2; i++) {
		for(j = 0; j < N; j++) {
			if(i == 0 || i == (N - 1) / 2 || j == 0 || j == N - 1) putchar(C);
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
