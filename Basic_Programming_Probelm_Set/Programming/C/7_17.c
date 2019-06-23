#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N, U, D;
	scanf("%d %d %d", &N, &U, &D);
	// N=12, U=3, D=1;
	int i,j,times;
	for(i=1,j=0; 1; i++, j++)
	{
		if(i*U-j*D >= N){
			times = i+j;
			break;
		}
	}
	printf("%d\n", times);
	return 0;
}