#include <stdio.h>
#include <string.h>
int main() {
	int n;
	scanf("%d", &n);
	char str1[85], str2[85];
	scanf("%s", str1);
	--n;
	while(n--) {
		scanf("%s", str2);
		if(strlen(str1) < strlen(str2)) {
			strcpy(str1, str2);
		}
	}
	printf("The longest is: %s", str1);
	return 0;
} 
