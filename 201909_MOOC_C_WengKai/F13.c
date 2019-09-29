#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}

char *getmonth( int n ) {
	if(n < 1 || n > 12) return NULL;
	char *Month[13] = {
		"",
		"January", "February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November", "December",  
	};
	char *month = Month[n];
	return month;
}
