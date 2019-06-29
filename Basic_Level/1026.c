#include <stdio.h>
#define CLK_TCK 100

int main(int argc, char const *argv[])
{
	int c1, c2, seconds, minutes, hours;
	scanf("%d %d", &c1, &c2);
	seconds = (c2 - c1 + 50) / CLK_TCK;
	/*
	hours = seconds / 3600;
	seconds -= hours*3600;
	minutes = seconds / 60;
	seconds -= minutes*60;
	*/
	hours = seconds / 3600;
	seconds = seconds % 3600;
	minutes = seconds / 60;
	seconds = seconds % 60;
	printf("%02d:%02d:%02d\n", hours, minutes, seconds);
	return 0;
}
