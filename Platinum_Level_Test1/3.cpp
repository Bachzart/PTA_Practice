#include <stdio.h>

int different_year(int year, int x);

int main(int argc, char const *argv[]) {
	int i, birth_year, x, age = 0;
	scanf("%d %d", &birth_year, &x);
	for(i = birth_year; ; i++, age++) {
		if(different_year(i, x)) {
			printf("%d %04d\n", age, i);
			break;
		}
	}
	return 0;
}

int different_year(int year, int x) {
	int i, j, judge[4] = {0}, diff_count = 4, flag, ret;
	if(year / 10 == 0) {
		judge[3] = year;
	} else if (year / 100 == 0) {
		judge[3] = year % 10;
		judge[2] = year / 10;
	} else if (year / 1000 == 0) {
		judge[3] = year % 10;
		judge[2] = year / 10 % 10;
		judge[1] = year / 100;
	} else {
		judge[3] = year % 10;
		judge[2] = year / 10 % 10;
		judge[1] = year / 100 % 10;
		judge[0] = year / 1000;
	}
	for(i = 0; i < 3; i++) {
		flag = 0;
		for(j = i + 1; j < 4; j++) {
			if(judge[j] == judge[i]) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			diff_count--;
		}
	}
	if(diff_count == x) {
		ret = 1;
	} else {
		ret = 0;
	}
	return ret;
}
