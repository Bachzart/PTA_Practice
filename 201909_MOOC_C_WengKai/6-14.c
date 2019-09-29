#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

int getindex( char *s ) {
	char *Week[8] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", 
		"Thursday", "Friday", "Saturday", 
	};
	int index;
	for(index = 0; index < 7; index++) {
		if(strcmp(Week[index], s) == 0) break; 
	}
	if(index > 6) return -1;
	else return index;
}
