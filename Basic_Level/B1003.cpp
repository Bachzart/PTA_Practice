#include <stdio.h>
#include <string.h>
int select_str(char s[], int length); 

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	char str[105];
	while(n--)
	{
		scanf("%s", str);
		int left, mid, right;
		left = mid = right = 0;
		int i, cnt, len = strlen(str);
		//calculate the number of 'A' in different area.
		for(i=0; i<len; i++)
		{
			if(str[i] != 'P') left++;
			else break;
		}
		for(i=0, cnt=0; i<len; i++)
		{
			if(str[i] != 'T') cnt++;
			else{
				mid = cnt - left - 1;	//subtract the number of 'P' 
				right = len - cnt - 1;	//subtract the number of 'T'
				break;
			}
		}
//		printf("left=%d, mid=%d, right=%d\n", left, mid, right);	//output the number of 'A' in different area.
		if(select_str(str, len)){
			if(!mid) printf("NO\n");
			else{
				if(left * mid == right){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

int select_str(char s[], int length)
{
	//when the string has other chars dislike 'P' or 'A' or 'T', the string is wrong. 
	int i, flag=1;
	for(i=0; i<length; i++)
	{
		if(s[i] != 'P' && s[i] != 'A' && s[i] != 'T'){
			flag=0;
			break;
		}
	}
	return flag;
}
