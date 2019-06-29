#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *Week[7] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN",
};

int Hours[31] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
0, 0, 0, 0, 0, 0, 0,
10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

int main(int argc, char const *argv[]) {
	char Str[5][65];
	scanf("%s\n%s\n%s\n%s", Str[1], Str[2], Str[3], Str[4]);
	int i, len1 = strlen(Str[1]), len2 = strlen(Str[2]), flag = 0, j;
	for(i = 0; ; i++) {
		if(!flag && Str[1][i] == Str[2][i] && ('A' <= Str[1][i] && Str[1][i] <= 'G')) {
			printf("%s ", Week[Str[1][i] - 'A']);
			flag = 1;
			continue;
		}
		if(flag && Str[1][i] == Str[2][i] && \
		 (isdigit(Str[1][i]) || ('A' <= Str[1][i] && Str[1][i] <= 'N')) ) {
			printf("%02d:", Hours[Str[1][i] - '0']);
			break;
		}
	}
	len1 = strlen(Str[3]), len2 = strlen(Str[4]);
	for(j = 0; ; j++) {
		if(Str[3][j] == Str[4][j] && isalpha(Str[3][j])) {
			printf("%02d\n", j);
			break;
		}
	}
	return 0;
}
