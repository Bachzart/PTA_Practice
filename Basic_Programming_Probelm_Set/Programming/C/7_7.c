#include <stdio.h>

int main(int argc, char const *argv[])
{
	int hours, minutes;
	// scanf("%d:%d", &hours, &minutes);
	hours = 12; minutes = 00;
	if(hours > 12){
		printf("%d:%d PM\n", hours-12, minutes);
	}else if(hours == 12){
		printf("%d:%d PM\n", hours, minutes);
	}else{
		printf("%d:%d AM\n", hours, minutes);
	}
	return 0;
}