#include <cstdio>
const int MAXN = 10000 + 5;
char PATest[10] = "PATest";

int main(int argc, char const *argv[]) {
	char str[MAXN];
	fgets(str, MAXN, stdin);
	char *p = str;
	int times[128] = {0};
	while(*p != '\0') {
		times[*p]++;
		p++;
	}
	while(times['P'] || times['A'] || times['T'] || times['e'] || 
		times['s'] || times['t']) {
		for(p = PATest; *p != '\0'; p++) {
			if(times[*p]) {
				putchar(*p);
				times[*p]--;
			}
		}
	}
	return 0;
}
