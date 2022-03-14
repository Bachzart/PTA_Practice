#include <cstdio>
#include <cstring>
#define MAXN 10005

int main(int argc, char const *argv[]) {
	char Num[MAXN];
	int count = 0, expo, len;
	scanf("%[^E]E%d", Num, &expo);
	len = strlen(Num);
	if(Num[0] == '-') putchar(Num[0]);
	if(expo > 0) {
		for(int i = 1; i < len; i++) {
			if(Num[i] == '.') continue;
			putchar(Num[i]);
			if(i == expo + 2 && len - 3 != expo) {
				putchar('.');
			}
		}
		for(int i = 0; i < expo - (len - 3); i++) {
			putchar('0');
		}
	} else if(expo == 0) {
		puts(Num + 1);
	} else {
		expo = -expo;
		printf("0.");
		for(int i = 0; i < expo - 1; i++) {
			putchar('0');
		}
		putchar(Num[1]);
		for(int i = 3; i < len; i++) {
			putchar(Num[i]);
		}
	}
	putchar('\n');
	return 0;
}
