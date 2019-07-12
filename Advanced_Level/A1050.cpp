#include <cstdio>
const int MAXN = 10000 + 5;

int main(int argc, char const *argv[]) {
	char str1[MAXN], str2[MAXN];
	fgets(str1, MAXN, stdin);
	fgets(str2, MAXN, stdin);
	int times[128] = {0};
	char *p = str1;
	while(*p != '\0') {
		times[*p++]++;
	}
	p = str2;
	while(*p != '\0') {
		times[*p++] = 0;
	}
	p = str1;
	while(*p != '\0') {
		if(times[*p]) {
			putchar(*p);
		}
		p++;
	}
	return 0;
} 
