#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial ( const int N )
{
	if(N < 0){
		printf("Invalid input\n");
	}else if(N == 0){
		printf("1\n");
	}else{
		int i,j,k,temp,carry,num[3000]={0};
		carry=0,k=1,num[0]=1;
		for(i=2; i<=N; i++)
		{
			for(j=0; j<k; j++)
			{
				temp = num[j]*i + carry;
				num[j] = temp%10;
				carry = temp/10;
			}
			while(carry)
			{
				num[k++] = carry%10;
				carry/=10;
			}
		}
		for(i=k-1; i>0; i--)
		{
			printf("%d", num[i]);
		}
		printf("%d\n", num[i]);
	}
}