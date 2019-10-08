#include <stdio.h>

int main() {
	int i = 1;
	while(1) {
		i++;
		if(i % 5 == 1 && i % 6 == 5 && i % 7 == 4 && i % 11 == 10) break;
	}
	printf("%d", i);
	return 0;
}
