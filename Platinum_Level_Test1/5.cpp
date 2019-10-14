#include <stdio.h>

int main(int argc, char const *argv[]) {
	int Position[100][10][10];
	int i, j, k, N, Teams[100], MaxNumTeam = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &Teams[i]);
		if(Teams[i] > MaxNumTeam) {
			MaxNumTeam = Teams[i];
		}
	}
	int last_school = -1, num = 0;
	for(j = 0; j < MaxNumTeam; j++) {
		for(k = 0; k < 10; k++) {
			for(i = 0; i < N; i++) {
				if(j <= Teams[i] - 1) {
					if(last_school == i) {
						num += 2;
					} else {
						num++;
					}
					Position[i][j][k] = num;
					last_school = i;
				}
			}
		}
	}
	for(i = 0; i < N; i++) {
		printf("#%d\n", i + 1);
		for(j = 0; j < Teams[i]; j++) {
			for(k = 0; k < 10; k++) {
				printf("%d", Position[i][j][k]);
				if(k != 9) {
					putchar(' ');
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
