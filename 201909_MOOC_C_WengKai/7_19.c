#include <stdio.h>
#include <stdbool.h>
int daysofmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, }; 
bool isleap(int year) {
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	else return false;
} 
int main() {
	int yy, mm, dd;
	scanf("%d/%d/%d", &yy, &mm, &dd);
	if(isleap(yy)) daysofmonth[2]++;
	int i, days = 0;
	for(i = 1; i < mm; i++) {
		days += daysofmonth[i];
	}
	days += dd;
	printf("%d", days);
	return 0;
}
