#include <stdio.h>

int main(int argc, char const *argv[])
{
	int foot,inch,centimeters;
	scanf("%d", &centimeters);
	// centimeters = 170;
	foot = centimeters / 30.48;
	inch = centimeters / 2.54 - 12*foot;
	printf("%d %d\n", foot, inch);
	return 0;
}