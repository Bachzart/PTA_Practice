#include <stdio.h>

int main() {
	double journey, fee = 0;
	int time;
	scanf("%lf %d", &journey, &time);
	if(journey <= 3) fee = 10.0;
	else if(journey <= 10) fee = 10.0 + (journey - 3.0) * 2.0;
	else fee = 24.0 + (journey - 10.0) * 3.0;
	if(time >= 5) fee += time / 5 * 2;
	printf("%.0lf", fee);
	return 0;
}
