#include <stdio.h>

int main() {
	int wrongnum, bcd;
	scanf("%d", &wrongnum);
	bcd = wrongnum / 16 * 10 + wrongnum % 16;
	printf("%d", bcd);
	return 0;
}
