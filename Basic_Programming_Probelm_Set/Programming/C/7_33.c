#include <stdio.h>
int gcd(int a, int b);
int lcm(int a, int b);
int main(int argc, char const *argv[])
{
	int a1,b1,a2,b2;
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	int member,denominator,LCM,GCD;
	LCM=lcm(b1, b2);
	member=a1*LCM/b1 + a2*LCM/b2;
	denominator=LCM;
	GCD=gcd(member, denominator);
	if(denominator/GCD == 1){
		printf("%d\n", member/GCD);
	}else{
		printf("%d/%d\n", member/GCD, denominator/GCD);
	}
	return 0;
}
int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a);
}
int lcm(int a, int b)
{
	return a*b/gcd(a, b);
}