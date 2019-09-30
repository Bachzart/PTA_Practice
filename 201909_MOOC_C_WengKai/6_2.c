#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

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

void Goldbach( int n ) {
	int i = 2;
	while(1) {
		if(prime(i) && prime(n - i)) break;
		i++;
	}
	printf("%d=%d+%d", n, i, n - i);
}
