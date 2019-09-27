#include <stdio.h>
#include <stdbool.h>

int main() {
	int randomnum, times, num, cnt = 0;
	scanf("%d %d", &randomnum, &times);
	bool flag = false;
	while(scanf("%d", &num) != EOF && num > 0) {
		if(num == randomnum) {
			flag = true;
			break;
		} else if(num > randomnum) {
			printf("Too big\n");
		} else if(num < randomnum) {
			printf("Too small\n");
		}
		cnt++;
		if(cnt == times) break;
	}
	if(flag) {
		switch(cnt + 1) {
			case 1: printf("Bingo!\n"); break;
			case 2:
			case 3: printf("Lucky You!\n"); break;
			default: printf("Good Guess!\n"); break;
		}
	} else printf("Game Over\n");
	return 0;
} 
