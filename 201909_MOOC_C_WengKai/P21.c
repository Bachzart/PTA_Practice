#include <stdio.h>

int main() {
	int speed;
	scanf("%d", &speed);
	printf("Speed: ");
	if(speed > 60) printf("%d - Speeding", speed);
	else printf("%d - OK", speed);
	return 0;
}
