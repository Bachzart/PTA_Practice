#include <stdio.h>
int main(int argc, char const *argv[])
{
	char num[100];
	scanf("%s", num);
	char *p = num;
	if(*p == '-'){
		printf("fu ");
		p++;
	}
	for(; *p != '\0'; p++)
	{
		switch(*p)
		{
			case '0': printf("ling");break;
			case '1': printf("yi");break;
			case '2': printf("er");break;
			case '3': printf("san");break;
			case '4': printf("si");break;
			case '5': printf("wu");break;
			case '6': printf("liu");break;
			case '7': printf("qi");break;
			case '8': printf("ba");break;
			case '9': printf("jiu");break;
			default: continue;
		}
		if(*(p+1) == '\0') printf("\n");
		else printf(" ");
	}
	return 0;
}
