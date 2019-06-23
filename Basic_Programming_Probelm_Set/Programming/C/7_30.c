#include <stdio.h>
#include <string.h>

/* method 1: define a new struct that save string and the serial number of every string. Then use 
the array to purplesort this array, so we can get a sequence by purplesort. But this algorithm can
not dispose this string like 'abc'/'aabc'.
typedef struct string_num
{
	int first_letter;
	char string[12];
}string_num;
int main(int argc, char const *argv[])
{
	int N,K;
	scanf("%d %d", &N, &K);
	string_num sequence[105];
	int i,j;
	for(i=1; i<=N; i++)
	{
		scanf("%s", sequence[i].string);
		sequence[i].first_letter=sequence[i].string[0] - 'a' + 1;
	}
	int num_array[105];
	for(i=1; i<=N; i++)
	{
		num_array[i]=sequence[i].first_letter;
	}
	for(i=1; i<=K; i++)
	{
		int temp;
		for(j=1; j<=N-i; j++)
		{
			if(num_array[j] > num_array[j+1]){
				temp=num_array[j];
				num_array[j]=num_array[j+1];
				num_array[j+1]=temp;
			}
		}
	}
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
		{
			if(num_array[i] == sequence[j].first_letter)
			{
				printf("%s\n", sequence[j].string);
				break;
			}
		}
	}
	return 0;
}
*/
/* method 2: use the string function in 'string.h'.
int main(int argc, char const *argv[])
{
	int N,K;
	scanf("%d %d", &N, &K);
	char s[N][11];
	int i,j;
	for(i=0; i<N; i++)
	{
		scanf("%s", s[i]);
	}
	char str_temp[11];
	for(i=1; i<=K; i++)
	{
		for(j=0; j<N-i; j++)
		{
			if(strcmp(s[j], s[j+1]) > 0)
			{
				strcpy(str_temp, s[j]);
				strcpy(s[j], s[j+1]);
				strcpy(s[j+1], str_temp);
			}
		}
	}
	for(i=0; i<N; i++)
	{
		puts(s[i]);
	}
	return 0;
}
*/
char* mycpy(char* dst, char* src);
int mycmp(char const *s1, char const *s2);

int main(int argc, char const *argv[])
{
	int N,K;
	scanf("%d %d", &N, &K);
	char str[N][11];
	int i,j;
	for(i=0; i<N; i++)
	{
		scanf("%s", str[i]);
	}
	char temp[11];
	char *p=temp;
	for(i=1; i<=K; i++)
	{
		for(j=0; j<N-i; j++)
		{
			if(mycmp(str[j], str[j+1]) > 0){
				mycpy(p, str[j]);
				mycpy(str[j], str[j+1]);
				mycpy(str[j+1], temp);
			}
		}
	}
	for(i=0; i<N; i++)
	{
		printf("%s\n", str[i]);
	}
	return 0;
}

char* mycpy(char *dst, char *src)
{
	char* ret = dst;
	while(*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return ret;
}

int mycmp(char const *s1, char const *s2)
{
	while(*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return *s1-*s2;
}
