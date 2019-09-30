#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] );

int main() {
	char s[MAXS], t[MAXS], *pos;

	ReadString(s);
	ReadString(t);
	pos = search(s, t);
	if ( pos != NULL )
		printf("%d\n", pos - s);
	else
		printf("-1\n");
	return 0;
}

char *search(char *s, char *t) {
	int flag1 = 0, flag2;
	for(; *s != '\0'; s++) {
		flag2 = 1;
		if(*s == *t) {
			char *p1 = s, *p2 = t;
			for(; *p2 != '\0'; p2++, p1++) {
				if(*p2 != *p1) {
					flag2 = 0;
					break;
				}
			}
			if(flag2) {
				flag1 = 1;
				break;
			}
		}
	}
	if(flag1) return s;
	else return NULL;
}

void ReadString( char s[] ) {
	gets(s);
}

/*
some samples:
in:
pprram
ram
out:
3

in:
catcatch
atc
out:
1

in:
ra
ram
out:
-1

*/
