#include <stdio.h>
#define maxn 100002
int main(int argc, char const *argv[])
{
	/* method 1: use the array do analog computation
	int A,N,sum[maxn],num[maxn];
	// scanf("%d %d", &A, &N);
	A=1, N=3;
	if(N == 0){
		printf("0\n");
	}else if(N == 1){
		printf("%d\n", A);
	}else{
		int i,j,temp,len,flag=0,carry=0;
		for(i=1; i<=N; i++)
		{
			num[i]=A;
		}
		while(N)
		{
			carry=0;
			for(i=1; i<=N-1; i++)
			{
				sum[i]=A;
			}
			for(i=1; i<=N-1; i++)
			{
				temp = num[i] + sum[i];
				num[i] = (temp + carry)%10;
				carry = (temp + carry)/10;
			}
			for(j=i; j<=N; j++)
			{
				temp = num[i] + sum[i];
				num[i] = (temp + carry)%10;
				carry = (temp + carry)/10;
			}
			while(carry)
			{
				num[j++] = carry%10;
				carry/=10;
				len = j;
				flag = 1;
			}
			for(i=1; i<=N-1; i++)
			{
				sum[i]=0;
			}
			N--;
			if(N == 1) break;
		}
		if(flag){
			for(i=len; i>1; i--){
				printf("%d", num[i]);
			}
			printf("%d\n", num[i]);
		}else{
			for(i=j; i>1; i--){
				printf("%d", num[i]);
			}
			printf("%d\n", num[i]);
		}
	}
	return 0;
	*/
	/* method 2: use the '%' */
	int num[maxn]={0},i,j,carry,flag,A,N;
	scanf("%d%d", &A, &N);
	// A=9, N=4;
	if(N == 0) printf("0\n");
	else if(N == 1) printf("%d\n", A);
	else{
		carry=0, flag=0;
		for(i=0; i<N; i++)
		{
			num[i] = (A*(N-i) + carry)%10;
			carry = (A*(N-i) + carry)/10;
		}
		while(carry)
		{
			num[i++] = carry%10;
			carry = carry/10;
			flag = 1;
		}
		if(flag == 1){
			for(i=N; i>0; i--)
			{
				printf("%d", num[i]);
			}
			printf("%d\n", num[i]);
		}else{
			for(i=N-1; i>0; i--)
			{
				printf("%d", num[i]);
			}
			printf("%d\n", num[i]);
		}
	}
	
}