#include<stdio.h>
typedef struct Fraction{
	int a;
	int b;
}fraction;
int gcd(int a, int b);
int lcm(int a, int b);
int main(int argc, char const *argv[])
{
    int i,N;
    scanf("%d", &N);
	fraction fra[N];
	for(i=0; i<N; i++)
	{
		scanf("%d/%d", &fra[i].a, &fra[i].b);
	}
	int GCD=0, LCM=0;
	long long member=fra[0].a, denominator=fra[0].b;
	for(i=1; i<N; i++)
	{
		GCD=gcd(denominator, fra[i].b);
		LCM=denominator*fra[i].b/GCD;
		member=member*LCM/denominator + fra[i].a*LCM/fra[i].b;
		denominator=LCM;
		GCD=gcd(member, denominator);
		member/=GCD;
		denominator/=GCD;
	}
	denominator*=N;
	GCD=gcd(member, denominator);
	member/=GCD;
	denominator/=GCD;
	if(denominator == 1) printf("%ld\n", member);
	else printf("%ld/%ld\n", member, denominator);
    return 0;
}
int gcd(int a, int b)
{
	return a==0?b:gcd(b%a, a); 
} 
int lcm(int a, int b){
	return a*b/gcd(a, b);
}
