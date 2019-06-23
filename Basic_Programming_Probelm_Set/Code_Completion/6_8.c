#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}
int Factorial( const int N )
{
	int i,ret=1;
	if(N < 0) return 0;
	else if(N == 0) return ret;
	else{
		for(i=1; i<=N; i++)
		{
			ret*=i;
		}
	}
	return ret;
}