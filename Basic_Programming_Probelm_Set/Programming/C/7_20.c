#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	// N = 4;
	int i,j;
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=i; j++)
		{
			printf("%d*%d=%-4d", j, i, i*j);
		}
		printf("\n");
	}
	return 0;
}