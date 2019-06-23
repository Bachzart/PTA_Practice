#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
//	N=884;
	int X,Y,flag=0;
	for(Y=100; Y>0; Y--)
	{
		for(X=1; X<=Y; X++)
		{
			if(X*X + Y*Y == N && (X*Y) < 5000){
				printf("%d %d\n", X, Y);
				flag=1;
				break;
			}
		}
	}
	if(!flag){
		printf("No Solution\n");
	}
	return 0;
}
