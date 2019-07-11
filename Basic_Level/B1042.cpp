#include <cstdio>
#include <cctype>

const int MAXN = 1000 + 5;
int main(int argc, char const *argv[]) {
	char str[MAXN];
	fgets(str, MAXN, stdin);
	int times[27] = {0}, maxtimes = -1;
	for(int i = 0; str[i] != '\0'; i++) {
		char c1 = str[i];
		if(isalpha(c1)) {
			if(isupper(c1)) c1 = tolower(c1);
			times[c1 - 'a']++;
			if(times[c1 - 'a'] > maxtimes) {
				maxtimes = times[c1 - 'a'];
			}
		}
	}
	for(int i = 0; i < 27; i++) {
		if(maxtimes == times[i]) {
			printf("%c %d\n", i + 'a', times[i]);
			break;
		}
	}
	return 0;
}
