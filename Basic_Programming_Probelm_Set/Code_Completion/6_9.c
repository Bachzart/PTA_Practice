#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D )
{
	int times=0,n;
	if(N < 0) n = -N;
	else{
		n=N;
		if(n == 0 && D == 0){
			return 1;
		}
	}
	int mask=1,temp=n;
	do{
		temp/=10;
		mask*=10;
	}while(temp > 9);
	temp = n;
	printf("temp=%d, mask=%d\n", temp, mask);
	int digit;
	do{
		digit = temp/mask;
		printf("%d\n", digit);
		temp%=mask;
		mask/=10;
		printf("mask=%d, temp=%d\n", mask, temp);
		if(digit == D) times++;
	}while(mask > 0 && temp != 0);
	return times;
}
