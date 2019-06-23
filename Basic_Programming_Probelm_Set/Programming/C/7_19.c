#include <stdio.h>

int main(int argc, char const *argv[])
{
	int y,f,n,flag=0;
	// scanf("%d", &n);
	n=23;
	for(y=0; y<50; y++)
	{
		for(f=0; f<100; f++)
		{
			if(98*f - 199*y == n){
				printf("%d.%d\n", y, f);
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