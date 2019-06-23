#include <stdio.h>
int gcd(int a, int b);

int main(int argc, char const *argv[])
{
	int member,denominator;
	// scanf("%d/%d", &member, &denominator);
	member=66, denominator=120;
	printf("%d/%d\n", member/gcd(member, denominator), denominator/gcd(member, denominator));
	return 0;
}
int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}
