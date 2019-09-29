#include <stdio.h>

int main() {
	int hashTable[128] = {0};
	char c;
	while((c = getchar()) != '\n') {
		hashTable[c]++;
	}
	int i;
	for(i = 0; i < 128; i++) {
		if(hashTable[i]) putchar(i);
	}
	return 0;
}
