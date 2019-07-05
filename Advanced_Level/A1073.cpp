#include <cstdio>
const int MAXN = 10000 + 5;

int main(int argc, char const *argv[]) {
	char Num[MAXN];
	scanf("%s", Num);
	int Epos, exp = 0;
	for(Epos = 1; Num[Epos] != 'E'; Epos++);
	for(int i = Epos + 2; Num[i] != '\0'; i++) {
		exp = exp * 10 + Num[i] - '0';
	}
	if(Num[0] == '-') {
		putchar(Num[0]);
	}
	if(exp == 0) {
		for(int i = 1; Num[i] != 'E'; i++) {
			putchar(Num[i]);
		}
	} else if(Num[Epos + 1] == '-') {
		printf("0.");
		for(int i = exp - 1; i > 0; i--) {
			putchar('0');
		}
		for(int i = 1; Num[i] != 'E'; i++) {
			if(Num[i] == '.') continue;
			putchar(Num[i]);
		}
	} else if(Num[Epos + 1] == '+') {
		for(int i = 1; i < Epos; i++) {
			if(Num[i] == '.') continue;
			putchar(Num[i]);
			if(i == exp + 2 && Epos - 3 != exp) {
				putchar('.');
			}
		}
		for(int i = 0; i < exp - (Epos - 3); i++) {
			putchar('0');
		}
	}
	putchar('\n');
	return 0;
}
