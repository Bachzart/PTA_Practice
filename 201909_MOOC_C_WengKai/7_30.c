#include <stdio.h>
char number[10][5] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", 
};
int main() {
	char num[12];
	scanf("%s", num);
	char *p = num;
	while(*p != '\0') {
		if(*p == '-') printf("fu");
		else printf("%s", number[*p - '0']);
		if(*(p + 1) != '\0') putchar(' ');
		p++;
	}
	return 0;
}
