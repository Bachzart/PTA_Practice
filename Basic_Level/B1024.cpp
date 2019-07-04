#include <cstdio>
#include <cstring>
#define MAXN 10005

int Getexpon(char *s, int Epos);

int main(int argc, char const *argv[]) {
	char Num[MAXN];
	scanf("%s", Num);
	int count = 0, expo, Epos = 0, len = strlen(Num);
	for(; Num[Epos] != 'E'; Epos++);
	if(Num[0] == '-') putchar(Num[0]);
	expo = Getexpon(Num, Epos);
	if(expo > 0) {
		for(int i = 1; i < Epos; i++) {
			if(Num[i] == '.') continue;
			putchar(Num[i]);
			if(i == expo + 2 && Epos - 3 != expo) {
				putchar('.');
			}
		}
		for(int i = 0; i < expo - (Epos - 3); i++) {
			putchar('0');
		}
	} else if(expo == 0) {
		Num[Epos] = '\0';
		puts(Num + 1);
	} else {
		expo = -expo;
		printf("0.");
		for(int i = 0; i < expo - 1; i++) {
			putchar('0');
		}
		putchar(Num[1]);
		for(int i = 3; i < Epos; i++) {
			putchar(Num[i]);
		}
	}
	putchar('\n');
	return 0;
}

int Getexpon(char *s, int Epos) {
	int ret = 0, flag = 1, i = Epos + 1;
	if(s[i] == '-') {
		flag = -1;
	}
	i++;
	for(; s[i] != '\0'; i++) {
		ret = ret * 10 + s[i] - '0';
	}
	return ret * flag;
}
