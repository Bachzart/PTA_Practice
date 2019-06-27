#include <stdio.h>

int main(int argc, char const *argv[]) {
	int count = 0;
	char Str[85][85], c;
	while(1) {
		scanf("%s", Str[++count]);
		c = getchar();
		if(c == '\n') {
			break;
		}
	}
	for(; count > 1; count--) {
		printf("%s ", Str[count]);
	}
	puts(Str[count]);
	return 0;
} 

