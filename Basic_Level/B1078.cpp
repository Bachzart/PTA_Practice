#include <cstdio>
#include <cctype>
char str[2005], mode;

int main() {
	scanf("%c%*c", &mode);
	fgets(str, 2005, stdin);
	if(mode == 'C') {
		for(int i = 0; str[i] != '\0'; i++) {
			char tmp = str[i];
			int count = 1, j;
			for(j = i + 1; str[j] == tmp; j++) {
				count++;
			}
			if(count == 1) printf("%c", tmp);
			else printf("%d%c", count, tmp);
			i = --j;
		}
	} else if(mode == 'D') {
		for(int i = 0; str[i] != '\0'; i++) {
			int count = 0, j;
			if(isdigit(str[i])) {
				count = str[i] - '0';
				for(j = i + 1; isdigit(str[j]); j++) {
					count = count * 10 + str[j] - '0';
				}
				for(int k = 0; k < count; k++) {
					printf("%c", str[j]);
				}
				i = j;
			} else printf("%c", str[i]);
		}
	}
	return 0;
}
