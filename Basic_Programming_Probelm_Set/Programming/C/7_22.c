#include <stdio.h>

int main(int argc, char const *argv[])
{
	int rabbit_dis=0,turtle_dis=0,rabbit_spd=9,turtle_spd=3,T;
	// scanf("%d", &T);
	T=30;
	int i,rabbit_on=1,break_times=0;
	for(i=0; i<T; i++)
	{
		if(i%10 == 0){
			if(rabbit_dis > turtle_dis && break_times == 0){
				break_times=30;
				rabbit_on=-1;
			}else{
				rabbit_on=1;
			}
		}
		if(rabbit_on && break_times==0){
			rabbit_dis+=rabbit_spd;
		}
		turtle_dis+=turtle_spd;
		if(break_times){
			break_times--;
		}
	}
	if(turtle_dis > rabbit_dis){
		printf("@_@ %d\n", turtle_dis);
	}else if(turtle_dis == rabbit_dis){
		printf("-_- %d\n", turtle_dis);
	}else{
		printf("^_^ %d\n", rabbit_dis);
	}
	return 0;
}