#include <stdio.h>
int mylen(char const *s1);
int main(int argc, char const *argv[])
{
	char str1[105];
	char str2[105];
	gets(str1);
	int N,i=1;
	scanf("%d", &N);
	// printf("str1=%s, N=%d\n", str1, N);
	char* p=str1;
	char* q=str2;
	int len=mylen(p);
	for(p+=(N%len); *p != '\0'; p++, q++)
	{
		*q=*p;
	}
	p=str1;
	for(i=1; i<=(N%len); i++, p++, q++)
	{
		*q=*p;
	}
	*q='\0';
	printf("%s\n", str2);
	/* method 2: use one char_array
	int i=0,len=mylen(str);
	char* p=str;
	printf("%s", p+(N%len);
	p=str;
	for(; i<(N%len); i++,p++)
	{
		printf("%c", *p);
	}
	printf("\n");
	*/
	return 0;
}
int mylen(char const *s1)
{
	int len=0;
	while(*s1)
	{
		s1++;
		len++;
	}
	return len;
}
