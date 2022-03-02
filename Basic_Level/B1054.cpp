#include <cstdio>
#include <cstring>
#include <cmath>
char str[100];
double num;
bool getnum(char *str) {
	num = 0.0;
	bool flag = false;
	int i = 0, dec = 0, pnum = 0;
	if(str[i] == '-') {
		for(i++; str[i] != '\0'; i++) {
			if(flag) dec++;
			if(str[i] == '.') {
				pnum++;
				flag = true;
			} else if(pnum > 1 || '9' < str[i] || str[i] < '0' || dec > 2) return false;
			if('0' <= str[i] && str[i] <= '9') num = num * 10 + str[i] - '0';
		}
		num = num / pow(10, dec) * -1;
	} else {
		for(; str[i] != '\0'; i++) {
			if(flag) dec++;
			if(str[i] == '.') {
				pnum++;
				flag = true;
			} else if(pnum > 1 || '9' < str[i] || str[i] < '0' || dec > 2) return false;
			if('0' <= str[i] && str[i] <= '9') num = num * 10 + str[i] - '0';
		}
		num = num / pow(10, dec);
	}
	if(-1000.0 <= num && num <= 1000.0) return true;
	else return false;
}

int main() {
	int n, valid = 0;
	double sum = 0.0;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		if(getnum(str)) {
			sum += num;
			valid++;
		} else {
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if(valid > 1) printf("The average of %d numbers is %.2lf\n", valid, sum / valid);
	else if(valid == 1) printf("The average of %d number is %.2lf\n", valid, sum / valid);
	else printf("The average of 0 numbers is Undefined\n");
	return 0;
} 

/*
in:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
out:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

in:
2
aaa -9999
out:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

in:
1
1000
out:
The average of 2 number is 1000.00
*/