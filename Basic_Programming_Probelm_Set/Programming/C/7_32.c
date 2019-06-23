#include <stdio.h>
#include <string.h>
#define maxn 500005
int main(int argc, char const *argv[])
{
	char str[maxn];
	gets(str);
//	printf("%s\n", str);
	int len=strlen(str);
	int i,j=0,char_cnt=0,next_flag=1,last_flag=1;
	for(i=0; i<len; i++)
	{
		if(str[i] != ' '){
			last_flag=i;
			break;
		}
	}
	for(i=len-1; i>=0; i--)
	{
		if(str[i] != ' '){
			next_flag=0;
			char_cnt++;
		}else if(!next_flag){
			next_flag=1;
			for(j=i+1; j<i+1+char_cnt; j++)
			{
				printf("%c", str[j]);
			}
			if(i+1 != last_flag) printf(" ");
			char_cnt=0;
		}
	}
	for(i=last_flag; i<last_flag+char_cnt; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}