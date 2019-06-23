#include <stdio.h>

int main(int argc, char const *argv[])
{
	int A;
	scanf("%d", &A);
	// A=2;
	int i, j, k, cnt=0;
	/* method 1: enumerate all the cases
	for(i=A; i<=A+3; i++)
	{
		for(j=A; j<=A+3; j++)
		{
			for(k=A; k<=A+3; k++)
			{
				if(k!=j && k!=i && j!=i){
					printf("%d%d%d", i, j, k);
					cnt++;
					if(cnt%6 == 0) printf("\n");
					else printf(" ");
				}
			}
		}
	}
	*/
	/* method 2: use "continue" to skip the extra cases*/
	for(i=A; i<=A+3; i++)
	{
		for(j=A; j<=A+3; j++)
		{
			if(j == i) continue;
			for(k=A; k<=A+3; k++)
			{
				if(k==i || k==j) continue;
				printf("%d%d%d", i, j, k);
				cnt++;
				if(cnt%6 == 0) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}