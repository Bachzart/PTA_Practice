#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N, i, j;
	char C;
	scanf("%d %c", &N, &C);
	/*actually, you just need to find the place you want print */
	for(i=0; i<(N+1)/2; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i==0 || i==(N-1)/2 || j==0 || j==N-1) putchar(C);
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

/* use 2 dimension array also can solve this problem, but the last test sample
can't pass(runtime error) 
#include <stdio.h> 

int main(int argc, char const *argv[])
{
	int N, i, j;
	char C;
	scanf("%d %c", &N, &C);
	char Square_char[(N+1)/2][N];
	i = j = 0;
	while(j < N)
	{
		Square_char[i][j++] = C;
	}
	j--;
	while(i < (N+1)/2)
	{
		Square_char[++i][j] = C;
	}
	i--;
	while(j >= 0)
	{
		Square_char[i][--j] = C;
	}
	j++;
	while(i > 0)
	{
		Square_char[--i][j] = C;
	}
	
	for(i=0; i<(N+1)/2; i++)
	{
		for(j=0; j<N; j++)
		{
			if(Square_char[i][j] == C) printf("%c", Square_char[i][j]);
			else printf(" ");
		}
		putchar('\n');
	} 
	return 0;
}
*/ 
