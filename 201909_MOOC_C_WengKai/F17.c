#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

char *match( char *s, char ch1, char ch2 ) {
	while(*s != ch1 && *s != '\0') s++;
	char *p1 = s, *p2 = s;
	while(*p2 != ch2 && *p2 != '\0') p2++;
	while(p1 < p2) putchar(*p1++);
	if(*p1 != '\0') printf("%c\n", *p1);
	else putchar('\n');
	return s;
}
