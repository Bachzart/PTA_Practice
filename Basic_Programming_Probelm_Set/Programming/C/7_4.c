#include <stdio.h>

int main(int argc, char const *argv[])
{
	int BCD;
	scanf("%d", &BCD);
	// BCD = 12;
	int units, tens;
	units = BCD%16;
	tens = BCD/16*10+units;
	printf("%d\n", tens);
	return 0;
}