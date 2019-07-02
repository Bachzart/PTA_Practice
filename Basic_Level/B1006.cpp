#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, num, unit, tens, hundred;
	scanf("%d", &num);
	unit = num % 10;
	tens = num / 10 % 10;
	hundred = num / 100;
	// printf("unit=%d, tens=%d, hundred=%d\n", unit, tens, hundred);
	for(i=0; i<hundred; i++)
	{
		printf("B");
	}
	for(i=0; i<tens; i++)
	{
		printf("S");
	}
	for(i=1; i<=unit; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	return 0;
}