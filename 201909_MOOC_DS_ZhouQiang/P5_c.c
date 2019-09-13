#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
	char str[45];
	scanf("%s", str);
	int i, len = strlen(str);
	for(i = 0; i < len; i++) {
		if(isdigit(str[i])) {
			if(isdigit(str[i + 1]) || str[i + 1] == '.') printf("%c", str[i]);
			else printf("%c\n", str[i]);
		} else {
			if(!isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '-') printf("%c", str[i]);
			else if (isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '.') printf("%c", str[i]);
			else if (!isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '+' && !isdigit(str[i - 2])) printf("%c", str[i]);
			else printf("%c\n", str[i]); 
		}
	}
	return 0;
}

/*
some samples:
32*((2-2)+5)/(+15)
*/
