#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) ){
            cnt++;
			}
    }
    printf("cnt = %d\n", cnt);
    return 0;
}
int IsTheNumber ( const int N )
{
    int ret=0,digit[11]={0};
    if( ((int)sqrt(N)) * ((int)sqrt(N) ) == N){
        int i,j,temp=N;
        for(i=0; temp; temp/=10, i++)
        {
            digit[temp%10]++;
        }
        for(j=0; j<10; j++){
            if(digit[j] >= 2){
            	ret=1;
            	break;
			}
        }
    }
    return ret;
}
