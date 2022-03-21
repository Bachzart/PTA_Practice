#include <cstdio>

int main() {
	int hour, minute, times;
	scanf("%d:%d", &hour, &minute);
	bool flag = false;
	if(hour >= 12) {
		times = hour - 12 + (minute ? 1 : 0);
		for(int i = 0; i < times; i++) {
			printf("Dang");
			flag = true;
		}
	} 
	if(!flag) printf("Only %02d:%02d.  Too early to Dang.", hour, minute);
	return 0;
}
