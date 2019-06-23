#include <stdio.h>

double factorial(double n);
int denominator(double n);

int main(int argc, char const *argv[])
{
	double Pi=0, each_item=0.0, threshold, i=0.0;
	scanf("%lf", &threshold);
//	threshold = 0.01;
	do{
//		printf("i=%.2lf, each_item=%lf, factorial(i)=%..2lf\n", i, each_item, factorial(i));
//		printf("denominator(i)=%d, each_item=%.2lf\n", denominator(i), each_item);
		each_item = factorial(i)/denominator(i);
		Pi+=each_item;
		i++;
	}while(each_item > threshold);
	printf("%.6lf\n", Pi*2.0);
	return 0;
}

double factorial(double n)
{
	double i,ret = 1.0;
	if(n == 0) return ret;
	else{
		for(i=1.0; i<=n; i++)
		{
			ret*=i;
		}
	}
	return ret;
}

int denominator(double n)
{
	int i, ret = 1;
	for(i=1; i<=2*n+1; i+=2)
	{
		ret*=i;
	}
	return ret;
}
