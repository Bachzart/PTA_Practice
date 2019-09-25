#include <stdio.h>

int main() {
	double y, x;
	scanf("%lf", &x);
	if(x <= 15.0) y = 4.0 * x / 3.0;
	else y = 2.5 * x - 17.5;
	printf("%.2f", y);
	return 0;
}
