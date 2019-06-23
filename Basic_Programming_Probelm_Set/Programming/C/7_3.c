#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	// n = 700;
	int units, tens, hundred;
	units = n%10;
	tens = n/10%10;
	hundred = n/100;
	// printf("%d %d %d\n", units, tens, hundred);
	printf("%d\n", units*100+tens*10+hundred);
	return 0;
}