#include <cstdio>
#include <cstring>

const int MAXN = 256 + 5;
char str[100][MAXN];
void Reverse(char *s);

int main(int argc, char const *argv[]) {
	int N, minLen = 256, ans = 0;
	scanf("%d", &N);
	getchar();
	for(int i = 0; i < N; i++) {
		fgets(str[i], MAXN, stdin);
		int len = strlen(str[i]);
		if(len < minLen) minLen = len;
		Reverse(str[i]);
	}
	for(int i = 0; i < minLen; i++) {
		char c = str[0][i];
		bool same = true;
		for(int j = 1; j < N; j++) {
			if(c != str[j][i]) {
				same = false;
				break;
			}
		}
		if(same) {
			ans++;
		} else {
			break;
		}
	}
	if(ans > 1) {
		for(int i = ans - 1; i >= 0; i--) {
			putchar(str[0][i]);
		}
	} else {
		puts("nai");
	}
	return 0;
}

void Reverse(char *s) {
	char temp;
	int len = strlen(s);
	for(int i = 0; i < len / 2; i++) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
