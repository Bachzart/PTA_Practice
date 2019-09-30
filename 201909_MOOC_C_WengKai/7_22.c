#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a != b) {
		if(a != c) putchar('A');
		else putchar('B');
	} else putchar('C');
	return 0;
}
