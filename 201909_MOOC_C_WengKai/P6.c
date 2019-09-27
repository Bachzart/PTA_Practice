#include <stdio.h>

int main() {
	int foot, inch, cm;
	scanf("%d", &cm);
	foot = cm / 30.48;
	inch = cm / 2.54 - 12 * foot;
	printf("%d %d", foot, inch);
	return 0;
}
