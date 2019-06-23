#include <stdio.h>

int main(int argc, char const *argv[])
{
	float open, high, low, close;
	scanf("%f %f %f %f", &open, &high, &low, &close);
	if(close < open){
		printf("BW-Solid");
	}else if(close == open){
		printf("R-Cross");
	}else{
		printf("R-Hollow");
	}
	if(low < open && low < close && high > open && high > close){
		printf(" with Lower Shadow and Upper Shadow");
	}
	if(high > open && high > close && !(low < open && low < close)){
		printf(" with Upper Shadow");
	}if(low < open && low < close && !(high > open && high > close)){
		printf(" with Lower Shadow");
	}
	printf("\n"); 
	return 0;
}
