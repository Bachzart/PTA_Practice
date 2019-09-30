#include <stdio.h>

int main() {
	int mm, dd, yy;
	scanf("%d-%d-%d", &mm, &dd, &yy);
	printf("%d-%02d-%02d", yy, mm, dd);
	return 0;
}
