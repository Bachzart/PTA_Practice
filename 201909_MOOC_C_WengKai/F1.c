#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime( int p ) {
	if(p <= 1) return 0;
	int i, sqr = sqrt(p), flag = 1;
	for(i = 2; i <= sqr; i++) {
		if(p % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int PrimeSum( int m, int n ) {
	int sum = 0, i = m;
	for(; i <= n; i++) {
		if(prime(i)) sum += i;
	}
	return sum;
}
