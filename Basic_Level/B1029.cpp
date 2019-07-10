#include <cstdio>
#include <cctype>

void levelup(char *str);

int main(int argc, char const *argv[]) {
	char str1[85], str2[85], Result[30];
	scanf("%s %s", str1, str2);
	levelup(str1);
	levelup(str2);
	int count = 0;
	for(int i = 0; str1[i] != '\0'; i++) {
		char temp = str1[i];
		bool flag = true;
		for(int j = 0; str2[j] != '\0'; j++) {
			if(temp == str2[j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			int k = 0;
			for(k = 0; k < 30; k++) {
				if(temp == Result[k]) {
					break;
				}
			}
			if(k == 30) {
				Result[count++] = temp;
			}
		}
	}
	Result[count] = '\0';
	puts(Result);
	return 0;
}

void levelup(char *str) {
	char *p = str;
	while(*p != '\0') {
		if(islower(*p)) {
			*p = toupper(*p);
		}
		p++;
	}
}
