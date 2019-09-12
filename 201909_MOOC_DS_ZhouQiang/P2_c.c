#include <stdio.h>
#include <string.h>
char keyboard[12][8] = {
	"0 ",
	"1,.?!", "2ABC", "3DEF", 
	"4GHI", "5JKL", "6MNO",
	"7PQRS", "8TUV", "9WXYZ",
};
int main(int argc, char const *argv[]) {
	char str[505];
	while(scanf("%s", str) != EOF) {
		int len = strlen(str);
		switch(str[0]) {
			case '0': {
				if(len % 2 == 0) len = 2;
				else if(len % 2 != 0) len %= 2;
				break;
			}
			case '1':
			case '7':
			case '9': {
				if(len % 5 == 0) len = 5;
				else if(len % 5 != 0) len %= 5;
				break;
			}
			default: {
				if(len % 4 == 0) len = 4;
				else if(len % 4 != 0) len %= 4;
				break;
			}
		}
		printf("%c", keyboard[str[0] - '0'][len - 1]);
	}
	return 0;
}
