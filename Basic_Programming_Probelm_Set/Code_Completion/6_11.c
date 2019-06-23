#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    for ( i=0; i<N; i++ )
        printf("%.2f ", A[i]);
    return 0;
}

ElementType Median( ElementType A[], int N )
{
	int i,j;
	ElementType temp;
	/* method 1: bubble sort, but Time Limit Exceeded
	for(i=0; i<N; i++)
	{
		for(j=0; j<N-i-1; j++)
		{
			if(A[j] > A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	*/
	/* method 2: insert sort, but also Time Limit Exceeded
	for(i=0; i<N; i++)
	{
		for(j=i; j>0 && A[j]<A[j-1]; j--)
		{
			temp = A[j];
			A[j] = A[j-1];
			A[j-1] = temp;
		}
	}
	*/
	/* method 3: shell sort*/
	int d;
	for(d=N/2; d>0; d/=2)
	{
		for(i=d; i<N; i++)
		{
			temp=A[i];
			for(j=i; j>=d; j-=d)
			{
				if(temp < A[j-d]){
					A[j] = A[j-d];
				}else break;
			}
			A[j]=temp;
		}
	}
	return A[N/2]; 
}
