#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char s1[85],s2[85];
	gets(s1);
	gets(s2);
	int len1=strlen(s1),len2=strlen(s2);
	int i,k;
	for(k=0; k<len1; k++)
	{
		for(i=0; i<len1; i++)
		{
			if(s1[i] == s2[0]){
				int temp=i,flag=1,j;
				for(i+=1,j=1; j<len2; i++,j++)
				{
					if(s1[i] != s2[j]){
						flag=0;
						break;
					}
				}
				if(!flag){
					i=temp;
				}else{
					for(j=temp; i<len1; j++,i++)
					{
						s1[j]=s1[i];
					}
					len1=len1-len2;
					s1[len1]='\0';
				}
				i=temp;
			}
		}
	}
	printf("%s\n", s1);
	return 0;
}