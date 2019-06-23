#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x;
	scanf("%d", &x);
	// x = 16;
	float y;
	if(x <= 15){
		y = 4*x/3.0;
	}else{
		y = 2.5*x - 17.5;
	}
	printf("%.2f\n", y);
	return 0;
}