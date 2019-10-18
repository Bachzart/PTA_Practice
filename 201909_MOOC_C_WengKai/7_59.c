#include <stdio.h>

int main() {
	int len = 0;
	char str[100], c;
	while((c = getchar()) != '\n') {
		str[len++] = c;
	}
	int i = len - 1;
	for(; i >= 0; i--) {
		printf("%c", str[i]);
	}
	return 0;
}
