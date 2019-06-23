#include <stdio.h>
#define new 0
#define old 1

int main(int argc, char const *argv[])
{
	int years, times, qual_flag;
	scanf("%d %d", &years, &times);
	// years = 3; times = 50;
	float weekly_wage = 0.0;
	if(years >= 5){
		qual_flag = old;
	}else{
		qual_flag = new;
	}
	if(qual_flag){
		if(times > 40){
			weekly_wage = 50*40 + (times - 40)*1.5*50;
		}else{
			weekly_wage = 50*times;
		}
	}else{
		if(times > 40){
			weekly_wage = 30*40 + (times - 40)*1.5*30;
		}else{
			weekly_wage = 30*times;
		}
	}
	printf("%.2f\n", weekly_wage
		);
	return 0;
}