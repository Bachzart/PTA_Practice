#include <stdio.h>

int main(int argc, char const *argv[])
{
	int speed;
	scanf("%d", &speed);
	// speed = 40;
	if(speed > 60){
		printf("Speed: %d - Speeding\n", speed);
	}else{
		printf("Speed: %d - OK\n", speed);
	}
	return 0;
}