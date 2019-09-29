#include <stdio.h>

int main() {
	int start, passtime, end;
	scanf("%d %d", &start, &passtime);
	int hour, minute = start / 100 * 60 + start % 100 + passtime;
	hour = minute / 60;
	minute %= 60;
	end = hour * 100 + minute;
	printf("%d", end);
	return 0;
}

/*
some samples:
in:
1120 110
out:
1310

in:
1120 -30
out:
1050

*/
