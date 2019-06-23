#include <stdio.h>

int main(int argc, char const *argv[])
{
	float a,b;
	int d;
	char c;
	scanf("%f %d %c %f", &a, &d, &c, &b);
	printf("%c %d %.2f %.2f\n", c, d, a, b);
	return 0;
}