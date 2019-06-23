#include <stdio.h>

int main(int argc, char const *argv[])
{
	int A, B, Sum=0, i;
	scanf("%d %d", &A, &B);
	// A = -3; B = 8;
	for(i=0; A<=B; A++, i++)
	{
		if(i % 5 == 0 && i != 0) printf("\n");
		printf("%5d", A);
		Sum+=A;
	}
	printf("\nSum = %d\n", Sum);
	return 0;
}