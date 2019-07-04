#include <stdio.h>
#define MAXN 1005

int main(int argc, char const *argv[]) {
	char num[MAXN];
	int i, digit[10]={0};
	scanf("%s", num);
	char *p;
	p = num;
	while(*p) {
		digit[*p - '0']++;
		p++;
	}
	for(i=0; i<10; i++) {
		if(digit[i] != 0) printf("%d:%d\n", i, digit[i]);
	}
	return 0;
}
