#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	int num, sum=0;
	while((c=getchar()) != '\n')
	{
		if('0' <= c && c <= '9'){
			num = c - '0';
			sum+=num;
		}else continue;
	}
	/* method 1: 
	int digit, temp=sum, mask=1;
	while(temp > 9)
	{
		temp/=10;
		mask*=10;
	}
	temp=sum;
	do{
		digit=temp/mask;
		temp%=mask;
		mask/=10;
		switch(digit){
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
		if(mask == 0) printf("\n");
		else printf(" ");
	}while(mask > 0);
	*/ 
	/*method 2:*/
	char num2chinese[][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int unit, tens, hundred;
	unit = sum%10;
	tens = sum/10%10;
	hundred=sum/100;
	if(sum > 100){
		printf("%s %s %s\n", num2chinese[hundred], num2chinese[tens], num2chinese[unit]);
	}else if(10 < sum && sum < 100){
		printf("%s %s\n", num2chinese[tens], num2chinese[unit]);
	}else{
		printf("%s\n", num2chinese[unit]);
	}
	return 0;
}
