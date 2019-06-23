#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N,K;
	scanf("%d %d", &N, &K);
	// N=6, K=2;
	int array[105];
	// int array[105]={2, 3, 5, 1, 6, 4, 0};
	int i,j;
	for(i=0; i<N; i++)
	{
		scanf("%d", &array[i]);
	}
	for(i=0; i<K; i++)
	{
		int temp=0;
		for(j=0; j<N-i-1; j++)
		{
			if(array[j] > array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}

	for(i=0; i<N; i++)
	{
		if(i == N-1) printf("%d\n", array[i]);
		else printf("%d ", array[i]);
	}
	return 0;
}