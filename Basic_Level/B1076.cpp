#include <stdio.h>
#define MAXN 105
int Wifi_Password[4] = {1, 2, 3, 4};

int main(int argc, char const *argv[]) {
	int i, N, count = 0;
	scanf("%d%*c", &N);
	char Answers[MAXN], temp, flag;
	for(i = 0; i < 4 * N; i++) {
		scanf("%c-%c%*c", &temp, &flag);
		if(flag == 'T') {
			Answers[count++] = temp;
		}
	}
	for(i = 0; i < count; i++) {
		printf("%d", Wifi_Password[Answers[i] - 'A']);
	}
	putchar('\n');
	return 0;
} 
