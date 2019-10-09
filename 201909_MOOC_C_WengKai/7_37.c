/* method 1: use long long int */
#include <stdio.h>

int main() {
	long long n, temp, mask = 1;
	scanf("%lld", &n);
	temp = n;
	while(temp > 9) {
		mask *= 10;
		temp /= 10;
	}
	do{
		printf("%d ", n / mask);
		n %= mask;
		mask /= 10;
	} while(mask);
	return 0;
}



/* method 2: use string

#include <stdio.h>

int main() {
	char *p, str[30];
	scanf("%s", str);
	p = str;
	while(*p != '\0') printf("%c ", *p++);
	return 0;
} 

*/
