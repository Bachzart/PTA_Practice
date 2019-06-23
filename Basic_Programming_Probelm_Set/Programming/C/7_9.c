#include <stdio.h>

int main(int argc, char const *argv[])
{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	// A=1;B=1;C=2;
	if(A != B && A != C) printf("A\n");
	if(B != A && B != C) printf("B\n");
	if(C != A && C != B) printf("C\n");
	return 0;
}