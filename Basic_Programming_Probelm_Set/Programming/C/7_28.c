#include <stdio.h>
#define maxn 1005
int josephus_recursion(int n, int m);
int main(int argc, char const *argv[])
{
	/* method 1: use backtracking
	int N;
	scanf("%d", &N);
	// N=11;
	int i,monkey_array[maxn]={0};
	for(i=1; i<=N; i++){
		monkey_array[i]=i;
	}
	int j,k,temp;
	for(i=N; i>=1; i--)
	{
		for(j=1; j<=3; j++){
			temp=monkey_array[1];
			for(k=1; k<=i; k++){
				monkey_array[k]=monkey_array[k+1];
			}
			monkey_array[i]=temp;
		}
	}
	printf("%d\n", monkey_array[1]);
	*/
	/* method 2: use recursion
	int N;
	N=11;
	if(!N) return 0;
	int result = josephus_recursion(N,3);
	printf("%d\n", result+1);
	*/
	/* method 3: use iteration*/
	int i,N,result=0;
	scanf("%d", &N);
	for(i=2; i<=N; i++)
	{
		result=(result + 3)%i;
	}
	printf("%d\n", result+1);
	return 0;
}
int josephus_recursion(int n, int m)
{
	if(n == 1) return 0;
	else return (josephus_recursion(n-1, m)+m)%n;
}
