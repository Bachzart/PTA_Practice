#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main() {
	int n, i;
	double a[MAXN], x;
	scanf("%d %lf", &n, &x);
	for ( i=0; i<=n; i++ )
		scanf("%lf", &a[i]);
	printf("%.1f\n", f(n, a, x));
	return 0;
}

/*
method 1: use the loop to calculate, Timeout.
double f( int n, double a[], double x )
{
	int i,j;
	double sum=0,X=x;
	sum=a[0]*1.0;
	if(n == 0){
		return sum;
	}else{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<i; j++)
			{
				X*=X;
			}
			sum+=(a[i]*X);
			// printf("i=%d, sum=%.1f, X=%.1f\n", i, sum, X);
			X=x;
		}
	}
	return sum;
}
*/
/* method 2: use the math.*/
double f( int n, double a[], double x ) {
	int i;
	double sum=0,X=x;
	if(n == 0) {
		sum=a[0]*1.0;
	} else {
		sum=a[n]*X + a[n-1];
		for(i=n-2; i>=0; i--) {
			sum=sum*X + a[i];
		}
//		printf("i=%d, sum=%.1f, X=%.1f\n", i, sum, X);
	}
	return sum;
}
