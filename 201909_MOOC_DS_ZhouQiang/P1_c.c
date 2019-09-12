#include <stdio.h>
#include <string.h>
char radix[35], num1[105], num2[105], num[105];
int getindex(char ch) {
	int index = 0;
	char *p = radix;
	for(; *p != '\0'; p++) {
		if(*p == ch) index = p - radix;
	}
	return index;
}
int main() {
	scanf("%s %s %s", radix, num1, num2);
	int i, j, len = strlen(radix), len1 = strlen(num1), len2 = strlen(num2);
	i = len1 - 1, j = len2 - 1;
	int index1, index2, sum = 0, carry = 0, count = 0;
	if(len1 >= len2) {
		for(; i >= 0; i--, j--) {
			index1 = getindex(num1[i]);
			if(j >= 0) index2 = getindex(num2[j]);
			else index2 = 0;
			sum = index1 + index2 + carry;
			carry = sum / len;
			num[count++] = radix[sum % len];
		}
		if(carry) num[count++] = radix[carry];
	} else {
		for(; j >= 0; i--, j--) {
			if(i >= 0)index1 = getindex(num1[i]);
			else index1 = 0;
			index2 = getindex(num2[j]);
			sum = index1 + index2 + carry;
			carry = sum / len;
			num[count++] = radix[sum % len];
		}
	}
	for(i = count - 1; i >= 0; i--) {
		printf("%c", num[i]);
	}
	return 0;
}
