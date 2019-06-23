#include <stdio.h>

int main(int argc, char const *argv[])
{
	int start_time, pass_time;
	// scanf("%d %d", &start_time, &pass_time);
	start_time = 1120; pass_time = 110;
	int hours, minutes;
	hours = start_time / 100;
	minutes = start_time - hours*100;
	int end_time = hours*60 + minutes + pass_time;
	printf("hours=%d, minutes=%d, end_time=%d\n", hours, minutes, end_time);
	printf("%d%02d\n", end_time/60, end_time%60);
	return 0;
}